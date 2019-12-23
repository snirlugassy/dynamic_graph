//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_TREE_NODE_H
#define DS_ALGS_CODING_HW_TREE_NODE_H


class Tree_Node {
private:
    unsigned int _id;
    // TODO: assign height
    unsigned int _height;
    Tree_Node* _parent = nullptr;
    Tree_Node* _left_child = nullptr;
    Tree_Node* _right_sibling = nullptr;
public:
    Tree_Node(unsigned int id);
    // Setters
    void set_parent(Tree_Node* parent);
    void set_child(Tree_Node* child);
    void set_sibling(Tree_Node* sibling);

    // Getters
    unsigned int get_id();
    Tree_Node* get_parent();
    Tree_Node* get_child();
    Tree_Node* get_sibling();

    void delete_child();
    bool is_leaf();
    bool is_root();
    bool has_sibling();
};


#endif //DS_ALGS_CODING_HW_TREE_NODE_H
