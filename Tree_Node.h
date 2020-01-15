//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_TREE_NODE_H
#define DS_ALGS_CODING_HW_TREE_NODE_H

#include "stddef.h"

class Tree_Node {
private:
    unsigned int _id;
    Tree_Node* _parent = NULL;
    Tree_Node* _left_child = NULL;
    Tree_Node* _right_sibling = NULL;
public:
    // TODO: assign height
    unsigned int height;
    Tree_Node(unsigned int id);
    Tree_Node(unsigned int id, Tree_Node* parent);

    // Setters
    void set_parent(Tree_Node* parent);
    void set_child(Tree_Node* child);
    void set_sibling(Tree_Node* sibling);

    // Getters
    unsigned int get_id();
    Tree_Node* get_parent();
    Tree_Node* get_child();
    Tree_Node* get_sibling();

    Tree_Node* add_child(unsigned int id);
    void delete_child();
    bool is_leaf();
    bool is_root();
    bool has_sibling();
};


#endif //DS_ALGS_CODING_HW_TREE_NODE_H
