//
// Created by snirlugassy on 12/20/19.
//

#include "stddef.h"
#include "Tree_Node.h"

Tree_Node::Tree_Node(unsigned int id): _id(id) {}

void Tree_Node::set_parent(Tree_Node *parent) {
    this->_parent = parent;
}

void Tree_Node::set_child(Tree_Node *child) {
    this->_left_child = child;
}

void Tree_Node::set_sibling(Tree_Node *sibling) {
    this->_right_sibling = sibling;
}

unsigned int Tree_Node::get_id() {
    return this->_id;
}

Tree_Node* Tree_Node::get_parent() {
    return this->_parent;
}

Tree_Node* Tree_Node::get_child() {
    return this->_left_child;
}

Tree_Node* Tree_Node::get_sibling() {
    return this->_right_sibling;
}

bool Tree_Node::has_sibling() {
    return this->_right_sibling != NULL;
}

bool Tree_Node::is_leaf() {
    return this->_left_child != NULL;
}

bool Tree_Node::is_root() {
    return this->_parent == NULL;
}

void Tree_Node::delete_child() {
    this->_left_child = NULL;
}