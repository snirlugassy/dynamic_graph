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
unsigned Graph_Node::Get_out_Degree() const {
    return _out_nodes.size();
}

unsigned Graph_Node::Get_in_Degree() const {
    return _in_nodes.size();
}

unsigned Graph_Node::Get_key() const {
    return _id;
}