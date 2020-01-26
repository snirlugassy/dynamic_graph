//
// Created by snirlugassy on 12/20/19.
//


#ifndef DS_ALGS_CODING_HW_GRAPH_NODE_H
#define DS_ALGS_CODING_HW_GRAPH_NODE_H


#include "typedefs.h"

class Graph_Node {
private:
    AdjacencyList *_out_nodes = NULL;
    AdjacencyList *_in_nodes = NULL;
    NodeList::iterator* _graph_pos = NULL;
    unsigned int _id;
    // DFS variables
    unsigned _color;
    void transpose();
    friend class Dynamic_Graph;

public:
    explicit Graph_Node(unsigned int id);
    ~Graph_Node();

    bool operator==(const Graph_Node &rhs) const;
    bool operator!=(const Graph_Node &rhs) const;

    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const;

};


#endif //DS_ALGS_CODING_HW_GRAPH_NODE_H
