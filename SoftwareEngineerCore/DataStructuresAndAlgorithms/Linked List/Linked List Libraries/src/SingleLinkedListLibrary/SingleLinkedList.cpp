#ifndef SINGLE_LINKED_LIST_CPP
#define SINGLE_LINKED_LIST_CPP 1
#include "../../include/SingleLinkedListLibrary/SingleLinkedList.hpp"
#include <memory>
#include <utility>
using namespace DataStructuresAndAlgorithms::LinkedList;

template <typename T, typename Alloc>
SingleLinkedListBase<T, Alloc>::SingleLinkedListBase(const SingleLinkedListBase& sll,
                                                     const NodeAllocatorTypeAlias& init)
    : LinkedListCore(init)
{
    this->LinkedListCore.NodeHead.PointerNext = nullptr;
    SingleLinkedListNodeBase* to = &this->LinkedListCore.NodeHead;
    NodeAlias* curr = static_cast<NodeAlias*>(sll.LinkedListCore.NodeHead.PointerNext);
    while (curr)
    {
        to->PointerNext = this->CreateNodeInternal(curr->GetValue());
        to = to->PointerNext;
        curr = static_cast<NodeAlias*>(curr->PointerNext);
    }
}

template <typename T, typename Alloc>
template <typename... Args>
SingleLinkedListNodeBase* SingleLinkedListBase<T, Alloc>::InsertAfterInternal(ConstIteratorAlias pos, Args&&... args)
{
    SingleLinkedListNodeBase* to = const_cast<SingleLinkedListNodeBase*>(pos.NodeBase);
    NodeAlias* thing = this->CreateNodeInternal(std::forward<Args>(args)...);
    thing->PointerNext = to->PointerNext;
    to->PointerNext = thing;
    return to->PointerNext;
}
template <typename T, typename Alloc>
SingleLinkedListNodeBase* SingleLinkedListBase<T, Alloc>::EraseAfterInternal(
    DataStructuresAndAlgorithms::LinkedList::SingleLinkedListNodeBase* pos)
{
    NodeAlias* curr = static_cast<NodeAlias*>(pos->PointerNext);
    pos->PointerNext = curr->PointerNext;
    GetNodeAllocator().Destroy(curr->GetValuePtr());
    PutNode(curr);
    return pos->PointerNext;
}
template <typename T, typename Alloc>
SingleLinkedListNodeBase* SingleLinkedListBase<T, Alloc>::EraseAfterInternal(
    DataStructuresAndAlgorithms::LinkedList::SingleLinkedListNodeBase* pos,
    DataStructuresAndAlgorithms::LinkedList::SingleLinkedListNodeBase* last)
{
    NodeAlias* curr = static_cast<NodeAlias*>(pos->PointerNext);
    while (curr != last)
    {
        NodeAlias* temp = curr;
        curr = static_cast<NodeAlias*>(pos->PointerNext);
        GetNodeAllocator().Destroy(temp->GetValuePtr());
        PutNode(temp);
    }
    pos->PointerNext = curr;
    return pos->PointerNext;
}

template <typename T, typename Alloc>
template <typename InputIterator>
void SingleLinkedList<T, Alloc>::RangeInitializeInternal(InputIterator first, InputIterator last)
{
    NodeBaseAlias* temp = &this->LinkedListCore.NodeHead;
    while (first != last)
    {
        temp->PointerNext = this->CreateNodeInternal(*first);
        temp = temp->PointerNext;
        ++first;
    }
}

template <typename T, typename Alloc> void SingleLinkedList<T, Alloc>::DefaultInitializeInternal(_SizeType size)
{
    NodeBaseAlias* temp = &this->LinkedListCore.NodeHead;
    while (size)
    {
        temp->PointerNext = this->CreateNodeInternal();
        temp = temp->PointerNext;
        --size;
    }
}

template <typename T, typename Alloc>
void SingleLinkedList<T, Alloc>::FillInitializeInternal(_SizeType size, const T& value)
{
    NodeBaseAlias* temp = &this->LinkedListCore.NodeHead;
    while (size)
    {
        temp->PointerNext = this->CreateNodeInternal(value);
        temp = temp->PointerNext;
    }
}

