//
// Created by snirlugassy on 28/12/2019.
//

#ifndef DS_ALGS_CODING_HW_TYPEDEFS_H
#define DS_ALGS_CODING_HW_TYPEDEFS_H

#include <list>

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Graph_Edge;
class Graph_Node;

typedef std::list<Graph_Node*> AdjacencyList;
typedef std::list<Graph_Node*>::iterator AdjacencyListNode;

typedef std::list<Graph_Node*> NodeList;
typedef std::list<Graph_Node*>::iterator NodeIterator;


typedef std::list<Graph_Edge*> EdgeList;
typedef std::list<Graph_Edge*>::iterator EdgeIterator;

#endif //DS_ALGS_CODING_HW_TYPEDEFS_H
