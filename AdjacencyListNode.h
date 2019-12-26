//
// Created by snirlugassy on 25/12/2019.
//

#ifndef DS_ALGS_CODING_HW_ADJACENCYLISTNODE_H
#define DS_ALGS_CODING_HW_ADJACENCYLISTNODE_H

#include "stddef.h"
#include "AdjacencyList.h"

// Same as ListItem but for AdjacencyList

template <typename T>
class AdjacencyListNode {
protected:
    unsigned int _id;
    T *next_node = NULL;
    T *prev_node = NULL;

    friend class AdjacencyList;
public:
    AdjacencyListNode<T>() {};
    AdjacencyListNode<T>(unsigned int id): _id(id) {};
};

#endif //DS_ALGS_CODING_HW_ADJACENCYLISTNODE_H
