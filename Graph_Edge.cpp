//
// Created by snirlugassy on 12/20/19.
//

#include "Graph_Edge.h"

Graph_Edge::Graph_Edge(
        Graph_Node *start,
        Graph_Node *end,
        AdjacencyListNode startAdjIterator,
        AdjacencyListNode endAdjIterator
        ):  _start(start),
            _end(end),
            _start_adj_iterator(startAdjIterator),
            _end_adj_iterator(endAdjIterator) {};

void Graph_Edge::flip() {
    Graph_Node *_temp_node = _start;
    _start = _end;
    _end = _temp_node;

    AdjacencyListNode _temp_adj = _start_adj_iterator;
    _start_adj_iterator = _end_adj_iterator;
    _end_adj_iterator = _temp_adj;
}
