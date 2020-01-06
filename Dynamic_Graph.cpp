//
// Created by snirlugassy on 12/20/19.
//

#include "Dynamic_Graph.h"
#include "typedefs.h"
#include "stddef.h"

Dynamic_Graph::Dynamic_Graph() {};

Dynamic_Graph::~Dynamic_Graph() {
    while(!_nodes.empty()){
        delete *_nodes.begin();
        _nodes.pop_front();
    }
    while(!_edges.empty()) {
        delete *_edges.begin();
        _edges.pop_front();
    }
};

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node *node = new Graph_Node(node_key);
    _nodes.push_back(node);
    return node;
};


void Dynamic_Graph::Delete_Node(Graph_Node* node) {
    if (node->Get_in_Degree() == 0 && node->Get_out_Degree() == 0) {
        _nodes.remove(node);
        delete node;
    }
};

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    from->_out_nodes.push_front(to);
    AdjacencyListNode fromAdjIter = from->_out_nodes.begin();
    to->_in_nodes.push_front(from);
    AdjacencyListNode toAdjIter = to->_in_nodes.begin();

    Graph_Edge *edge = new Graph_Edge(from, to, fromAdjIter, toAdjIter);
    _edges.push_front(edge);
    edge->_graph_pos = _edges.begin();
    return edge;
};

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {
    edge->_start->_out_nodes.erase(edge->_start_adj_iterator);
    edge->_end->_in_nodes.erase(edge->_end_adj_iterator);
    _edges.erase(edge->_graph_pos);
    delete edge;
}

void Dynamic_Graph::_dfs_visit(std::stack<Graph_Node*> *_stack, Graph_Node* node) const {
    node->_color = GRAY;
    std::list<Graph_Node*>::const_iterator v = node->_out_nodes.begin();
    for (; v != node->_out_nodes.end(); v++) {
        Graph_Node *adj = *v;
        if (adj->_color == WHITE) {
            adj->_pi = node;
            _dfs_visit(_stack, adj);
        }
    }
    node->_color = BLACK;
    _stack->push(node);
}

void Dynamic_Graph::_dfs_unvisit(std::stack<Graph_Node*> *_stack, Graph_Node* node) const {
    node->_color = GRAY;
    std::list<Graph_Node*>::const_iterator v = node->_out_nodes.begin();
    for (; v != node->_out_nodes.end(); v++) {
        Graph_Node *adj = *v;
        if (adj->_color == WHITE) {
            adj->_pi = node;
            _dfs_visit(_stack, adj);
        }
    }
    node->_color = BLACK;
    _stack->push(node);
}

Rooted_Tree* Dynamic_Graph::SCC() const {
    std::stack<Graph_Node*> S;

    // Initialize the graph nodes
    for (std::list<Graph_Node*>::const_iterator v = _nodes.begin(); v != _nodes.end(); v++) {
        (*v)->_color = WHITE;
        (*v)->_pi = NULL;
    }

    // First DFS traversal
    for (std::list<Graph_Node*>::const_iterator u = _nodes.begin(); u != _nodes.end(); u++) {
        Graph_Node *node = *u;
        if( node->_color == WHITE){
            this->_dfs_visit(&S, node);
        }
    }

};

void Dynamic_Graph::transpose() {
    for (std::list<Graph_Edge *>::const_iterator e = _edges.begin(); e != _edges.end(); e++) {
        (*e)->flip();
    }
}
//Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {};