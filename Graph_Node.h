//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_GRAPH_NODE_H
#define DS_ALGS_CODING_HW_GRAPH_NODE_H


#include <list>

class Graph_Node {
private:
    // TODO: chage to LinkedList
    std::list<Graph_Node *> _out_nodes;
    std::list<Graph_Node *> _in_nodes;
    unsigned int _id;
public: //TODO: make some members protected
    void insert_out_node(Graph_Node *node);

    void insert_in_node(Graph_Node *node);

    unsigned Get_out_Degree() const;

    unsigned Get_in_Degree() const;

    unsigned Get_key() const;
};


#endif //DS_ALGS_CODING_HW_GRAPH_NODE_H
