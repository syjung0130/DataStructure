#ifndef __TLINKEDLIST_H__
#define __TLINKEDLIST_H__

#include <iostream>

using namespace std;

namespace sy {
namespace list {

template<typename T>
class TNODE
{
public:
    T data;
    TNODE<T> *next;
};

template<typename T>
class TLinkedList 
{
public:
    TLinkedList();
    virtual ~TLinkedList();
    TNODE<T> *CreateNode();
    virtual void RemoveAllNodes();
    virtual void InsertNodeAtEnd(T data);
    virtual void RemoveNode(int index);
    void copyNode(TNODE<T> *destNode, TNODE<T> *srcNODE);
    void PrintList();
    int GetLength();
    void IncreaseLength();
    void DecreaseLength();

    // TODO:
    // 추후에는 위 메서드들을 private으로 옮기고
    // std::list의 insert(), erase()메서드를 구현해보고 
    //[]연산자 오버로딩까지 해보자
private:
    int mLength;
    TNODE<T> *m_pHead;
};

template<typename T>
TLinkedList<T>::TLinkedList()
 :mLength(0),
 m_pHead(nullptr)
{
}

template<typename T>
TLinkedList<T>::~TLinkedList()
{
}

template<typename T>
TNODE<T> *TLinkedList<T>::CreateNode()
{
    cout << "TLinkedList::CreateNode()" << endl;
    TNODE<T> *pNODE = new TNODE<T>();
    pNODE->next = nullptr;
    
    return pNODE;
}

template<typename T>
void TLinkedList<T>::RemoveAllNodes()
{

}

template<typename T>
void TLinkedList<T>::InsertNodeAtEnd(T data)
{
    TNODE<T> *pNODE = CreateNode();
    pNODE->data = data;

    cout << "TLinkedList::InsertNodeAtEnd()" << endl;

    if(m_pHead == nullptr) //if only one node existed
    {
        m_pHead = pNODE;
    }
    else // if two or more than nodes are existed
    {
        TNODE<T> *pCurrentNode = m_pHead;
        while(pCurrentNode->next != nullptr)
        {
            pCurrentNode = pCurrentNode->next;
        }
        pCurrentNode->next = pNODE;
    }
    IncreaseLength();
}


template<typename T>
void TLinkedList<T>::RemoveNode(int index)
{

}

template<typename T>
void TLinkedList<T>::copyNode(TNODE<T> *destNode, TNODE<T> *srcNODE)
{

}

template<typename T>
void TLinkedList<T>::PrintList()
{
    cout.precision(5);
    TNODE<T> *pNODE = m_pHead;
    cout << "TLinkedList::PrintList()" << endl;
    if(pNODE == nullptr)
    {
        cout << "List element is not exist !!!!!" <<endl;
        return;
    }
    cout << "#### List Items ####" << endl;
    while(pNODE != nullptr)
    {
        cout << fixed << pNODE->data << endl;
        pNODE = pNODE->next;
    }
    cout << "####################" << endl;
}

template<typename T>
int TLinkedList<T>::GetLength()
{
    return mLength;
}

template<typename T>
void TLinkedList<T>::IncreaseLength()
{
    mLength++;
}

template<typename T>
void TLinkedList<T>::DecreaseLength()
{
    mLength--;
}

}//list
}//sy

#endif