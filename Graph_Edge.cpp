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

Graph_Edge::~Graph_Edge() {
//    if(_start != NULL) delete _start;
//    if(_end != NULL) delete _end;

//    if(_start != NULL) {
//        delete _start_adj_iterator;
//    }
//    if(_end_adj_iterator != NULL) {
//        delete _end_adj_iterator;
//    };
//    if(_graph_pos != NULL) {
//        delete _graph_pos;
//    }
}
