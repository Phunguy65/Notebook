#ifndef SINGLE_LINKED_LISTITERATOR_HPP
#define SINGLE_LINKED_LISTITERATOR_HPP 1
#include "SingleLinkedListNode.hpp"
namespace DataStructuresAndAlgorithms
{
namespace LinkedList
{
template <typename T> struct SingleLinkedListIterator
{
    SingleLinkedListNodeBase* NodeBase;

    SingleLinkedListIterator() noexcept : NodeBase()
    {
    }

    explicit SingleLinkedListIterator(SingleLinkedListNodeBase* nodeBase) noexcept : NodeBase(nodeBase)
    {
    }

    // SingleLinkedListIterator(const SingleLinkedListIterator& iter) noexcept : _nodeBase(iter._nodeBase)
    // {
    // }

    T& operator*() const noexcept
    {
        return *static_cast<SingleLinkedListNode<T>*>(this->NodeBase)->GetValuePtr();
    }

    T* operator->() const noexcept
    {
        return static_cast<SingleLinkedListNode<T>>(this->NodeBase).GetValuePtr();
    }

    SingleLinkedListIterator<T>& operator++() noexcept
    {
        this->NodeBase = this->NodeBase->PointerNext;
        return *this;
    }

    SingleLinkedListIterator<T> operator++(int) noexcept
    {
        SingleLinkedListIterator<T> temp(*this);
        this->NodeBase = this->NodeBase->PointerNext;
        return temp;
    }

    friend bool operator!=(const SingleLinkedListIterator<T>& lhs, const SingleLinkedListIterator<T>& rhs) noexcept
    {
        return lhs.NodeBase != rhs.NodeBase;
    }

    SingleLinkedListIterator<T> Next() const noexcept
    {
        if (this->NodeBase)
        {
            return SingleLinkedListIterator(this->NodeBase->PointerNext);
        }
        else
        {
            return SingleLinkedListIterator(nullptr);
        }
    }
};

template <typename T> struct SingleLinkedListConstIterator
{
    typedef SingleLinkedListConstIterator<T> SelfAlias;
    typedef const SingleLinkedListNode<T> NodeAlias;
    typedef SingleLinkedListIterator<T> IteratorAlias;

    typedef T ValueTypeAlias;
    typedef const T* PointerAlias;
    typedef const T& ReferenceAlias;

    const SingleLinkedListNodeBase* NodeBase;

    SingleLinkedListConstIterator() noexcept : NodeBase()
    {
    }

    explicit SingleLinkedListConstIterator(const SingleLinkedListNodeBase* nodeBase) noexcept : NodeBase(nodeBase)
    {
    }

    SingleLinkedListConstIterator(const IteratorAlias& iter) noexcept : NodeBase(iter.NodeBase)
    {
    }

    ReferenceAlias operator*() const noexcept
    {
        return *static_cast<NodeAlias*>(this->NodeBase)->GetValuePtr();
    }

    PointerAlias operator->() const noexcept
    {
        return static_cast<NodeAlias*>(this->NodeBase)->GetValuePtr();
    }

    SelfAlias& operator++() noexcept
    {
        this->NodeBase = this->NodeBase->PointerNext;
        return *this;
    }

    SelfAlias operator++(int) noexcept
    {
        SelfAlias temp(*this);
        this->NodeBase = this->NodeBase->PointerNext;
        return temp;
    }

    friend bool operator!=(const SelfAlias& lhs, const SelfAlias& rhs) noexcept
    {
        return lhs.NodeBase != rhs.NodeBase;
    }

    SelfAlias Next() const noexcept
    {
        if (this->NodeBase)
        {
            return SingleLinkedListConstIterator(this->NodeBase->PointerNext);
        }
        else
        {
            return SingleLinkedListConstIterator(nullptr);
        }
    }
};
} // namespace LinkedList
} // namespace DataStructuresAndAlgorithms
#endif // !SINGLELINKEDLISTITERATOR_HPP