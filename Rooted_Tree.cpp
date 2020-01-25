//
// Created by snirlugassy on 12/20/19.
//
#include <iostream>
#include "Rooted_Tree.h"
#include "Queue.h"
#include <cstddef>

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
    Queue<Tree_Node*> q;
    Tree_Node *_printed_root = this->_root;
    q.enqueue(_printed_root);

    unsigned last_height = 0;

    while (!q.empty()) {
        Tree_Node *front = q.front();
        if (front->height != last_height) {
            stream << "\n";
            last_height = front->height;
        } else {
            if(front->get_parent())
                stream << ",";
        }
        q.dequeue();
        while (front != NULL) {
            stream << front->get_id();
            if(front->get_sibling())
                stream << ",";
            Tree_Node *child = front->get_child();
            if (child != NULL) {
                q.enqueue(child);
            }
            front = front->get_sibling();
        }
    }
}