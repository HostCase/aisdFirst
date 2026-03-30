#include "list.h"
#include <stdexcept>

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr) {}

template<typename T>
list<T>::list(int count){
    nodeT* curr=new nodeT;
    curr->prev=nullptr;
    for(int i=0; i<count;i++){
        curr->next=new nodeT;
        curr=curr->next;
    }
    delete curr;
};

template<typename T>
list<T>::list(int count, const T& value){
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
list<T>::~list() {
    nodeT* temp;
    while (head != nullptr) {
        temp=head;
        head=head->next;
        delete temp;
    }
}

template<typename T>
T& list<T>::front(){
    if (this->head != nullptr) {
        return this->head->data;}
} //ссылка на первый эл

template<typename T>
T& list<T>::back(){
    return this->tail->data;
} //на ласт

template<typename T>
void list<T>::push_front(const T& value){
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
void list<T>::push_back(const T& value) {
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
void list<T>::pop_front() {
    if (this->head == nullptr) {
        return;
    }

    nodeT* temp = this->head->next;
    delete this->head;
    this->head = temp;

    if (this->head != nullptr) {
        this->head->prev = nullptr;
    } else {
        this->tail = nullptr;
    }

    this->size -= 1;
}


template <typename T>
void list<T>::pop_back() {
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
//последний

template<typename T>
bool list<T>::empty() {
    return this->head == nullptr;
}

template<typename T>
int list<T>::getSize(){
    return size;
}

template<typename T>
T& list<T>::getElement(int index) {
    nodeT*curr=head;
    if (index >= 0 && index < size) { // тут был or mb вернуть
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        return curr->data;
    }
    else{
        throw std::out_of_range("getElement error");
    }
}


template<typename T>
void list<T>::insert(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Insert list error");
    }

    nodeT* newNode = new nodeT;
    newNode->data = value;

    if (index == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    } else if (index == size) {
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
    } else {
        nodeT* curr;
        if (index > size / 2) {
            curr = tail;
            for (int i = size; i > index; i--) {
                curr = curr->prev;
            }
        } else {
            curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
        }

        newNode->next = curr;
        newNode->prev = curr->prev;
        if (curr->prev != nullptr) {
            curr->prev->next = newNode;
        }
        curr->prev = newNode;
    }

    size+=1;
}


template<typename T>
void list<T>::erase(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Erase list error");
    }
    nodeT* curr = head;

    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }

    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    } else {
        head = curr->next;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    } else {

        tail = curr->prev;
    }
    delete curr;
    size--;
}






template class list<int>;
template class list<QString>;
