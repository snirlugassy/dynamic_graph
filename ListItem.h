//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LISTITEM_H
#define DS_ALGS_CODING_HW_LISTITEM_H

#include "stddef.h"

template <typename T>
class ListItem {
protected:
    unsigned int _id;
    T *next = NULL;
    T *prev = NULL;

    // Any linked list is a friend
    template <class S>
    friend class LinkedList;
public:
    ListItem<T>() {};
    ListItem<T>(unsigned int id): _id(id) {};
};

#endif //DS_ALGS_CODING_HW_LISTITEM_H
