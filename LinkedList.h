//
// Created by snirlugassy on 12/20/19.
//

#ifndef DS_ALGS_CODING_HW_LINKEDLIST_H
#define DS_ALGS_CODING_HW_LINKEDLIST_H

#include "stddef.h"
#include "ListItem.h"

template <typename T>
class LinkedList {
private:
    ListItem<T> *_first;
    ListItem<T> *_last;
    static ListItem<T> _null_iterator;
    unsigned _length;

public:
    typedef ListItem<T> iterator;
    typedef const ListItem<T> const_iterator;

    LinkedList() {
        _length = 0;
        _first = NULL;
        _last = NULL;
    };

    virtual ~LinkedList() {
        while (_first != _last) {
            pop_back();
        }
        if (_first != NULL) {
            delete _first;
        }
        _first = _last = NULL;
    };

    bool empty() const {
        return _first == NULL;
    };

    void clear() {
        while (_first != _last) {
            pop_back();
        }
        if (_first != NULL) {
            delete _first;
        }
        _first = NULL;
        _last = NULL;
        _length = 0;
    }

    void push_back(T &item) {
        ListItem<T> *_new_list_item = new ListItem<T>(item);

        // in case the list is empty
        if (_first == NULL) {
            _first = _new_list_item;
            _last = _new_list_item;
        } else {
            // the new first is the prev of the old first
            _last->next = _new_list_item;
            // the next of the new first is the old first
            _new_list_item->prev = _last;

            _last = _new_list_item;
        }
        _length++;
    };

    void pop_back() {
        if (_last != NULL) {
            if (_last == _first) {
                // LAST ITEM IN THE LIST
                clear();
            } else {
                iterator * _new_last = _last->prev;
                delete _last;
                _last = _new_last;
                if (_last != NULL) {
                    _last->next = NULL;
                }
                _length--;
            }
        } else {
            clear();
        }
    }

    void pop_front() {
        if (_first != NULL) {
            if(_first == _last) {
                // LAST ITEM IN THE LIST
                clear();
            } else {
                iterator *_new_first = _first->next;
                delete _first;
                _first = _new_first;
                if (_new_first != NULL)
                    _first->prev = NULL;
                _length--;
            }
        } else {
            clear();
        }
    }

    void erase(iterator *item) {
        if (item == _first) {
            pop_front();
            return;
        }

        if (item == _last) {
            pop_back();
            return;
        }

        item->prev->next = item->next;
        item->next->prev = item->prev;
        this->_length--;
    }

    void insert_after(iterator &item);

    void insert_before(iterator &item);

    iterator& begin() const { if(_first != NULL) return *_first; return LinkedList<T>::_null_iterator; };
    iterator& end() const { if(_last != NULL) return *_last; return LinkedList<T>::_null_iterator; };


    unsigned int length() const {
        return _length;
    };

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        this->_last = other._last;
        this->_first = other._first;
        this->_length = other._length;
        return *this;
    }

    bool operator==(const LinkedList &rhs) const {
        return _last == rhs._last;
    }

    bool operator!=(const LinkedList &rhs) const {
        return !(rhs == *this);
    }
};

template <typename T>
ListItem<T> LinkedList<T>::_null_iterator = ListItem<T>();


#endif //DS_ALGS_CODING_HW_LINKEDLIST_H
