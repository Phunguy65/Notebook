#include <utility>
#ifndef SINGLE_LINKED_LIST_NODE_HPP
#define SINGLE_LINKED_LIST_NODE_HPP 1
namespace DataStructuresAndAlgorithms
{
namespace LinkedList
{

struct SingleLinkedListNodeBase
{
    SingleLinkedListNodeBase* PointerNext = nullptr;

    SingleLinkedListNodeBase() = default;

    SingleLinkedListNodeBase(SingleLinkedListNodeBase&& nodeBase) noexcept : PointerNext(nodeBase.PointerNext)
    {
    }

    SingleLinkedListNodeBase(const SingleLinkedListNodeBase&) = delete;

    SingleLinkedListNodeBase& operator=(const SingleLinkedListNodeBase&) = delete;

    SingleLinkedListNodeBase& operator=(SingleLinkedListNodeBase&& nodeBase) noexcept
    {
        PointerNext = nodeBase.PointerNext;
        nodeBase.PointerNext = nullptr;
        return *this;
    }

    SingleLinkedListNodeBase* TransferAfter(SingleLinkedListNodeBase* begin, SingleLinkedListNodeBase* end) noexcept
    {
        SingleLinkedListNodeBase* keep = begin->PointerNext;
        if (end)
        {
            begin->PointerNext = end->PointerNext;
            end->PointerNext = PointerNext;
        }
        else
        {
            begin->PointerNext = nullptr;
            PointerNext = keep;
        }
        return end;
    }

    void ReverseAfter() noexcept
    {
        SingleLinkedListNodeBase* tail = this->PointerNext;
        if (!tail)
        {
            return;
        }
        while (SingleLinkedListNodeBase* temp = tail->PointerNext)
        {
            SingleLinkedListNodeBase* keep = this->PointerNext;
            this->PointerNext = temp;
            tail->PointerNext = temp->PointerNext;
            this->PointerNext->PointerNext = keep;
        }
        return;
    }
};

template <typename T> struct SingleLinkedListNode : public SingleLinkedListNodeBase
{
    T data;

    SingleLinkedListNode() = default;

    template <typename... Args>
    SingleLinkedListNode(Args&&... args) : SingleLinkedListNodeBase(), data(std::forward<Args>(args)...)
    {
    }

    T* GetValuePtr()
    {
        return &this->data;
    }

    T const* GetValuePtr() const
    {
        return &this->data;
    }
};
} // namespace LinkedList
} // namespace DataStructuresAndAlgorithms
#endif // LINKEDLISTNODE_HPP