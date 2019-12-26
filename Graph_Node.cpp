//
// Created by snirlugassy on 12/20/19.
//

#include "Graph_Node.h"

Graph_Node::Graph_Node(unsigned int id): ListItem{id}, _id(id) {}

void Graph_Node::insert_out_node(Graph_Node &node) {
    _out_nodes.push_back(node);
}

void Graph_Node::insert_in_node(Graph_Node &node) {
    _in_nodes.push_back(node);
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