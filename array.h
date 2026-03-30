// array.h
#ifndef ARRAY_H
#define ARRAY_H

#include "datainterface.h"
#include <QString>


template <typename T>
class Array : public dataInterface<T> {
public:
    Array();
    Array(int count);
    Array(int count, const T& value);
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    ~Array();

    T& front();
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    int getSize();
    bool empty();
    T& getElement(int index);
    T& operator[](int index);
    void sort();
    void insert(int pos, const T& value);
    void erase(int pos);
private:
    T* data;
    int capacity;
    int size;
    void resize(int newCapacity);
};

#endif // ARRAY_H


