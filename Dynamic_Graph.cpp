//
// Created by snirlugassy on 12/20/19.
//


#include "Dynamic_Graph.h"
#include "typedefs.h"


Dynamic_Graph::~Dynamic_Graph() {
    LinkedList<Graph_Node*>::iterator _garbage_node_iter = _nodes.begin();
    for(; *_garbage_node_iter != NULL; ++_garbage_node_iter) {
        Graph_Node* _garbage = *(_garbage_node_iter);
        delete _garbage;
    }

    LinkedList<Graph_Edge*>::iterator _garbage_edge_iter = _edges.begin();
    for(; *_garbage_edge_iter != NULL; ++_garbage_edge_iter) {
        Graph_Edge* _garbage = *(_garbage_edge_iter);
        delete _garbage;
    }
}

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node *node = new Graph_Node(node_key);
    _nodes.push_back(node);
    node->_graph_pos = &_nodes.end();
    return *(_nodes.end());
};


void Dynamic_Graph::Delete_Node(Graph_Node* node) {
    if (node->Get_in_Degree() == 0 && node->Get_out_Degree() == 0) {
        _nodes.erase(node->_graph_pos);
        delete node;
    }
};

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    Graph_Edge *edge = new Graph_Edge(from, to);

    from->_out_nodes->push_back(to);
    to->_in_nodes->push_back(from);

    edge->_start_adj_iterator = &(from->_out_nodes->end());
    edge->_end_adj_iterator = &(to->_in_nodes->end());

    _edges.push_back(edge);

    edge->_graph_pos = &_edges.end();

    return edge;
};

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {
    edge->_start->_out_nodes->erase(edge->_start_adj_iterator);
    edge->_end->_in_nodes->erase(edge->_end_adj_iterator);
    _edges.erase(edge->_graph_pos);
    delete edge;
}

void Dynamic_Graph::_dfs_visit(Stack<Graph_Node*> *_stack, Graph_Node* node) const {
    node->_color = GRAY;
    LinkedList<Graph_Node*>::iterator v = node->_out_nodes->end();
    for (; *v != NULL; --v) {
        Graph_Node *adj = *v;
        if (adj->_color == WHITE) {
            _dfs_visit(_stack, adj);
        }
    }
    node->_color = BLACK;
    _stack->push(node);
}

void Dynamic_Graph::_dfs_unvisit(Graph_Node* node, Tree_Node* _scc_tree_node) const {
    node->_color = GRAY;
    LinkedList<Graph_Node*>::iterator v = node->_out_nodes->end();
    for (; *v != NULL; --v) {
        Graph_Node *adj = *v;
        if(adj->_color == BLACK) {
            Tree_Node * _scc_component_node = _scc_tree_node->append_child(adj->_id);
            _dfs_unvisit(adj, _scc_component_node);
        }
    }
    node->_color = WHITE;
}

Rooted_Tree* Dynamic_Graph::SCC() const {
    Tree_Node *_root = new Tree_Node(0);
    Rooted_Tree *_scc = new Rooted_Tree(_root);

    Stack<Graph_Node*> S;

    // Initialize the graph nodes
    // O(N)
    for (LinkedList<Graph_Node*>::iterator v = _nodes.begin(); *v != NULL; ++v) {
        (*v)->_color = WHITE;
    }

    // First DFS traversal
    // DFS: O(N+M)
    for (LinkedList<Graph_Node*>::iterator u = _nodes.end(); *u != NULL; --u) {
        Graph_Node *node = *u;
        if( node->_color == WHITE){
            this->_dfs_visit(&S, node);
        }
    }

    // Transpose the graph
    // O(N+M)
    transpose();

    // DFS on the transposed graph
    // DFS: O(N+M)
    while(!S.empty()) {
        Graph_Node *v = S.top();
        if (v->_color == BLACK) {
            Tree_Node *_scc_root = _root->append_child(v->_id);
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
    for (LinkedList<Graph_Edge *>::iterator e = _edges.begin(); *e != NULL; ++e) {
        Graph_Edge *edge = *e;
        edge->transpose();
    }

    // O(N)
    for (LinkedList<Graph_Node *>::iterator v = _nodes.begin(); *v != NULL; ++v) {
        Graph_Node *node = *v;
        node->transpose();
    }
}

Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
        Tree_Node * _bfs_tree_root = new Tree_Node(source->_id);
        Rooted_Tree *_bfs_tree = new Rooted_Tree(_bfs_tree_root);

        Queue<Graph_Node*> Q;
        Queue<Tree_Node*> Q_tree;

        // O(N)
        for (LinkedList<Graph_Node*>::iterator v = _nodes.begin(); *v != NULL; ++v) {
            (*v)->_color = WHITE;
        }

        source->_color = GRAY;

        // Enqueue
        Q.enqueue(source);
        Q_tree.enqueue(_bfs_tree_root);

        // O(N+M)
        while(!Q.empty()) {
            // Dequeue
            Graph_Node * u = Q.front();
            Q.dequeue();

            Tree_Node *u_tree = Q_tree.front();
            Q_tree.dequeue();

            LinkedList<Graph_Node*>::iterator v = u->_out_nodes->end();
            // O(Adj(u))
            for (; *v != NULL; --v) {
                Graph_Node *node = *v;
                if( node->_color == WHITE){
                    node->_color = GRAY;
                    Q.enqueue(node);

                    // Add the child to the BFS tree
                    Tree_Node * _bfs_tree_child = new Tree_Node(node->_id);
                    _bfs_tree_child->set_parent(u_tree);
                    u_tree->append_child(_bfs_tree_child);
                    Q_tree.enqueue(_bfs_tree_child);
                }
            }
            u->_color = BLACK;
        }

        return _bfs_tree;
    };