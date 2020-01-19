//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_GRAPH_EDGE_H
#define DS_ALGS_CODING_HW_GRAPH_EDGE_H

#include "Graph_Node.h"
#include "ListItem.h"
#include "typedefs.h"
#include <list>


class Graph_Edge: public ListItem<Graph_Edge> {
private:
    Graph_Node *_start;
    Graph_Node *_end;
    AdjacencyList::iterator *_start_adj_iterator;
    AdjacencyList::iterator *_end_adj_iterator;
    // The graph's edges list participation iterator
    // In order to delete the edge in constant time
    EdgeList::iterator *_graph_pos;
    void transpose();
    friend class Dynamic_Graph;
public:
    Graph_Edge(
        Graph_Node *start,
        Graph_Node *end
    );
};


#endif //DS_ALGS_CODING_HW_GRAPH_EDGE_H
