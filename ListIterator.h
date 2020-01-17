//
// Created by snirlugassy on 1/17/20.
//

#ifndef DS_ALGS_CODING_HW_LISTITERATOR_H
#define DS_ALGS_CODING_HW_LISTITERATOR_H

template <typename T>
class ListIterator {
    typedef T* pointer;
    typedef T item_type;
    T* _item;

    pointer
    operator*() const
    { return _item; }

    pointer
    operator->() const
    { return _item; }

    ListIterator<T>&
    operator++()
    {
        _item = _item->next;
        return this;
    }

    ListIterator<T>&
    operator--()
    {
        _item = _item->prev;
        return this;
    }

    ListIterator<T>
    operator--(int)
    {
        ListIterator<T> __tmp = *this;
        _item = _item->prev;
        return __tmp;
    }

    friend bool
    operator==(const ListIterator<T>& __x, const ListIterator<T>& __y)
    { return __x._M_node == __y._M_node; }

    friend bool operator!=(const ListIterator<T> & a, const ListIterator<T>& b)
    { return a._item != b._item; }

};


#endif //DS_ALGS_CODING_HW_LISTITERATOR_H
