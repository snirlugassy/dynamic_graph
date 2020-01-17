//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LINKEDLIST_H
#define DS_ALGS_CODING_HW_LINKEDLIST_H

#include "stddef.h"

template <typename T>
class LinkedList {

public:
    typedef ListItem<T> iterator;

    typedef const ListItem<T> const_iterator;

    LinkedList() {};

    virtual ~LinkedList() {
//        while (_first != _last) {
//            iterator __temp = _first;
//            ++_first;
//            delete __temp;
//        }
//        delete _first;
    };

    bool empty() const {
        return _first == NULL && _last == NULL;
    };

    void push_back(T &item) {
        ListItem<T> *_item = new ListItem<T>();
        _item->item = &item;

        if (_last != NULL){
            // the new first is the prev of the old first
            _last.next = _item;
            // the next of the new first is the old first
            _item->prev = &_last;
        }
        _last = *_item;


        if (_first == NULL)
            // in case the list is empty
            _first = _last;

        _length++;
    };

//    void push_front(T &element);

    void pop_back();

    void pop_front();

    void remove(iterator *node);

    void insert_after(iterator &item);

    void insert_before(iterator &item);

    iterator front() const { return _first; };
    iterator back() const { return _last; };

    iterator begin() const { return _first; };
    iterator end() const { return NULL; };


    unsigned int length() const {
        return _length;
    };


private:
    iterator _first = NULL;
    iterator _last = NULL;
    unsigned _length = 0;
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

//template <typename T>
//void LinkedList<T>::pop_back() {
//    if (_first != NULL) {
//        T *_garbage = _first;
//        _first = _first->next;
////        _garbage->prev = NULL;
////        _garbage->next = NULL;
//        delete _garbage;
//        _length--;
//    }
//};

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

//template <typename T>
//void LinkedList<T>::remove(ListItem<T> *item) {
//    if (_first == item)
//        _first = item->next;
//    if (_last == item)
//        _last = item->prev;
//    if (item->prev != NULL)
//        item->prev->next = item->next;
//    if (item->next != NULL)
//        item->next->prev = item->prev;
//
//    // decrease the length if found
//    // TODO: think of a way to avoid decreasing fake nodes
//    _length -= (int) (item->prev != NULL || item->next != NULL);
//
//    delete item;
////    item->prev = NULL;
////    item->next = NULL;
//};

//
//template <typename T>
//LinkedList<T>::~LinkedList() {
//    while(!empty()) {
//        pop_back();
//        pop_front();
//    }
//}

//template <typename T>
//void LinkedList<T>::insert_before(T &item) {};
//
//template <typename T>
//void LinkedList<T>::insert_after(T &item) {};

#endif //DS_ALGS_CODING_HW_LINKEDLIST_H
