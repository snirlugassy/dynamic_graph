//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_GRAPH_NODE_H
#define DS_ALGS_CODING_HW_GRAPH_NODE_H

#include "LinkedList.h"
#include "ListItem.h"
#include "AdjacencyListNode.h"

class Graph_Node: public ListItem<Graph_Node>, public AdjacencyListNode<Graph_Node> {
private:
    // TODO: chage to LinkedList
    LinkedList<Graph_Node> _out_nodes;
    LinkedList<Graph_Node> _in_nodes;
    unsigned int _id;
public: //TODO: make some members protected
    Graph_Node(unsigned int id);

    void insert_out_node(Graph_Node &node);

    void insert_in_node(Graph_Node &node);

    unsigned Get_out_Degree() const;

    unsigned Get_in_Degree() const;

    unsigned Get_key() const;
};


#endif //DS_ALGS_CODING_HW_GRAPH_NODE_H
