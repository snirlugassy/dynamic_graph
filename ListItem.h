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

    ListItem<T> *next = NULL;
    ListItem<T> *prev = NULL;
    T* item;

    ListItem<T>() {};
    ListItem<T>(pointer item): item(item) {};

    // Referencing
    T operator*() const { if(item != NULL) return *item; return NULL; }
    T operator->() const { if(item != NULL) return *item; return NULL; }

    // Iteration Operations
        void operator++() {
        if(next != NULL)
        {
            *this = *next;
        } else {
            prev = this;
            item = NULL;
        }
    }

    void operator--() {
        if(prev != NULL)
        {
            *this = *prev;
        } else {
            next = this;
            item = NULL;
        }
    }

    ListItem<T>& operator=(ListItem<T> &other) {
        prev = other.prev;
        next = other.next;
        *item = *(other.item);
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
