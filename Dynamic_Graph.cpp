//
// Created by snirlugassy on 12/20/19.
//

#include "Dynamic_Graph.h"

Dynamic_Graph::Dynamic_Graph() {};

Dynamic_Graph::~Dynamic_Graph() {};

void Dynamic_Graph::Delete_Node(Graph_Node* node) {
    if (node->Get_in_Degree() == 0 && node->Get_out_Degree() == 0)
        _nodes.remove(node);
};

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    Graph_Edge *edge = new Graph_Edge(from, to);
    _edges.push_back(*edge);
    return edge;
};

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {}

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node *node = new Graph_Node(node_key);
    _nodes.push_back(*node);
    return node;
};

//Rooted_Tree* Dynamic_Graph::SCC() const {};

//Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {};