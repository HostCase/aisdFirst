#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <qcontainerfwd.h>
#include <vector>
template<typename T>
class dataInterface
{
public:
    dataInterface();
    virtual ~dataInterface<T>();
    T& front(); //ссылка на первый эл
    T& back(); //на ласт
    virtual void push_front(const T& value);//пушим в 0
    virtual void push_back(const T& value);//пушим в ass
    virtual void pop_front();
    virtual void pop_back();
    virtual void insert(int pos, const T& value);//вставка
    virtual void erase(int pos);
    virtual int getSize();//размерность
    virtual bool empty();//? пустой
    virtual T& getElement(int index);
    virtual void sort();

private:
    int size=0;
};


#endif // DATAINTERFACE_H
