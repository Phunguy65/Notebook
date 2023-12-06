
#pragma onece
#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE 1
#include "Allocator.hpp"
#include <algorithm>
#include <asm-generic/errno.h>
#include <cstddef>
#include <exception>
#include <memory>
#include <new>
#include <ostream>
#include <utility>
using namespace MemoryManagement;
namespace DataStructuresAndAlgorithms
{
namespace LinkedList
{

struct SingleLinkedListNodeBase
{
    SingleLinkedListNodeBase *_pNext = nullptr;
    SingleLinkedListNodeBase() = default;
    SingleLinkedListNodeBase(SingleLinkedListNodeBase &&nodeBase) noexcept : _pNext(nodeBase._pNext)
    {
    }
    SingleLinkedListNodeBase(const SingleLinkedListNodeBase &) = delete;
    SingleLinkedListNodeBase &operator=(const SingleLinkedListNodeBase &) = delete;
    SingleLinkedListNodeBase &operator=(SingleLinkedListNodeBase &&nodeBase) noexcept
    {
        _pNext = nodeBase._pNext;
        nodeBase._pNext = nullptr;
        return *this;
    }
    SingleLinkedListNodeBase *TransferAfter(SingleLinkedListNodeBase *begin, SingleLinkedListNodeBase *end) noexcept
    {
        SingleLinkedListNodeBase *keep = begin->_pNext;
        if (end)
        {
            begin->_pNext = end->_pNext;
            end->_pNext = _pNext;
        }
        else
        {
            begin->_pNext = nullptr;
            _pNext = keep;
        }
        return end;
    }
    void ReverseAfter() noexcept
    {
        SingleLinkedListNodeBase *tail = this->_pNext;
        if (!tail)
        {
            return;
        }
        while (SingleLinkedListNodeBase *temp = tail->_pNext)
        {
            SingleLinkedListNodeBase *keep = this->_pNext;
            this->_pNext = temp;
            tail->_pNext = temp->_pNext;
            this->_pNext->_pNext = keep;
        }
        return;
    }
};

template <typename T> struct SingleLinkedListNode : public SingleLinkedListNodeBase
{
    T data;
    SingleLinkedListNode() = default;
    template <typename... Args>
    SingleLinkedListNode(Args &&...args) : SingleLinkedListNodeBase(), data(std::forward<Args>(args)...)
    {
    }
    T *GetValuePtr()
    {
        return &this->data;
    }
    T const *GetValuePtr() const
    {
        return &this->data;
    }
};

template <typename T> struct SingleLinkedListIterator
{
    SingleLinkedListNodeBase *_nodeBase;
    SingleLinkedListIterator() noexcept : _nodeBase()
    {
    }
    explicit SingleLinkedListIterator(SingleLinkedListNodeBase *nodeBase) noexcept : _nodeBase()
    {
    }
    T &operator*() const noexcept
    {
        return *static_cast<SingleLinkedListNode<T> *>(this->_nodeBase)->GetValuePtr();
    }
    T *operator->() const noexcept
    {
        return static_cast<SingleLinkedListNode<T>>(this->_nodeBase).GetValuePtr();
    }
    SingleLinkedListIterator<T> &operator++() noexcept
    {
        this->_nodeBase = this->_nodeBase->pNext;
        return *this;
    }
    SingleLinkedListIterator<T> operator++(int) noexcept
    {
        SingleLinkedListIterator<T> temp(*this);
        this->_nodeBase = this->_nodeBase->pNext;
        return temp;
    }
    friend bool operator!=(const SingleLinkedListIterator<T> &lhs, const SingleLinkedListIterator<T> &rhs) noexcept
    {
        return lhs._nodeBase != rhs._nodeBase;
    }
    SingleLinkedListIterator<T> Next() const noexcept
    {
        if (this->_nodeBase)
        {
            return SingleLinkedListIterator(this->_nodeBase->pNext);
        }
        else
        {
            return SingleLinkedListIterator(nullptr);
        }
    }
};

template <typename T> struct SingleLinkedListConstIterator
{
    typedef SingleLinkedListConstIterator<T> _Self;
    typedef const SingleLinkedListNode<T> _Node;
    typedef SingleLinkedListIterator<T> _Iterator;

    typedef T _ValueType;
    typedef const T *_Pointer;
    typedef const T &_Reference;

    const SingleLinkedListNodeBase *nodeBase;

    SingleLinkedListConstIterator() noexcept : nodeBase()
    {
    }

    explicit SingleLinkedListConstIterator(const SingleLinkedListNodeBase *nodeBase) noexcept : nodeBase(nodeBase)
    {
    }

    SingleLinkedListConstIterator(const _Iterator &iter) noexcept : nodeBase(iter._nodeBase)
    {
    }

    _Reference operator*() const noexcept
    {
        return *static_cast<_Node *>(this->nodeBase)->GetValuePtr();
    }

    _Pointer operator->() const noexcept
    {
        return static_cast<_Node *>(this->nodeBase)->GetValuePtr();
    }

    _Self &operator++() noexcept
    {
        this->nodeBase = this->nodeBase->pNext;
        return *this;
    }

    _Self operator++(int) noexcept
    {
        _Self temp(*this);
        this->nodeBase = this->nodeBase->pNext;
        return temp;
    }

    friend bool operator!=(const _Self &lhs, const _Self &rhs) noexcept
    {
        return lhs.nodeBase != rhs.nodeBase;
    }

    _Self Next() const noexcept
    {
        if (this->nodeBase)
        {
            return SingleLinkedListConstIterator(this->nodeBase->pNext);
        }
        else
        {
            return SingleLinkedListConstIterator(nullptr);
        }
    }
};

template <typename T, typename _Alloc> struct SingleLinkedListBase
{
  protected:
    typedef typename _Alloc::template Rebind<SingleLinkedListNode<T>>::other _NodeAllocatorType;
    typedef typename _Alloc::template Rebind<T> _TAllocatorType;
    struct SingleLinkedListCore : public _NodeAllocatorType
    {
        SingleLinkedListNodeBase _nodeHead;
        SingleLinkedListCore(const _NodeAllocatorType &init) noexcept : _NodeAllocatorType(init), _nodeHead()
        {
        }
        SingleLinkedListCore(SingleLinkedListCore &&) = default;
        SingleLinkedListCore(SingleLinkedListCore &&sll, _NodeAllocatorType &&node)
            : _NodeAllocatorType(std::move(node)), _nodeHead(std::move(sll._nodeHead))
        {
        }
        SingleLinkedListCore(_NodeAllocatorType &&node) : _NodeAllocatorType(std::move(node)), _nodeHead()
        {
        }
        SingleLinkedListCore() : _NodeAllocatorType(), _nodeHead()
        {
        }
    };

  public:
    SingleLinkedListCore _linkedListCore;
    SingleLinkedListBase() = default;
    typedef SingleLinkedListNode<T> _Node;
    typedef SingleLinkedListIterator<T> _Iterator;
    typedef SingleLinkedListConstIterator<T> _ConstIterator;
    typedef _Alloc _AllocatorType;
    SingleLinkedListBase(_NodeAllocatorType &&node) : SingleLinkedListCore(std::move(node))
    {
    }
    _NodeAllocatorType &GetNodeAllocator() noexcept
    {
        return this->_linkedListCore;
    }
    const _NodeAllocatorType &GetNodeAllocator() const noexcept
    {
        return this->_linkedListCore;
    }
    _TAllocatorType GetTAllocator() const noexcept
    {
        return _TAllocatorType(GetNodeAllocator());
    }
    _AllocatorType GetAllocator() const noexcept
    {
        return _AllocatorType(GetNodeAllocator());
    }

  protected:
    _Node *GetNode()
    {
        return this->_linkedListCore.Allocate(1);
    }
    void PutNode(SingleLinkedListNode<T> *node)
    {
        this->_linkedListCore.DeAllocate(node, 1);
    }

    template <typename... Args> SingleLinkedListNodeBase *InsertAfter(_ConstIterator pos, Args &&...args);
    SingleLinkedListNodeBase *EraseAfter(SingleLinkedListNodeBase *pos);
    SingleLinkedListNodeBase *EraseAfter(SingleLinkedListNodeBase *pos, SingleLinkedListNodeBase *last);
};

template <typename T, typename _Alloc = Allocator<T>()> class SingleLinkedList : SingleLinkedListBase<T, _Alloc>
{
  private:
    typedef SingleLinkedListBase<T, _Alloc> _Base;
    typedef SingleLinkedListNodeBase _NodeBase;
    typedef typename _Base::_Node _Node;
    typedef typename _Base::_NodeAllocatorType _NodeAllocatorType;
    typedef typename _Base::_TAllocatorType _TAllocatorType;

  public:
    typedef T _ValueType;
    typedef _ValueType &_Reference;
    typedef const _ValueType &_ConstReference;

    typedef typename _Base::_Iterator _Iterator;
    typedef typename _Base::_ConstIterator _ConstIterator;
    typedef std::size_t _SizeType;

    typedef typename _Base::_AllocatorType _AllocatorType;
    SingleLinkedList() = default;
    explicit SingleLinkedList(const _Alloc &al) noexcept : _Base(_NodeAllocatorType(al))
    {
    }
    explicit SingleLinkedList(_SizeType size, const _Alloc &al = _Alloc()) : _Base(_NodeAllocatorType(al))
    {
        DefaultInitialize(size);
    }
    SingleLinkedList(_SizeType size, const T &value, const _Alloc &al = _Alloc()) : _Base(_NodeAllocatorType(al))
    {
        FillInitialize(size, value);
    }
    SingleLinkedList(const SingleLinkedList &sll) : _Base(sll.GetNodeAllocator())
    {
    }
    SingleLinkedList(SingleLinkedList &&sll) noexcept : _Base(std::move(sll))
    {
    }
    SingleLinkedList &operator=(const SingleLinkedList &sll);

    _Iterator GetBegin()
    {
        return _Iterator(&this->_linkedListCore._nodeHead._pNext);
    }
    _ConstIterator GetConstBegin() const noexcept
    {
        return _ConstIterator(&this->_linkedListCore._nodeHead._pNext);
    }
    _Iterator GetEnd()
    {
        return _Iterator(nullptr);
    }
    _ConstIterator GetConstEnd() const noexcept
    {
        return _ConstIterator(nullptr);
    }
    _Iterator GetBeginBeforeHead()
    {
        return _Iterator(&this->_linkedListCore._nodeHead);
    }
    _Iterator GetConstBeginBeforeHead() const noexcept
    {
        return _ConstIterator(&this->_linkedListCore._nodeHead);
    }

    bool IsEmpty() const noexcept
    {
        return this->_linkedListCore._nodeHead._pNext == nullptr;
    }

    _Reference GetItemFront()
    {
        _Node *front = static_cast<_Node *>(this->_linkedListCore._nodeHead._pNext);
        return *front.;
    }

  protected:
    using _Base::GetNode;
    using _Base::GetNodeAllocator;
    using _Base::GetTAllocator;
    using _Base::PutNode;
    using _Base::SingleLinkedListCore;
    template <typename... Args> _Node *CreateNode(Args &&...args)
    {
        _Node *node = this->GetNode();
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

  private:
    void FillInitialize(_SizeType size, const T &value);
    void DefaultInitialize(_SizeType size);
    void RangInitialize();
};

} // namespace LinkedList
} // namespace DataStructuresAndAlgorithms
#endif