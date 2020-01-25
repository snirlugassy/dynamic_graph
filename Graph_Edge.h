//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_GRAPH_EDGE_H
#define DS_ALGS_CODING_HW_GRAPH_EDGE_H

#include "Graph_Node.h"
#include "ListItem.h"
#include "typedefs.h"


class Graph_Edge {
private:
    Graph_Node *_start = NULL;
    Graph_Node *_end = NULL;
    AdjacencyList::iterator *_start_adj_iterator = NULL;
    AdjacencyList::iterator *_end_adj_iterator = NULL;
    EdgeList::iterator *_graph_pos = NULL;
    void transpose();
    friend class Dynamic_Graph;
public:
    Graph_Edge(
        Graph_Node *start,
        Graph_Node *end
    );

    ~Graph_Edge() {
        _start = _end = NULL;
        _start_adj_iterator = _end_adj_iterator = NULL;
        _graph_pos = NULL;
    };
};


#endif //DS_ALGS_CODING_HW_GRAPH_EDGE_H