template <typename T, typename Alloc>
SingleLinkedList<T, Alloc>& SingleLinkedList<T, Alloc>::operator=(const SingleLinkedList& list)
{
    if (this != &list)
    {
        // Clear();
        IteratorAlias oldIteratorPrev = this->GetBeginFromHead();
        IteratorAlias oldIteratorCurr = this->GetBegin();
        IteratorAlias oldIteratorLast = this->GetEnd();

        ConstIteratorAlias newIteratorFirst = list.GetConstBegin();
        ConstIteratorAlias newIteratorLast = list.GetConstEnd();

        while (oldIteratorCurr != oldIteratorLast && newIteratorFirst != newIteratorLast)
        {
            *oldIteratorCurr = *newIteratorFirst;
            ++oldIteratorCurr;
            ++newIteratorFirst;
            ++oldIteratorPrev;
        }
        if (newIteratorFirst == newIteratorLast)
        {
            this->EraseAfter(oldIteratorPrev, oldIteratorLast);
        }
        else
        {
            this->InsertAfter(oldIteratorPrev, newIteratorFirst, newIteratorLast);
        }
    }
    return *this;
}

template <typename T, typename Alloc>
void SingleLinkedList<T, Alloc>::DefaultInsertAfterInternal(ConstIteratorAlias pos, _SizeType size)
{
    ConstIteratorAlias savePos = pos;
    try
    {
        for (; size; --size)
        {
            pos = this->EmplaceAfter(pos);
        }
    }
    catch (...)
    {
        this->EraseAfter(savePos, pos);
        throw;
    }
}

template <typename T, typename Alloc> void SingleLinkedList<T, Alloc>::Resize(_SizeType size)
{
    IteratorAlias curr = this->GetBeginFromHead();

    _SizeType length = 0;

    while (curr.Next() != this->GetEnd() && length < size)
    {
        ++length;
        ++curr;
    }

    if (length == size)
    {
        this->EraseAfter(curr, this->GetEnd());
    }
    else
    {
        this->DefaultInsertAfter(curr, size - length);
    }
}

template <typename T, typename Alloc>
void SingleLinkedList<T, Alloc>::Resize(_SizeType size, const ValueTypeAlias& value)
{
    IteratorAlias curr = this->GetBeginFromHead();

    _SizeType length = 0;

    while (curr.Next() != this->GetEnd() && length < size)
    {
        ++length;
        ++curr;
    }

    if (length == size)
    {
        this->EraseAfter(curr, this->GetEnd());
    }
    else
    {
        this->InsertAfter(curr, size - length, value);
    }
}

template <typename T, typename Alloc>
typename SingleLinkedList<T, Alloc>::IteratorAlias SingleLinkedList<T, Alloc>::SpliceAfterInternal(
    ConstIteratorAlias pos, SingleLinkedList&& sll)
{
    NodeBaseAlias* temp = const_cast<NodeBaseAlias*>(pos.NodeBase);
    IteratorAlias before = sll.GetBeginFromHead();
    return IteratorAlias(temp->TransferAfter(before.NodeBase));
}

template <typename T, typename Alloc>
void SingleLinkedList<T, Alloc>::SpliceAfter(ConstIteratorAlias pos, SingleLinkedList&& sll, ConstIteratorAlias first,
                                             ConstIteratorAlias last)
{
    NodeBaseAlias* temp = const_cast<NodeBaseAlias*>(pos.NodeBase);
    temp->TransferAfter(const_cast<NodeBaseAlias*>(first.NodeBase), const_cast<NodeBaseAlias*>(last.NodeBase));
}

template <typename T, typename Alloc>
typename SingleLinkedList<T, Alloc>::IteratorAlias SingleLinkedList<T, Alloc>::InsertAfter(ConstIteratorAlias pos,
                                                                                           _SizeType size,
                                                                                           const ValueTypeAlias& value)
{
    if (size)
    {
        SingleLinkedList temp(size, value, this->GetNodeAllocator());
        return this->SpliceAfterInternal(pos, std::move(temp));
    }
    else
    {
        return IteratorAlias(const_cast<NodeBaseAlias*>(pos.NodeBase));
    }
}

template <typename T, typename Alloc>
template <typename InputIterator>
typename SingleLinkedList<T, Alloc>::IteratorAlias SingleLinkedList<T, Alloc>::InsertAfter(ConstIteratorAlias pos,
                                                                                           InputIterator first,
                                                                                           InputIterator last)
{
    SingleLinkedList temp(first, last, this->GetNodeAllocator());
    if (!temp.IsEmpty())
    {
        return this->SpliceAfterInternal(pos, std::move(temp));
    }
    else
    {
        return IteratorAlias(const_cast<NodeBaseAlias*>(pos.NodeBase));
    }
}

