#ifndef SINGLE_LINKED_LIST_HPP
#define SINGLE_LINKED_LIST_HPP 1
#include "../Allocator.hpp"
#include "SingleLinkedListIterator.hpp"
#include "SingleLinkedListNode.hpp"
#include <algorithm>
#include <cstddef>
#include <utility>

using namespace MemoryManagement;
namespace DataStructuresAndAlgorithms
{
namespace LinkedList
{
template <typename T, typename Alloc> struct SingleLinkedListBase
{
  protected:
    typedef typename Alloc::template Rebind<SingleLinkedListNode<T>>::other NodeAllocatorTypeAlias;
    typedef typename Alloc::template Rebind<T>::other TpAllocatorTypeAlias;

    struct SingleLinkedListCore : public NodeAllocatorTypeAlias
    {
        SingleLinkedListNodeBase NodeHead;

        SingleLinkedListCore() : NodeAllocatorTypeAlias(), NodeHead()
        {
        }

        SingleLinkedListCore(const NodeAllocatorTypeAlias& init) noexcept : NodeAllocatorTypeAlias(init), NodeHead()
        {
        }

        SingleLinkedListCore(NodeAllocatorTypeAlias&& node) : NodeAllocatorTypeAlias(std::move(node)), NodeHead()
        {
        }
    };

  public:
    SingleLinkedListCore LinkedListCore;

    typedef SingleLinkedListNode<T> NodeAlias;
    typedef SingleLinkedListIterator<T> IteratorAlias;
    typedef SingleLinkedListConstIterator<T> ConstIteratorAlias;
    typedef Alloc AllocatorTypeAlias;

    NodeAllocatorTypeAlias& GetNodeAllocator() noexcept
    {
        return *static_cast<NodeAllocatorTypeAlias*>(&LinkedListCore);
    }

    const NodeAllocatorTypeAlias& GetNodeAllocator() const noexcept
    {
        return *static_cast<const NodeAllocatorTypeAlias*>(&LinkedListCore);
    }

    TpAllocatorTypeAlias GetTAllocator() const noexcept
    {
        return TpAllocatorTypeAlias(GetNodeAllocator());
    }

    AllocatorTypeAlias GetAllocator() const noexcept
    {
        return AllocatorTypeAlias(this->GetNodeAllocator());
    }

    SingleLinkedListBase() : LinkedListCore()
    {
    }

    SingleLinkedListBase(const NodeAllocatorTypeAlias& init) noexcept : LinkedListCore(init)
    {
    }

    SingleLinkedListBase(const SingleLinkedListBase& sll, const NodeAllocatorTypeAlias& init);

    SingleLinkedListBase(SingleLinkedListBase&& sll, const NodeAllocatorTypeAlias& init) noexcept : LinkedListCore(init)
    {
        LinkedListCore.NodeHead.PointerNext = sll.LinkedListCore.NodeHead.PointerNext;
        sll.LinkedListCore.NodeHead.PointerNext = nullptr;
    }

    SingleLinkedListBase(SingleLinkedListBase&& sll) noexcept : LinkedListCore(std::move(sll.GetNodeAllocator()))
    {
        LinkedListCore.NodeHead.PointerNext = sll.LinkedListCore.NodeHead.PointerNext;
        sll.LinkedListCore.NodeHead.PointerNext = nullptr;
    }

    ~SingleLinkedListBase() noexcept
    {
        EraseAfterInternal(&LinkedListCore.NodeHead, nullptr);
    }

  protected:
    template <typename... Args> SingleLinkedListNodeBase* InsertAfterInternal(ConstIteratorAlias pos, Args&&... args);
    SingleLinkedListNodeBase* EraseAfterInternal(SingleLinkedListNodeBase* pos);
    SingleLinkedListNodeBase* EraseAfterInternal(SingleLinkedListNodeBase* pos, SingleLinkedListNodeBase* last);

    NodeAlias* GetNode()
    {
        return GetNodeAllocator().Allocate(1);
    }

    void PutNode(SingleLinkedListNode<T>* node)
    {
        GetNodeAllocator().DeAllocate(node, 1);
    }

    template <typename... Args> NodeAlias* CreateNodeInternal(Args&&... args)
    {
        NodeAlias* node = this->GetNode();
        try
        {
            GetNodeAllocator().Construct(node, std::forward<Args>(args)...);
        }
        catch (...)
        {
            this->PutNode(node);
        }
        return node;
    }
};

template <typename T, typename Alloc = Allocator<T>> class SingleLinkedList : private SingleLinkedListBase<T, Alloc>
{
  private:
    typedef SingleLinkedListBase<T, Alloc> BaseAlias;
    typedef SingleLinkedListNodeBase NodeBaseAlias;
    typedef typename BaseAlias::NodeAlias NodeAlias;
    typedef typename BaseAlias::NodeAllocatorTypeAlias NodeAllocatorTypeAlias;
    typedef typename BaseAlias::TpAllocatorTypeAlias TpAllocatorTypeAlias;

  public:
    typedef T ValueTypeAlias;
    typedef ValueTypeAlias& ReferenceAlias;
    typedef const ValueTypeAlias& ConstReferenceAlias;

    typedef typename BaseAlias::IteratorAlias IteratorAlias;
    typedef typename BaseAlias::ConstIteratorAlias ConstIteratorAlias;
    typedef std::size_t _SizeType;

    typedef typename BaseAlias::AllocatorTypeAlias AllocatorTypeAlias;

    explicit SingleLinkedList(const Alloc& al = Alloc()) noexcept : BaseAlias(NodeAllocatorTypeAlias(al))
    {
    }

    SingleLinkedList(const SingleLinkedList& sll, const Alloc& al) : BaseAlias(sll, NodeAllocatorTypeAlias(al))
    {
    }

    SingleLinkedList(SingleLinkedList&& sll, const Alloc& al) noexcept
        : BaseAlias(std::move(sll), NodeAllocatorTypeAlias(al))
    {
    }

    explicit SingleLinkedList(_SizeType size) : BaseAlias()
    {
        DefaultInitializeInternal(size);
    }

    SingleLinkedList(_SizeType size, const T& value, const Alloc& al = Alloc()) : BaseAlias(NodeAllocatorTypeAlias(al))
    {
        FillInitializeInternal(size, value);
    }

    template <typename InputIterator>
    SingleLinkedList(InputIterator first, InputIterator last, const Alloc& al = Alloc())
        : BaseAlias(NodeAllocatorTypeAlias(al))
    {
        RangeInitializeInternal(first, last);
    }

    SingleLinkedList(const SingleLinkedList& sll) : BaseAlias(sll.GetNodeAllocator())
    {
        RangeInitializeInternal(sll.GetConstBegin(), sll.GetConstEnd());
    }

    SingleLinkedList(SingleLinkedList&& sll) noexcept : BaseAlias(std::move(sll))
    {
    }

    ~SingleLinkedList() noexcept
    {
    }

    SingleLinkedList& operator=(const SingleLinkedList& sll);

    SingleLinkedList& operator=(SingleLinkedList&& sll) noexcept
    {
        this->Clear();
        this->Swap(sll);
        return *this;
    }

    IteratorAlias GetBegin()
    {
        return IteratorAlias(this->LinkedListCore.NodeHead.PointerNext);
    }

    ConstIteratorAlias GetConstBegin() const noexcept
    {
        return ConstIteratorAlias(this->LinkedListCore.NodeHead.PointerNext);
    }

    IteratorAlias GetEnd()
    {
        return IteratorAlias(nullptr);
    }

    ConstIteratorAlias GetConstEnd() const noexcept
    {
        return ConstIteratorAlias(nullptr);
    }

    IteratorAlias GetBeginFromHead()
    {
        return IteratorAlias(&this->LinkedListCore.NodeHead);
    }

    ConstIteratorAlias GetConstBeginFromHead() const noexcept
    {
        return ConstIteratorAlias(&this->LinkedListCore.NodeHead);
    }

    bool IsEmpty() const noexcept
    {
        return this->LinkedListCore.NodeHead._pNext == nullptr;
    }

    _SizeType MaxSize() const noexcept
    {
        return this->GetNodeAllocator().MaxSize();
    }

    ReferenceAlias GetItemFront()
    {
        NodeAlias* front = static_cast<NodeAlias*>(this->LinkedListCore.NodeHead.PointerNext);
        return *front->GetValuePtr();
    }

    ConstReferenceAlias GetItemFront() const
    {
        NodeAlias* front = static_cast<NodeAlias*>(this->LinkedListCore.NodeHead.PointerNext);
        return *front->GetValuePtr();
    }

    void PushFront(const T& value)
    {
        this->InsertAfterInternal(this->GetConstBeginFromHead(), value);
    }

    void PushFront(T&& value)
    {
        this->InsertAfterInternal(this->GetConstBeginFromHead(), std::move(value));
    }

    void PopFront()
    {
        this->EraseAfterInternal(&this->LinkedListCore.NodeHead);
    }

    template <typename... Args> void EmplaceFront(Args&&... args)
    {
        this->InsertAfterInternal(this->GetBeginFromHead(), std::forward<Args>(args)...);
    }

    template <typename... Args> IteratorAlias EmplaceAfter(ConstIteratorAlias pos, Args&&... args)
    {
        return IteratorAlias(this->InsertAfterInternal(pos, std::forward<Args>(args)...));
    }

    template <typename InputIterator> void Assign(InputIterator first, InputIterator last)
    {
        this->Clear();
        InsertAfter(this->GetBeginFromHead(), first, last);
    }

    void Assign(_SizeType size, const T& value)
    {
        this->Clear();
        InsertAfter(this->GetBeginFromHead(), size, value);
    }

    IteratorAlias InsertAfter(ConstIteratorAlias pos, const T& value)
    {
        return IteratorAlias(this->InsertAfterInternal(pos, value));
    }

    IteratorAlias InsertAfter(ConstIteratorAlias pos, T&& value)
    {
        return IteratorAlias(this->InsertAfterInternal(pos, std::move(value)));
    }

    IteratorAlias InsertAfter(ConstIteratorAlias pos, _SizeType size, const T& value);

    template <typename InputIterator>
    IteratorAlias InsertAfter(ConstIteratorAlias pos, InputIterator first, InputIterator last);

    void SpliceAfter(ConstIteratorAlias pos, SingleLinkedList&& sll)
    {
        this->SpliceAfterInternal(pos, std::move(sll));
    }

    void SpliceAfter(ConstIteratorAlias pos, SingleLinkedList&& sll, ConstIteratorAlias i)
    {
        ConstIteratorAlias j = i;
        ++j;

        if (pos == i || pos == j)
        {
            return;
        }

        NodeBaseAlias* temp = const_cast<NodeBaseAlias*>(pos.NodeBase);
        temp->TransferAfter(const_cast<NodeBaseAlias*>(i.NodeBase), const_cast<NodeBaseAlias*>(j.NodeBase));
    }

    void SpliceAfter(ConstIteratorAlias pos, SingleLinkedList&& sll, ConstIteratorAlias first, ConstIteratorAlias last);

    IteratorAlias EraseAfter(ConstIteratorAlias pos)
    {
        return IteratorAlias(this->EraseAfterInternal(const_cast<NodeBaseAlias*>(pos.NodeBase)));
    }

    IteratorAlias EraseAfter(ConstIteratorAlias pos, ConstIteratorAlias last)
    {
        return IteratorAlias(this->EraseAfterInternal(const_cast<NodeBaseAlias*>(pos.NodeBase)),
                             const_cast<NodeBaseAlias*>(last.NodeBase));
    }

    void Resize(_SizeType size);

    void Resize(_SizeType size, const ValueTypeAlias& value);

    void Clear() noexcept
    {
        this->EraseAfterInternal(&this->LinkedListCore.NodeHead, nullptr);
    }

    void Remove(const T& value);

    template <typename Predicate> void RemoveIf(Predicate pred);

    template <typename Compare> void Merge(SingleLinkedList&& sll, Compare comp);

    template <typename Compare> void Merge(SingleLinkedList& sll, Compare comp)
    {
        this->Merge(std::move(sll), comp);
    }

    void Merge(SingleLinkedList&& sll)
    {
        this->Merge(std::move(sll), std::less<T>());
    }

    void Merge(SingleLinkedList& sll)
    {
        this->Merge(std::move(sll), std::less<T>());
    }

    template <typename Compare> void Sort(Compare compare);

    void Sort()
    {
        this->Sort(std::less<T>());
    }

    void Swap(SingleLinkedList& sll) noexcept
    {
        std::swap(this->LinkedListCore.NodeHead._pNext, sll.LinkedListCore.NodeHead._pNext);
    }

    void Reverse() noexcept
    {
        this->LinkedListCore.NodeHead.ReverseAfter();
    }

    AllocatorTypeAlias GetAllocator() const noexcept
    {
        return AllocatorTypeAlias(this->GetNodeAllocator());
    }

  private:
    void FillInitializeInternal(_SizeType size, const T& value);

    void DefaultInitializeInternal(_SizeType size);

    void DefaultInsertAfterInternal(ConstIteratorAlias pos, _SizeType size);

    IteratorAlias SpliceAfterInternal(ConstIteratorAlias pos, SingleLinkedList&& sll);

    template <typename InputIterator> void RangeInitializeInternal(InputIterator first, InputIterator last);
};

template <typename T, typename Alloc>
bool operator==(const SingleLinkedList<T, Alloc>& lhs, const SingleLinkedList<T, Alloc>& rhs);

template <typename T, typename Alloc>
inline bool operator!=(const SingleLinkedList<T, Alloc>& lhs, const SingleLinkedList<T, Alloc>& rhs)
{
    return !(lhs == rhs);
}

} // namespace LinkedList
} // namespace DataStructuresAndAlgorithms

#endif