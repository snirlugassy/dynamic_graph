//
// Created by snirlugassy on 12/20/19.
//

#include "Graph_Node.h"

Graph_Node::Graph_Node(unsigned int id): _id(id) {}
Graph_Node::~Graph_Node() {
    while(!_out_nodes.empty()){
//        delete *_out_nodes.begin();
        _out_nodes.pop_front();
    }
    while(!_in_nodes.empty()) {
//        delete *_in_nodes.begin();
        _in_nodes.pop_front();
    }
}

void Graph_Node::transpose() {
    AdjacencyList temp = _out_nodes;
    _out_nodes = _in_nodes;
    _in_nodes = temp;
}

unsigned Graph_Node::Get_out_Degree() const {
    return _out_nodes.length();
}

unsigned Graph_Node::Get_in_Degree() const {
    return _in_nodes.length();
}

unsigned Graph_Node::Get_key() const {
    return _id;
}