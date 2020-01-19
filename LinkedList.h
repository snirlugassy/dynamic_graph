//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LINKEDLIST_H
#define DS_ALGS_CODING_HW_LINKEDLIST_H

#include "stddef.h"
#include "ListItem.h"

template <typename T>
class LinkedList {

public:
    typedef ListItem<T> iterator;
    typedef const ListItem<T> const_iterator;

    LinkedList() {};

    virtual ~LinkedList() {
        while (_first != _last) {
            pop_back();
        }
        if (_first != NULL)
            delete _first;
    };

    bool empty() const {
        return _first == NULL && _last == NULL;
    };

    void push_back(T &item) {
        ListItem<T> *_item = new ListItem<T>();
        _item->item = &item;

        // in case the list is empty
        if (_first == NULL) {
            _first = _item;
            _last = _item;
        } else {
            // the new first is the prev of the old first
            _last->next = _item;
            // the next of the new first is the old first
            _item->prev = _last;

            if(_first == _last) {
                _first->next = _item;
            }

            _last = _item;
        }
        _length++;
    };

    void pop_back() {
        if (_last != NULL) {
            iterator * _new_last = _last->prev;
            delete _last;
            _last = _new_last;
            _last->next = NULL;
            _length--;
        }
    }

    void pop_front() {
        if (_first != NULL) {
            iterator * _new_first = _first->next;
            delete _first;
            _first = _new_first;
            _first->prev = NULL;
            _length--;
        }
    }

    void erase(iterator *item) {
        if (item->prev != NULL)
            item->prev->next = item->next;
        if (item->next != NULL)
            item->next->prev = item->prev;
        delete item;
        _length--;
    }

    void insert_after(iterator &item);

    void insert_before(iterator &item);

    iterator& begin() const { return *_first; };
    iterator& end() const { return *_last; };


    unsigned int length() const {
        return _length;
    };

    LinkedList<T>& operator=(LinkedList<T>& other) {
        this->_last = other._last;
        this->_first = other._first;
        this->_length = other._length;
        return *this;
    }

private:
    iterator *_first = NULL;
    iterator *_last = NULL;
    unsigned _length = 0;
};


#endif //DS_ALGS_CODING_HW_LINKEDLIST_H
