#include <utility>
#ifndef SINGLE_LINKED_LIST_CPP
#define SINGLE_LINKED_LIST_CPP 1
#include "LinkedListNode.hpp"
namespace DataStructuresAndAlgorithms
{
namespace LinkedList
{
template <typename T, typename _Alloc>
template <typename... Args>
SingleLinkedListNodeBase *SingleLinkedListBase<T, _Alloc>::InsertAfter(_ConstIterator pos, Args &&...args)
{
    SingleLinkedListNodeBase *temp = const_cast<SingleLinkedListNodeBase *>(pos.nodeBase);
    _Node *node = this->CreateNode(std::forward<Args>(args)...);
    node->_pNext = temp->_pNext;
    temp->_pNext = node;
    return temp->_pNext;
}
template <typename T, typename _Alloc>
SingleLinkedListNodeBase *SingleLinkedListBase<T, _Alloc>::EraseAfter(SingleLinkedListNodeBase *pos)
{
    _Node *curr = static_cast<_Node *>(pos->_pNext);
    pos->_pNext = curr->_pNext;
    _TAllocatorType tAllocType(GetNodeAllocator());
    tAllocType.Destroy(curr->GetValuePtr());
    curr->~_Node();
    PutNode(curr);
    return pos->_pNext;
}
template <typename T, typename _Alloc>
SingleLinkedListNodeBase *SingleLinkedListBase<T, _Alloc>::EraseAfter(SingleLinkedListNodeBase *pos,
                                                                      SingleLinkedListNodeBase *last)
{
    _Node *curr = static_cast<_Node *>(pos->_pNext);
    while (curr != last)
    {
        _Node *temp = curr;
        curr = static_cast<_Node *>(pos->_pNext);
        _TAllocatorType tAllocType(GetNodeAllocator());
        tAllocType.Destroy(temp->GetValuePtr());
        temp->~_Node();
        PutNode(temp);
    }
}
} // namespace LinkedList
} // namespace DataStructuresAndAlgorithms
#endif