//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_ROOTED_TREE_H
#define DS_ALGS_CODING_HW_ROOTED_TREE_H

#include <iostream>
#include "Tree_Node.h"

class Rooted_Tree {
private:
    Tree_Node* _root;
    static void preorder_traverse(std::ostream &stream, Tree_Node* node);
public:
    Rooted_Tree();

    Rooted_Tree(Tree_Node* root);

    ~Rooted_Tree();

    void set_root(Tree_Node* root);
    Tree_Node* get_root();

    void Print_By_Layer(std::ostream &stream) const;
    void Preorder_Print(std::ostream &stream) const;
};


#endif //DS_ALGS_CODING_HW_ROOTED_TREE_H
