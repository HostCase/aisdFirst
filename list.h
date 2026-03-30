#ifndef LIST_H
#define LIST_H

#include "datainterface.h"
#include <QString>

template <typename T>
class list : public dataInterface<T> {
public:
    list();
    list(int count);
    list(int count, const T& value);
    T& front();
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    ~list();
    bool empty();
    int getSize();
    T& getElement(int index);
    void insert(int pos, const T& value);
    void erase(int pos);
private:
    struct nodeT {
        nodeT* next;
        nodeT* prev;
        T data;
    };
    nodeT* head;
    nodeT* tail;
    int size=0;
};

#endif // LIST_H

// ( - 7 + 1 ) ^3 / 2
