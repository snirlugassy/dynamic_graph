//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LINKEDLIST_H
#define DS_ALGS_CODING_HW_LINKEDLIST_H

#include "ListNode.h"

template <typename T>
class LinkedList {
private:
    ListNode<T> *_first = nullptr;
    ListNode<T> *_last = nullptr;
    unsigned _length = 0;
public:
    LinkedList();
    virtual ~LinkedList();
    LinkedList(T &element);
    bool empty();
    void push_back(T &element);
    void push_front(T &element);
    void pop_back();
    void pop_front();
    void remove(ListNode<T> *node);
    void insert_after(ListNode<T> *node);
    void insert_before(ListNode<T> *node);
    T* begin();
    T* end();
    unsigned int length();
};

template <typename T>
LinkedList<T>::LinkedList() {};

template <typename T>
LinkedList<T>::LinkedList(T &element) {
    ListNode<T> *node = new ListNode(element);
    this->_first = node;
    this->_last = node;
};

template <typename T>
bool LinkedList<T>::empty() {
    return this->_first == nullptr && this->_last == nullptr;
};

template <typename T>
void LinkedList<T>::push_back(T &element) {
    ListNode<T> *node = new ListNode<T>(element);
    if (this->_last == nullptr)
        // in case the list is empty
        this->_last = node;
    if (this->_first != nullptr){
        // the new first is the prev of the old first
        this->_first->prev = node;
        // the next of the new first is the old first
        node->next = this->_first;
    }
    this->_first = node;
    this->_length++;
};

template <typename T>
void LinkedList<T>::push_front(T &element) {
    ListNode<T> *node = new ListNode<T>(element);
    if (this->_first == nullptr)
        // in case the list is empty
        this->_first = node;
    if (this->_last != nullptr) {
        // the new last is the next of the old last
        this->_last->next = node;
        // the prev of the new last is the old last
        node->prev = this->_last;
    }
    this->_last = node;
    this->_length++;
};

template <typename T>
void LinkedList<T>::pop_back() {
    if (this->_first != nullptr && this->_last != nullptr) {
        ListNode<T> *_temp = this->_first;
        this->_first = this->_first->next;
        delete _temp;
        this->_length--;
    }
};

template <typename T>
void LinkedList<T>::pop_front() {
    if (this->_first != nullptr && this->_last != nullptr) {
        ListNode<T> *_temp = this->_last;
        this->_last = this->_last->prev;
        delete _temp;
        this->_length--;
    }
};

template <typename T>
void LinkedList<T>::remove(ListNode<T> *node) {
    if (node->prev != nullptr) {
        // might be null
        node->prev->next = node->next;
    }
    if (node->next != nullptr) {
        // might be null
        node->next->prev = node->prev;
    }
    delete node;
};

template <typename T>
T* LinkedList<T>::begin() {
    if (this->_first != nullptr)
        return this->_first->element;
    return nullptr;
};

template <typename T>
T* LinkedList<T>::end() {
    if (this->_last != nullptr)
        return this->_last.element;
    return nullptr;
};

template <typename T>
unsigned int LinkedList<T>::length() {
    return this->_length;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while(!this->empty())
        pop_back();
};

#endif //DS_ALGS_CODING_HW_LINKEDLIST_H
