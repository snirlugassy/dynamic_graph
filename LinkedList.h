//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LINKEDLIST_H
#define DS_ALGS_CODING_HW_LINKEDLIST_H

#include "stddef.h"


template <typename T>
class LinkedList {
private:
    T* _first = NULL;
    T* _last = NULL;
    unsigned _length = 0;
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    LinkedList();
    virtual ~LinkedList();
    bool empty() const;
    void push_back(T &element);
    void push_front(T &element);
    void pop_back();
    void pop_front();
    void remove(ListItem<T> *node);
    void insert_after(ListItem<T> &item);
    void insert_before(ListItem<T> &item);
    T* begin() const;
    T* end() const;
    unsigned int length() const;
};

template <typename T>
LinkedList<T>::LinkedList() {};

template <typename T>
bool LinkedList<T>::empty() const {
    return _first == NULL && _last == NULL;
};

template <typename T>
void LinkedList<T>::push_back(T &item) {
    ListItem<T> _item = new ListItem(&item);
    if (_last == NULL)
        // in case the list is empty
        _last = _item;
    if (_first != NULL){
        // the new first is the prev of the old first
        _first->prev = _item;
        // the next of the new first is the old first
        _item->next = _first;
    }
    _first = _item;
    _length++;
};

//template <typename T>
//void LinkedList<T>::push_front(T &item) {
//    if (_first == NULL)
//        // in case the list is empty
//        _first = item;
//    if (_last != NULL) {
//        // the new last is the next of the old last
//        _last->next = item;
//        // the prev of the new last is the old last
//        item->prev = _last;
//    }
//    _last = item;
//    _length++;
//};

template <typename T>
void LinkedList<T>::pop_back() {
    if (_first != NULL) {
        T *_garbage = _first;
        _first = _first->next;
//        _garbage->prev = NULL;
//        _garbage->next = NULL;
        delete _garbage;
        _length--;
    }
};

//template <typename T>
//void LinkedList<T>::pop_front() {
//    if (_last != NULL) {
//        T *_garbage = _last;
//        _last = _last->prev;
//        _garbage->prev = NULL;
//        _garbage->next = NULL;
//        _length--;
//    }
//};

template <typename T>
void LinkedList<T>::remove(ListItem<T> *item) {
    if (_first == item)
        _first = item->next;
    if (_last == item)
        _last = item->prev;
    if (item->prev != NULL)
        item->prev->next = item->next;
    if (item->next != NULL)
        item->next->prev = item->prev;

    // decrease the length if found
    // TODO: think of a way to avoid decreasing fake nodes
    _length -= (int) (item->prev != NULL || item->next != NULL);

    delete item;
//    item->prev = NULL;
//    item->next = NULL;
};

template <typename T>
T* LinkedList<T>::begin() const {
    return _first;
};

template <typename T>
T* LinkedList<T>::end() const {
    return _last;
};

template <typename T>
unsigned int LinkedList<T>::length() const {
    return _length;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(!empty()) {
        pop_back();
        pop_front();
    }
}

//template <typename T>
//void LinkedList<T>::insert_before(T &item) {};
//
//template <typename T>
//void LinkedList<T>::insert_after(T &item) {};

#endif //DS_ALGS_CODING_HW_LINKEDLIST_H
