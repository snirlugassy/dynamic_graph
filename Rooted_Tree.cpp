//
// Created by snirlugassy on 12/20/19.
//
#include <iostream>
#include <list>
#include "Rooted_Tree.h"

Rooted_Tree::Rooted_Tree() {}
Rooted_Tree::Rooted_Tree(Tree_Node *root):_root(root) {}
Rooted_Tree::~Rooted_Tree() {
    delete _root;
}

Tree_Node * Rooted_Tree::get_root() { return _root; };
void Rooted_Tree::set_root(Tree_Node *root) { _root = root; };

void Rooted_Tree::Preorder_Print(std::ostream &stream) const {
    Rooted_Tree::preorder_traverse(stream, this->_root);
}

void Rooted_Tree::preorder_traverse(std::ostream &stream, Tree_Node* node) {
    if (node != NULL) {
        stream << node->get_id();
        Tree_Node *child = node->get_child();
        while (child != NULL){
            stream << "," ;
            preorder_traverse(stream, child);
            child = child->get_sibling();
        }
    }
}

void Rooted_Tree::Print_By_Layer(std::ostream &stream) const {
    // TODO: implement queue
    std::list<Tree_Node*> q;

    q.push_front(this->_root);

    unsigned last_height = 0;

    while (!q.empty()) {
        Tree_Node *front = q.front();
        if (front->height != last_height) {
            stream << "\n";
            last_height = front->height;
        }
        q.pop_front();
        while (front) {
            stream << front->get_id() << ",";
            Tree_Node *child = front->get_child();
            if (child != nullptr) {
                q.push_back(child);
            }
            front = front->get_sibling();
        }
    }
}