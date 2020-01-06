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
    ListItem *next = NULL;
    ListItem *prev = NULL;
    T *item;

    // Any linked list is a friend
    template <class S>
    friend class LinkedList;
//    friend class AdjacencyList;
public:
    ListItem<T>() {};
    ListItem<T>(T* item): item(item) {};
};

#endif //DS_ALGS_CODING_HW_LISTITEM_H
