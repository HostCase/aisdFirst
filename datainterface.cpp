#include "datainterface.h"
#include <QString>
template <typename T>
dataInterface<T>::dataInterface() {}

template <typename T>
dataInterface<T>::~dataInterface() {}
template <typename T>
T& dataInterface<T>::front() {

}

template <typename T>
T& dataInterface<T>::back() {
}


template <typename T>
void dataInterface<T>::push_front(const T& value) {

}

template <typename T>
void dataInterface<T>::push_back(const T& value) {

}

template <typename T>
void dataInterface<T>::pop_front() {

}

template <typename T>
void dataInterface<T>::pop_back() {

}

template <typename T>
void dataInterface<T>::erase(int i) {

}


template <typename T>
bool dataInterface<T>::empty() {

}

template <typename T>
int dataInterface<T>::getSize() {

}

template <typename T>
T& dataInterface<T>::getElement(int index){

}

template <typename T>
void dataInterface<T>::sort(){

}



template <typename T>
void dataInterface<T>::insert(int pos, const T& value){

}


template class dataInterface<int>;
template class dataInterface<QString>;
