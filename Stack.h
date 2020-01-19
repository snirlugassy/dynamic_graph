//
// Created by snirlugassy on 1/19/20.
//

#ifndef DS_ALGS_CODING_HW_STACK_H
#define DS_ALGS_CODING_HW_STACK_H

template <typename T>
class Stack {
private:
    LinkedList<T> *_list;
public:
    Stack<T>() {
        _list = new LinkedList<T>();
    }

    ~Stack<T> () {
        delete _list;
    }

    void push(T& item) {
        _list->push_back(item);
    }

    void pop() {
        _list->pop_back();
    }

    T top() {
        return *(_list->end());
    }

    bool empty () {
        return _list->empty();
    }

};


#endif //DS_ALGS_CODING_HW_STACK_H
