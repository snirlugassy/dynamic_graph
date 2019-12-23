//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_GRAPH_EDGE_H
#define DS_ALGS_CODING_HW_GRAPH_EDGE_H

#include "Graph_Node.h"

class Graph_Edge {
private:
    Graph_Node *_start;
    Graph_Node *_end;
public:
    Graph_Edge(Graph_Node *from, Graph_Node *to);
};

#endif //DS_ALGS_CODING_HW_GRAPH_EDGE_H
