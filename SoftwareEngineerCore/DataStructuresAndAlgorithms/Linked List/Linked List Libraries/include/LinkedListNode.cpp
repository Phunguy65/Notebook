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

template<typename T, typename _Alloc> template<typename _InputIterator> void SingleLinkedList<T, _Alloc>::RangeInitialize(_InputIterator first, _InputIterator last){
    _NodeBase *temp = &this->_linkedListCore._nodeHead;
    while (first!=last) {
    temp->_pNext = this->CreateNode(*first);
    temp = temp->_pNext;
    ++first;
    }
}

template<typename T, typename _Alloc> void SingleLinkedList<T,_Alloc>::DefaultInitialize(_SizeType size){
    _NodeBase *temp = &this->_linkedListCore._nodeHead;
    while (size) {
        temp->_pNext = this->CreateNode();
        temp = temp->_pNext;
        --size;
    }
}

template<typename T, typename _Alloc> void SingleLinkedList<T,_Alloc>::FillInitialize(_SizeType size, const T &value){
    _NodeBase* temp = &this->_linkedListCore._nodeHead;
    while (size) {
        temp->_pNext=this->CreateNode(value);
        temp = temp->_pNext;
    }
}

template<typename T, typename _Alloc> SingleLinkedList<T,_Alloc>& SingleLinkedList<T,_Alloc>::operator=(const SingleLinkedList& list){
    if(this != &list){
        Clear();
    }
    return *this;
}


} // namespace LinkedList
} // namespace DataStructuresAndAlgorithms
#endif