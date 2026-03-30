#include "stack.h"
#include <stdexcept>

template <typename T>
stack<T>::stack() : head(nullptr), tail(nullptr) {}

template<typename T>
stack<T>::stack(int count){
    nodeT* curr=new nodeT;
    curr->prev=nullptr;
    for(int i=0; i<count;i++){
        curr->next=new nodeT;
        curr=curr->next;
    }
    delete curr;
};

template<typename T>
stack<T>::stack(int count, const T& value){
    nodeT* curr=new nodeT;
    curr->prev=nullptr;
    for(int i=0; i<count;i++){
        curr->next=new nodeT;
        curr->data=value;
        curr=curr->next;
    }
    curr->next=nullptr;
}


template<typename T>
stack<T>::~stack() {
    nodeT* temp;
    while (head != nullptr) {
        temp=head;
        head=head->next;
        delete temp;
    }
}

template<typename T>
T& stack<T>::front(){
    if (this->head != nullptr) {
        return this->head->data;}
} //ссылка на первый эл

template<typename T>
T& stack<T>::back(){
    return this->tail->data;
} //на ласт

template<typename T>
void stack<T>::push_front(const T& value){
    nodeT* newNode = new nodeT;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = this->head;

    if (this->head != nullptr) {
        this->head->prev = newNode;
    } else {
        this->tail = newNode;
    }
    this->head = newNode;
    this->size+=1;
}

template <typename T>
void stack<T>::push_back(const T& value) {
    nodeT* newNode = new nodeT;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = this->tail;

    if (this->tail != nullptr) {
        this->tail->next = newNode;
    } else {
        this->head = newNode;
    }
    this->tail = newNode;
    this->size+=1;
}//пушим в ass

template<typename T>
void stack<T>::pop_front(){
    if (this->head == nullptr) {
        return;
    }
    nodeT* temp=this->head->next;;
    delete this->head;
    this->head=temp;
    this->head->prev=nullptr;
    size-=1;
}

template <typename T>
void stack<T>::pop_back() {
    if (this->tail == nullptr) {
        return;
    }

    nodeT* temp = this->tail->prev;
    delete this->tail;
    this->tail = temp;

    if (this->tail != nullptr) {
        this->tail->next = nullptr;
    } else {
        this->head = nullptr;
    }

    this->size -= 1;
}


template<typename T>
bool stack<T>::empty() {
    return this->head == nullptr;
}

template<typename T>
int stack<T>::getSize(){
    return size;
}

template<typename T>
T& stack<T>::getElement(int index) {
    nodeT*curr=head;
    if (index == 0 || index <= size) {
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        return curr->data;
    }
    else{
        throw std::out_of_range("getElement error");
    }
}





template class stack<QString>;
