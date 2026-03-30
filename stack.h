#ifndef STACK_H
#define STACK_H

#include "dataInterface.h"
template <typename T>
class stack : public dataInterface<T> {
public:
    stack();
    stack(int count);
    stack(int count, const T& value);
    T& front();
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    ~stack();
    int size=0;
    bool empty();
    int getSize();
    T& getElement(int index);
    QString combineQString();
private:
    struct nodeT {
        nodeT* next;
        nodeT* prev;
        T data;
    };
    nodeT* head;
    nodeT* tail;
};

#endif // STACK_H
#include "datainterface.h"
#include <QString>

