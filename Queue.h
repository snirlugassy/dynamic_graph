//
// Created by snirlugassy on 1/19/20.
//

#ifndef DS_ALGS_CODING_HW_QUEUE_H
#define DS_ALGS_CODING_HW_QUEUE_H

#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> *_list;
public:
    Queue<T>() {
        _list = new LinkedList<T>();
    }

    ~Queue<T> () {
        delete _list;
    }

    void enqueue(T& item) {
        _list->push_back(item);
    }

    void dequeue() {
        _list->pop_front();
    }

    T front() {
        return *(_list->begin());
    }

    bool empty () {
        return _list->empty();
    }

};


#endif //DS_ALGS_CODING_HW_QUEUE_H
