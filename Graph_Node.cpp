//
// Created by snirlugassy on 12/20/19.
//

#include "Graph_Node.h"

Graph_Node::Graph_Node(unsigned int id): _id(id) {
    _in_nodes = new AdjacencyList();
    _out_nodes = new AdjacencyList();
}

Graph_Node::~Graph_Node() {
    delete _in_nodes;
    delete _out_nodes;
}


void Graph_Node::transpose() {
    AdjacencyList * temp = _out_nodes;
    _out_nodes = _in_nodes;
    _in_nodes = temp;
}

unsigned Graph_Node::Get_out_Degree() const {
    return _out_nodes->length();
}

unsigned Graph_Node::Get_in_Degree() const {
    return _in_nodes->length();
}

unsigned Graph_Node::Get_key() const {
    return _id;
}

bool Graph_Node::operator==(const Graph_Node &rhs) const {
    return _out_nodes == rhs._out_nodes &&
           _in_nodes == rhs._in_nodes &&
           _graph_pos == rhs._graph_pos &&
           _id == rhs._id &&
           _color == rhs._color;
}

bool Graph_Node::operator!=(const Graph_Node &rhs) const {
    return !(rhs == *this);
}
