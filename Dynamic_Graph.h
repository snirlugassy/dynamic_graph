//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_DYNAMIC_GRAPH_H
#define DS_ALGS_CODING_HW_DYNAMIC_GRAPH_H

#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"
#include "LinkedList.h"
#include "typedefs.h"
#include "Queue.h"
#include "Stack.h"

class Dynamic_Graph {
private:
    NodeList _nodes;
    EdgeList _edges;
    void _dfs_visit(Stack<Graph_Node*> *_stack, Graph_Node* node) const;
    void _dfs_unvisit(Graph_Node* node, Tree_Node* _scc_tree_node) const;
    void _dfs();
    void transpose() const;
public:
    Dynamic_Graph() {};
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    Rooted_Tree* BFS(Graph_Node* source) const;
};


#endif //DS_ALGS_CODING_HW_DYNAMIC_GRAPH_H
