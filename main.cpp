#include <iostream>
#include "Graph_Edge.h"
#include "Graph_Node.h"
#include "Rooted_Tree.h"
#include "Tree_Node.h"
#include "LinkedList.h"
#include "Dynamic_Graph.h"

int main() {
    Dynamic_Graph DG;

    Graph_Node *one = DG.Insert_Node(1);
    Graph_Node *two = DG.Insert_Node(2);
    Graph_Node *three = DG.Insert_Node(3);
    Graph_Node *four = DG.Insert_Node(4);

    DG.Delete_Node(one);
    DG.Delete_Node(three);

//    Tree_Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
//    n1.set_child(&n2);
//    n2.set_child(&n3);
//    n2.set_sibling(&n4);
//    n4.set_child(&n6);
//    n4.set_sibling(&n5);
//    n6.set_sibling(&n7);
//    n7.set_sibling(&n8);
//
//    Rooted_Tree tree(&n1);
//    tree.Print_By_Layer(std::cout);


    std::cout << "Linked list:" << std::endl;
    LinkedList<Graph_Node> list;
    Graph_Node *n = new Graph_Node(1);
    list.push_back(*n);
    Graph_Node * fir = list.begin();
    list.remove(fir);
    std::cout << fir->Get_key() << std::endl;
    list.pop_back();
    Graph_Node g = Graph_Node(5);
    list.push_back(g);
    return 0;
}