//
// Created by snirlugassy on 12/20/19.
//

#include "Graph_Edge.h"

Graph_Edge::Graph_Edge(
        Graph_Node *start,
        Graph_Node *end
        ):  _start(start),
            _end(end)
            {};

void Graph_Edge::transpose() {
    Graph_Node *_temp_node = _start;
    _start = _end;
    _end = _temp_node;

    AdjacencyList::iterator *_temp_adj = _start_adj_iterator;
    _start_adj_iterator = _end_adj_iterator;
    _end_adj_iterator = _temp_adj;
}
