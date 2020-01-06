#include <iostream>
#include "Dynamic_Graph.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"

#define SEED 23454
#define TEST_SIZE 30
#define INITIAL_NODES_NUM 10
#define INITIAL_EDGES_NUM 30
#define NUM_OF_OPERATIONS 8
#define INSERT_NODE 1
#define INSERT_EDGE 2
#define DELETE_NODE 3
#define DELETE_EDGE 4
#define STRONGLY_CONNECTED_COMPONENTS 5
#define RUN_BFS 6
#define OUT_DEGREE 7
#define IN_DEGREE 8


int main() {
    Dynamic_Graph DG;

    Graph_Node *one = DG.Insert_Node(1);
    Graph_Node *two = DG.Insert_Node(2);
    Graph_Node *three = DG.Insert_Node(3);
    Graph_Node *four = DG.Insert_Node(4);
    Graph_Node *five = DG.Insert_Node(5);
    Graph_Node *six = DG.Insert_Node(6);
    Graph_Node *seven = DG.Insert_Node(7);
    Graph_Node *eight = DG.Insert_Node(8);

    Graph_Edge* e1 = DG.Insert_Edge(seven, eight);
    Graph_Edge* e2 = DG.Insert_Edge(eight, seven);
    Graph_Edge* e3 = DG.Insert_Edge(seven, six);
    Graph_Edge* e4 = DG.Insert_Edge(one, six);
    Graph_Edge* e5 = DG.Insert_Edge(six, one);
    Graph_Edge* e6 =  DG.Insert_Edge(one, two);
    Graph_Edge* e7 = DG.Insert_Edge(two, three);
    Graph_Edge* e8 = DG.Insert_Edge(three, four);
    Graph_Edge* e9 = DG.Insert_Edge(three, five);
    Graph_Edge* e10 = DG.Insert_Edge(five, three);

    Rooted_Tree *T = DG.SCC();
    T->Print_By_Layer(std::cout);

//    DG.Delete_Edge(e1);
//    DG.Delete_Edge(e2);
//    DG.Delete_Edge(e3);
//    DG.Delete_Edge(e4);
//    DG.Delete_Edge(e5);
//    DG.Delete_Edge(e6);
//    DG.Delete_Edge(e7);
//    DG.Delete_Edge(e8);
//    DG.Delete_Edge(e9);
//    DG.Delete_Edge(e10);

    return 0;
}