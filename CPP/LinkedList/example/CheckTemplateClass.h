#ifndef __CHECKTEMPLATECLASS_H__
#define __CHECKTEMPLATECLASS_H__

#include <iostream>
using namespace std;

template<typename T>
class MyMath
{
public:
    MyMath(){};
    T sum(T op1, T op2);
};

template<typename T>
T MyMath<T>::sum(T op1, T op2)
{
    return op1+op2;
}

template <typename T>
class NODE
{
    T data;
    NODE *next;
};

template<typename T>
class MyList
{
public:
    MyList();
    NODE<T>* createNode();

private:
    NODE<T> *pHead;
};

template<typename T>
MyList<T>::MyList()
 :pHead(nullptr)
{
}

template<typename T>
NODE<T>* MyList<T>::createNode()
{
    NODE<T> *node = new NODE<T>();
    if(pHead == nullptr)
    {
        cout << "[MyList::createNode()] first node" << endl;
        pHead = node;
    }
    cout << "[MyList::createNode()] create node" << endl;
    return node;
}

#endif