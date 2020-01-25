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
    ListItem<T> *_first = NULL;
    ListItem<T> *_last = NULL;
    static inline ListItem<T> _null_iterator = ListItem<T>();
    unsigned _length = 0;

public:
    typedef ListItem<T> iterator;
    typedef const ListItem<T> const_iterator;

    LinkedList() {};

    virtual ~LinkedList() {
        while (_first != _last) {
            pop_back();
        }
        if (_first != NULL) {
            delete _first;
            _first = NULL;
        }
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

//        if(_first == NULL) {
//            // FIRST IS NULL
//            _first = _new_list_item;
//        } else {
//            if(_last == NULL) {
//                // FIRST IS NOT NULL AND LAST IS NULL
//                _new_list_item->prev = _first;
//                _last = _new_list_item;
//                _first->next = _last;
//            } else {
//                // FIRST AND LAND ARE NOT NULL
//                _new_list_item->prev = _last;
//                _last->next = _new_list_item;
//                _last = _new_list_item;
//            }
//        }
//
//        _length++;


        // in case the list is empty
        if (_first == NULL) {
            _first = _new_list_item;
            _last = _new_list_item;
        } else {
            // the new first is the prev of the old first
            _last->next = _new_list_item;
            // the next of the new first is the old first
            _new_list_item->prev = _last;

//            if(_first == _last) {
//                _first->next = _new_list_item;
//            }

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
                _last->next = NULL;
                _length--;
            }
        }
    }

    void pop_front() {
        if (_first != NULL) {
            if(_first == _last) {
                // LAST ITEM IN THE LIST
                clear();
            } else {
                iterator *_new_first = _first->next;
//                delete _first;
                _first = _new_first;
                _first->prev = NULL;
                _length--;
            }
        }
    }

    void erase(iterator *item) {
        if (item->prev != NULL)
            item->prev->next = item->next;
        if (item->next != NULL)
            item->next->prev = item->prev;
//        delete item;
        _length--;

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




#endif //DS_ALGS_CODING_HW_LINKEDLIST_H
