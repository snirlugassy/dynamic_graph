//
// Created by snirlugassy on 12/20/19.
//

#include <queue>
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

void Dynamic_Graph::_dfs_unvisit(Graph_Node* node, Tree_Node* _scc_tree_node) const {
    node->_color = GRAY;
    std::list<Graph_Node*>::const_iterator v = node->_out_nodes.begin();
    for (; v != node->_out_nodes.end(); v++) {
        Graph_Node *adj = *v;
        if(adj->_color == BLACK) {
            Tree_Node * _scc_component_node = _scc_tree_node->add_child(adj->_id);
            adj->_pi = node;
            _dfs_unvisit(adj, _scc_component_node);
        }
    }
    node->_color = WHITE;
}

Rooted_Tree* Dynamic_Graph::SCC() const {
    Tree_Node *_root = new Tree_Node(0);
    Rooted_Tree *_scc = new Rooted_Tree(_root);

    // TODO: create stack
    std::stack<Graph_Node*> S;

    // Initialize the graph nodes
    // O(N)
    for (std::list<Graph_Node*>::const_iterator v = _nodes.begin(); v != _nodes.end(); v++) {
        (*v)->_color = WHITE;
        (*v)->_pi = NULL;
    }

    // First DFS traversal
    // DFS: O(N+M)
    for (std::list<Graph_Node*>::const_iterator u = _nodes.begin(); u != _nodes.end(); u++) {
        Graph_Node *node = *u;
        if( node->_color == WHITE){
            this->_dfs_visit(&S, node);
        }
    }

    // Transpose the graph
    // O(N+M)
    transpose();

    // O(N)
    for (std::list<Graph_Node*>::const_iterator v = _nodes.begin(); v != _nodes.end(); v++) {
        (*v)->_pi = NULL;
    }

    // DFS on the transposed graph
    // DFS: O(N+M)
    while(!S.empty()) {
        Graph_Node *v = S.top();
        if (v->_color == BLACK) {
            Tree_Node *_scc_root = _root->add_child(v->_id);
            _dfs_unvisit(v, _scc_root);
        }
        S.pop();
    }

    // Transpose again, go back to the original orientation
    // O(N+M)
    transpose();

    return _scc;
};

void Dynamic_Graph::transpose() const {
    // O(M)
    for (std::list<Graph_Edge *>::const_iterator e = _edges.begin(); e != _edges.end(); e++) {
        Graph_Edge *edge = *e;
        edge->transpose();
    }

    // O(N)
    for (std::list<Graph_Node *>::const_iterator v = _nodes.begin(); v != _nodes.end(); v++) {
        Graph_Node *node = *v;
        node->transpose();
    }
}

Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
        Tree_Node * _bfs_tree_node = new Tree_Node(source->_id);
        Rooted_Tree *_bfs_tree = new Rooted_Tree(_bfs_tree_node);

        std::queue<Graph_Node*> Q;

        for (std::list<Graph_Node*>::const_iterator v = _nodes.begin(); v != _nodes.end(); v++) {
            (*v)->_color = WHITE;
            (*v)->_pi = NULL;
            (*v)->_distance = -1;
        }

        source->_color = GRAY;
        source->_pi = NULL;
        source->_distance = 0;

        // Enqueue
        Q.push(source);

        while(!Q.empty()) {
            // Dequeue
            Graph_Node* u = Q.front();
            Q.pop();
            Tree_Node * _bfs_tree_node = new Tree_Node(u->_id);
            for (std::list<Graph_Node*>::const_iterator v = u->_out_nodes.begin(); v != u->_out_nodes.end(); v++) {
                Graph_Node *node = *v;
                if( node->_color == WHITE){
                    Tree_Node * _bfs_tree_child = new Tree_Node(node->_id);
                    node->_color = GRAY;
                    node->_distance = u->_distance + 1;
                    node->_pi = u;
                    Q.push(node);
                }
            }
            u->_color = BLACK;
        }
    };