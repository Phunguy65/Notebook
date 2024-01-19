
#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP 1
#include <limits>
#include <memory>
#include <new>
#include <utility>


namespace MemoryManagement
{
template <typename T> class Allocator;

template <> class Allocator<void>
{
  public:
    using value_type = void;
    using pointer = void*;
    using const_pointer = void const*;
    using void_pointer = void*;
    using const_void_pointer = void const*;

    template <typename U> struct Rebind
    {
        typedef Allocator<U> other;
    };
};

template <typename T> class Allocator
{
  public:
    using value_type = T;

    using pointer = value_type*;
    using const_pointer = typename std::pointer_traits<pointer>::template rebind<value_type const>;
    using void_pointer = typename std::pointer_traits<pointer>::template rebind<void>;
    using const_void_pointer = typename std::pointer_traits<pointer>::template rebind<const void>;

    using difference_type = typename std::pointer_traits<pointer>::difference_type;
    using size_type = std::make_unsigned_t<difference_type>;

    template <typename U> struct Rebind
    {
        typedef Allocator<U> other;
    };

    Allocator() noexcept
    {
    } // not required, unless used

    template <typename U> Allocator(Allocator<U> const&) noexcept
    {
    }

    value_type* // Use pointer if pointer is not a value_type*
    Allocate(std::size_t n)
    {
        return static_cast<value_type*>(::operator new(n * sizeof(value_type)));
    }

    void DeAllocate(value_type* pValueType, std::size_t) noexcept // Use pointer if pointer is not a value_type*
    {
        ::operator delete(pValueType);
    }

    value_type* Allocate(std::size_t sizeValueType, const_void_pointer)
    {
        return Allocate(sizeValueType);
    }

    template <typename U, typename... Args> void Construct(U* p, Args&&... args)
    {
        ::new (p) U(std::forward<Args>(args)...);
    }

    template <typename U> void Destroy(U* p) noexcept
    {
        p->~U();
    }

    std::size_t MaxSize() const noexcept
    {
        return std::numeric_limits<size_type>::max() / sizeof(value_type);
    }

    Allocator SelectOnContainerCopyConstruction() const
    {
        return *this;
    }
};

template <typename T, typename U> bool operator==(Allocator<T> const&, Allocator<U> const&) noexcept
{
    return true;
}

template <typename T, typename U> bool operator!=(Allocator<T> const& x, Allocator<U> const& y) noexcept
{
    return !(x == y);
}
}; // namespace MemoryManagement
#endif