template <typename T, typename Alloc> void SingleLinkedList<T, Alloc>::Remove(const ValueTypeAlias& value)
{
    NodeAlias* curr = static_cast<NodeAlias*>(this->LinkedListCore.NodeHead.PointerNext);
    NodeAlias* extra = nullptr;

    while (NodeAlias* temp = static_cast<NodeAlias*>(curr->PointerNext))
    {
        if (temp->GetValue() == value)
        {
            if (std::addressof(temp->GetValue()) != std::addressof(value))
            {
                this->EraseAfterInternal(curr);
                continue;
            }
            else
            {
                extra = curr;
            }
        }
        curr = static_cast<NodeAlias*>(curr->PointerNext);
    }
    if (extra)
    {
        this->EraseAfterInternal(extra);
    }
}

template <typename T, typename Alloc>
template <typename Predicate>
void SingleLinkedList<T, Alloc>::RemoveIf(Predicate pred)
{
    NodeAlias* curr = static_cast<NodeAlias*>(&this->LinkedListCore.NodeHead.PointerNext);

    while (NodeAlias* temp = static_cast<NodeAlias*>(curr->PointerNext))
    {
        if (pred(temp->GetValue()))
        {
            this->EraseAfterInternal(curr);
        }
        else
        {
            curr = static_cast<NodeAlias*>(curr->PointerNext);
        }
    }
}

template <typename T, typename Alloc>
template <typename Compare>
void SingleLinkedList<T, Alloc>::Merge(SingleLinkedList&& sll, Compare compare)
{
    NodeBaseAlias* node = static_cast<NodeBaseAlias*>(&this->LinkedListCore.NodeHead);
    while (node->PointerNext && sll.LinkedListCore.NodeHead.PointerNext)
    {
        if (compare(static_cast<NodeAlias*>(node->PointerNext)->GetValue(),
                    static_cast<NodeAlias*>(sll.LinkedListCore.NodeHead.PointerNext)->GetValue()))
        {
            node =
                node->TransferAfter(&sll.LinkedListCore.NodeHead.PointerNext, sll.LinkedListCore.NodeHead.PointerNext);

            node = node->PointerNext;
        }

        if (sll.LinkedListCore.NodeHead.PointerNext)
        {
            node->PointerNext = sll.LinkedListCore.NodeHead.PointerNext;
            sll.LinkedListCore.NodeHead.PointerNext = nullptr;
        }
    }
}

template <typename T, typename Alloc> template <typename Compare> void SingleLinkedList<T, Alloc>::Sort(Compare compare)
{
    NodeAlias* list = static_cast<NodeAlias*>(this->LinkedListCore.NodeHead.PointerNext);

    if (!list)
    {
        return;
    }

    unsigned long insize = 1;

    while (1)
    {
        NodeAlias* p = list;
        list = nullptr;
        NodeAlias* tail = nullptr;

        unsigned long nmerges = 0;

        while (p)
        {
            ++nmerges;

            NodeAlias* q = p;

            unsigned long psize = 0;

            for (unsigned long i = 0; i < insize; ++i)
            {
                ++psize;
                q = static_cast<NodeAlias*>(q->PointerNext);
                if (!q)
                {
                    break;
                }
            }

            unsigned long qsize = insize;

            while (psize > 0 || ((qsize > 0) && q))
            {
                NodeAlias* e = nullptr;

                if (psize == 0)
                {
                    e = q;
                    q = static_cast<NodeAlias*>(q->PointerNext);
                    --qsize;
                }
                else if (qsize == 0 || !q)
                {
                    e = p;
                    p = static_cast<NodeAlias*>(p->PointerNext);
                    --psize;
                }
                else if (compare(*p->GetValuePtr(), *q->GetValuePtr()))
                {
                    e = p;
                    p = static_cast<NodeAlias*>(p->PointerNext);
                    --psize;
                }
                else
                {
                    e = q;
                    q = static_cast<NodeAlias*>(q->PointerNext);
                    --qsize;
                }

                if (tail)
                {
                    tail->PointerNext = e;
                }
                else
                {
                    list = e;
                }
                tail = e;
            }
            p = q;
        }

        tail->PointerNext = nullptr;

        if (nmerges <= 1)
        {
            this->LinkedListCore.NodeHead.PointerNext = list;
            return;
        }

        insize *= 2;
    }
}

template <typename T, typename Alloc>
bool operator==(const SingleLinkedList<T, Alloc>& lhs, const SingleLinkedList<T, Alloc>& rhs)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        return false;
    }
    auto lhsIter = lhs.GetConstBegin();
    auto rhsIter = rhs.GetConstBegin();
    while (lhsIter != lhs.GetConstEnd() && rhsIter != rhs.GetConstEnd())
    {
        if (*lhsIter != *rhsIter)
        {
            return false;
        }
        ++lhsIter;
        ++rhsIter;
    }
    return true;
}
#endif