//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LISTNODE_H
#define DS_ALGS_CODING_HW_LISTNODE_H

template <typename T>
class ListNode {
public:
    ListNode(T &element);
    T element = nullptr;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
};

template <typename T>
ListNode<T>::ListNode(T &element): element(element) {};

#endif //DS_ALGS_CODING_HW_LISTNODE_H
