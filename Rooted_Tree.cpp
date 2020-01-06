//
// Created by snirlugassy on 12/20/19.
//
#include <iostream>
#include <stack>
#include <list>
#include "stddef.h"
#include "Rooted_Tree.h"

Rooted_Tree::Rooted_Tree() {}
Rooted_Tree::Rooted_Tree(Tree_Node *root):_root(root) {}
Rooted_Tree::~Rooted_Tree() {}

void Rooted_Tree::Preorder_Print(std::ostream &stream) const {
    // TODO: print preorder
    stream << "hello\n";
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
            stream << front->get_id();
            Tree_Node *child = front->get_child();
            if (child != nullptr) {
                q.push_back(child);
            }
            front = front->get_sibling();
        }
    }
}