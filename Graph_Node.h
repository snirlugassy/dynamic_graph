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
    // The graph's nodes list participation iterator
    // In order to delete the node in constant time
    NodeList::iterator* _graph_pos = NULL;
    unsigned int _id;
    // DFS variables
    unsigned _color;
    void transpose();
    friend class Dynamic_Graph;

public: //TODO: make some members protected
    explicit Graph_Node(unsigned int id);
    ~Graph_Node();

    Graph_Node& operator=(const Graph_Node &rhs);
    bool operator==(const Graph_Node &rhs) const;
    bool operator!=(const Graph_Node &rhs) const;

    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const;

};


#endif //DS_ALGS_CODING_HW_GRAPH_NODE_H
