#include "array.h"


template <typename T>
Array<T>::Array() : data(nullptr), capacity(0), size(0) {}

template <typename T>
Array<T>::Array(int size) : capacity(size), size(size) {
    data = new T[size];
}


template <typename T>
Array<T>::Array(int size, const T& value) : capacity(size), size(size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = value;
    }
}

template <typename T>
Array<T>::Array(const Array<T>& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}



template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::front() {
    if (empty()) throw std::out_of_range("Array is empty");
    return data[0];
}




template <typename T>
T& Array<T>::back() {
    if (empty()) throw std::out_of_range("Array is empty");
    return data[size - 1];
}



template <typename T>
void Array<T>::push_back(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void Array<T>::push_front(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    for (int i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    ++size;
}



template <typename T>
void Array<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Array is empty");
    }
    --size;
}


template <typename T>
void Array<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Array is empty");
    }
    for (int i = 0; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}





template <typename T>
bool Array<T>::empty() {
    return size==0;
}

template<typename T>
T& Array<T>::getElement(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}


template <typename T>
T& Array<T>::operator[](int index) {
    return getElement(index);
}


template <typename T>
int Array<T>::getSize()
{
    return size;
}

template <typename T>
void Array<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}


template <typename T>
void Array<T>::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}



template <typename T>
void Array<T>::insert(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }


    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }


    for (int i = size; i > index; --i) {
        data[i] = data[i - 1];
    }


    data[index] = value;
    size+=1;
}

template <typename T>
void Array<T>::erase(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }


    --size;

}



template class Array<QString>;
