//
// Created by snirlugassy on 12/20/19.
//


#ifndef DS_ALGS_CODING_HW_GRAPH_NODE_H
#define DS_ALGS_CODING_HW_GRAPH_NODE_H


#include "typedefs.h"

class Graph_Node {
private:
    // TODO: chage to LinkedList
    AdjacencyList _out_nodes;
    AdjacencyList _in_nodes;
    unsigned int _id;
    // DFS variables
    unsigned _color;
    Graph_Node* _pi;
    void transpose();
    friend class Dynamic_Graph;

public: //TODO: make some members protected
    Graph_Node(unsigned int id);
    ~Graph_Node();
    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const;
};


#endif //DS_ALGS_CODING_HW_GRAPH_NODE_H
