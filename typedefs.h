//
// Created by snirlugassy on 28/12/2019.
//

#ifndef DS_ALGS_CODING_HW_TYPEDEFS_H
#define DS_ALGS_CODING_HW_TYPEDEFS_H

#include "LinkedList.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Graph_Edge;
class Graph_Node;

typedef LinkedList<Graph_Node*> AdjacencyList;
typedef LinkedList<Graph_Node*> NodeList;
typedef LinkedList<Graph_Edge*> EdgeList;

#endif //DS_ALGS_CODING_HW_TYPEDEFS_H
