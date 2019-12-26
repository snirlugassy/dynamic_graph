//
// Created by snirlugassy on 12/20/19.
//
#include <iostream>
#include <queue>
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
    std::queue<Tree_Node*> q;
    q.push(this->_root);
    while (!q.empty()) {
        Tree_Node *front = q.front();
        q.pop();
        while (front != nullptr) {
            stream << front->get_id();
            Tree_Node *child = front->get_child();
            if (child != nullptr) {
                q.push(child);
            }
            front = front->get_sibling();
        }
        //TODO: line break properly
    }
}