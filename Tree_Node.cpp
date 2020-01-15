//
// Created by snirlugassy on 12/20/19.
//

#include "stddef.h"
#include "Tree_Node.h"

// TODO: create a destructor
Tree_Node::Tree_Node(unsigned int id): _id(id), height(0) {}
Tree_Node::Tree_Node(unsigned int id, Tree_Node* parent): _id(id), _parent(parent) ,height(0) {}

void Tree_Node::set_parent(Tree_Node *parent) {
    _parent = parent;
    height = parent->height + 1;
}

void Tree_Node::set_child(Tree_Node *child) {
    _left_child = child;
    _left_child->height = height + 1;
}

void Tree_Node::set_sibling(Tree_Node *sibling) {
    _right_sibling = sibling;
    _right_sibling->height = height;
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

Tree_Node* Tree_Node::add_child(unsigned int id) {
    Tree_Node *child = new Tree_Node(id);
    child->height = height + 1;
    if (_left_child == NULL) {
        _left_child = child;
    } else {
        Tree_Node *pos = _left_child;
        while(pos->_right_sibling != NULL)
            pos = pos->_right_sibling;
        pos->_right_sibling = child;
    }
    return child;
}

void Tree_Node::delete_child() {
    this->_left_child = NULL;
}