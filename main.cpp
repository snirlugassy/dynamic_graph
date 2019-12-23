#include <iostream>
#include "Graph_Edge.h"
#include "Graph_Node.h"
#include "Rooted_Tree.h"
#include "Tree_Node.h"
#include "LinkedList.h"

int main() {
    Tree_Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
    n1.set_child(&n2);
    n2.set_child(&n3);
    n2.set_sibling(&n4);
    n4.set_child(&n6);
    n4.set_sibling(&n5);
    n6.set_sibling(&n7);
    n7.set_sibling(&n8);

    Rooted_Tree tree(&n1);
    tree.Print_By_Layer(std::cout);

    std::cout << "\n\nLinked list:" << std::endl;

    LinkedList<int> list;
    int a=1, b=5, c=7, d=13;
    list.push_back(&a);
    std::cout << *list.begin() << std::endl;
    list.push_back(&b);
    std::cout << *list.begin() << std::endl;
    list.pop_back();
    std::cout << *list.begin() << std::endl;
    list.push_back(&c);
    std::cout << *list.begin() << std::endl;
    list.pop_back();
    std::cout << *list.begin() << std::endl;


    return 0;
}