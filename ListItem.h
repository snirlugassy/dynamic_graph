//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LISTITEM_H
#define DS_ALGS_CODING_HW_LISTITEM_H

#include <cstddef>

template <typename T>
class ListItem {
public:
    typedef T* pointer;

    ListItem<T> *next = NULL;
    ListItem<T> *prev = NULL;
    T item = NULL;

    ListItem<T>() {};
    explicit ListItem<T>(T &item): item(item) {};

    // Referencing
    T operator*() const {  return item;  }
    T operator->() const {  return item;  }

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

    ListItem<T>& operator=(ListItem<T> const &rhs) {
        prev = rhs.prev;
        next = rhs.next;
        item = rhs.item;
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
