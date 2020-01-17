//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LISTITEM_H
#define DS_ALGS_CODING_HW_LISTITEM_H

#include "stddef.h"

template <typename T>
class ListItem {
public:
    typedef T* pointer;
    typedef T item_type;

    ListItem<T> *next = NULL;
    ListItem<T> *prev = NULL;
    T* item;

    ListItem<T>() {};
    ListItem<T>(pointer item): item(item) {};

    // Referencing
    item_type& operator*() const { return *item; }
    item_type& operator->() const { return *item; }

    // Iteration Operations
    ListItem<T>& operator++() {
        *this = *next;
        return *this;
    }
    ListItem<T>& operator--() { return *this->prev; }

    ListItem<T>& operator=(ListItem<T> &other) {
        prev = other.prev;
        next = other.next;
        item = other.item;
        return *this;
    }

    // Comparison Operations
    friend bool
    operator==(const ListItem<T>& x, const ListItem<T>& y)
    { return x.item == y.item; }

    friend bool operator!=(const ListItem<T> & x, const ListItem<T>& y)
    { return x.item != y.item; }



};

#endif //DS_ALGS_CODING_HW_LISTITEM_H
