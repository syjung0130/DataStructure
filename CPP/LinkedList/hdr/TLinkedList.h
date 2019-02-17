#ifndef __TLINKEDLIST_H__
#define __TLINKEDLIST_H__

#include <iostream>
#include <cassert>
#include <string.h>

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
    
    //Capacity
    bool empty() const;
    int size() const;

    //Modifiers
    void clear();
    //TODO: 아래 메소드들은 Iterator 구현 후에
    // void insert();//TODO: iterator 구현 후에
    // iterator emplace( const_iterator pos, Args&&... args ); //TODO: iterator 구현 후에
    // iterator erase( iterator pos ); (until C++11)
    // iterator erase( const_iterator pos );(since C++11)
    // iterator erase( iterator first, iterator last );(until C++11)
    // iterator erase( const_iterator first, const_iterator last );(since C++11)
    void push_back( const T& value );
    // iterator emplace_back() //TODO: iterator 구현 후에
    void pop_back();
    void push_front( const T& value );
    void pop_front();
    void resize( int count );
    // void swap( list& other ); //(until C++17) //TODO:

    void PrintList();
    TLinkedList<T>& operator=(const TLinkedList<T>& rObj);
    // template<typename U>
    // friend TLinkedList<U>& operator=(TLinkedList<U>& lObj, const TLinkedList<U>& rObj);

    T& operator[](const int& index) const;
    template<typename U>
    friend ostream& operator<<(ostream& os, const TLinkedList<U>& tList);
    template<typename U>
    friend TLinkedList<U>& operator<<(TLinkedList<U>& tList, const U& item);

private:
    int mLength;
    TNODE<T> *m_pHead;

    TNODE<T> *CreateNode();
    virtual void InsertNodeAtEnd(const T& data);
    virtual void RemoveNode(int index);
    TNODE<T> *GetNode(const int& index) const;
    void copyNode(TNODE<T> *destNode, TNODE<T> *srcNODE);
    int GetLength() const;
    void IncreaseLength();
    void DecreaseLength();
    virtual void RemoveAllNodes();
};

template<typename T>
TLinkedList<T>::TLinkedList()
 :mLength(0),
 m_pHead(nullptr)
{
    cout << "TLinkedList()" << endl;
}

template<typename T>
TLinkedList<T>::~TLinkedList()
{
    cout << "~TLinkedList()" << endl;
    RemoveAllNodes();
}

template<typename T>
bool TLinkedList<T>::empty() const
{
    if(GetLength() > 0) 
    {
        return false;
    }
    else 
    {
        return true;
    }
}

template<typename T>
int TLinkedList<T>::size() const
{
    return GetLength();
}

template<typename T>
void TLinkedList<T>::clear()
{
    RemoveAllNodes();
}

template<typename T>
void TLinkedList<T>::push_back(const T& value)
{
    InsertNodeAtEnd(value);
}

template<typename T>
void TLinkedList<T>::pop_back()
{
    // assert(size() > 0);//if empty, exit program
    RemoveNode(GetLength()-1);
}

template<typename T>
void TLinkedList<T>::push_front(const T& value)
{
    TNODE<T> *newNode = CreateNode();
    newNode->next = m_pHead;
    newNode->data = value;
    m_pHead = newNode;
    IncreaseLength();
}

template<typename T>
void TLinkedList<T>::pop_front()
{
    assert(size() > 0);//if empty, exit program
    RemoveNode(0);
}

template<typename T>
void TLinkedList<T>::resize(int count)
{
    if (count > size())
    {
        while(count > size())
        {
            T nullValue = NULL;
            push_back(nullValue);
        }
    }
    else if(count < size())
    {
        int removeCount = size() - count;
        for(int i = 0; i < removeCount; i++)
        {
            pop_back();
        }
    }
    else
    {
        return;
    }
}

//(until C++17)
// template<typename T>
// void TLinkedList<T>::swap( T& other )
// {

// }

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
    cout << "RemoveAllNodes() size: " << GetLength() << endl;
    if (GetLength() == 0) 
    {
        return;
    }
    TNODE<T> *pCur = m_pHead;
    TNODE<T> *pTempNode = pCur;
    while (pCur->next != nullptr)
    {
        pTempNode = pCur;
        pCur = pCur->next;
        printf("RemoveAllNodes(): free momory - cur(0x%2X), tempNode(0x%2X), data(%d)\n", pCur, pTempNode, pTempNode->data);
        delete pTempNode;
        DecreaseLength();
    }
    printf("RemoveAllNodes(): free momory - addr(0x%2X), data(%d)\n", pCur, pCur->data);
    delete pCur;
    DecreaseLength();
}

template<typename T>
void TLinkedList<T>::InsertNodeAtEnd(const T& data)
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
    TNODE<T> *pTempNode = m_pHead;

    cout << "TLinkedList::RemoveNode()" << endl;
    
    if(index > GetLength()-1)
    {
        cout << "Invalid index parameter !!!!" << endl;
        return;
    }

    // 삭제할 노드가 하나 뿐일 경우
    if(GetLength() == 1)
    {
        delete m_pHead;
        m_pHead = nullptr;
        DecreaseLength();
        return;
    }
    DecreaseLength();

    // 첫번째 노드를 삭제할 경우
    if(index == 0)
    {
        TNODE<T> *pBeRemovedNode = m_pHead;
        m_pHead = pBeRemovedNode->next;        
        delete pBeRemovedNode;
        return;
    }

    // 삭제할 인덱스 바로 전 노드까지 이동
    for(int i = 0; i < index-1; i++)
    {
        pTempNode = pTempNode->next;
    }
    TNODE<T> *pBeRemovedNode = pTempNode->next;
    pTempNode->next = pBeRemovedNode->next;
    delete pBeRemovedNode;
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
    if(pNODE == nullptr || GetLength() == 0)
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
TLinkedList<T>& TLinkedList<T>::operator=(const TLinkedList<T>& rObj)
{
    cout << "[TLinkedList::operator=()] lLength, rLength: " << this->mLength << ", " << rObj.size() << endl;
    for (int i = 0; i < rObj.size(); i++)
    {
        this->push_back(rObj[i]);
    }

    return *this;
}

template<typename T>
T& TLinkedList<T>::operator[](const int& index) const
{
    // cout << "operator[](): " << index << endl;
    TNODE<T>* targetNode = GetNode(index);
    return targetNode->data;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const TLinkedList<T>& tList)
{
    TNODE<T> *pNODE = tList.m_pHead;

    while(pNODE != nullptr)
    {
        os << fixed << pNODE->data << endl;
        pNODE = pNODE->next;
    }
    return os;
}

template<typename T>
TLinkedList<T>& operator<<(TLinkedList<T>& tList, const T& item)
{
    tList.push_back(item);
    return tList;
}

template<typename T>
TNODE<T>* TLinkedList<T>::GetNode(const int& index) const
{
    TNODE<T>* curNode = m_pHead;
    for(int i = 0; i < index; i++)
    {
        curNode = curNode->next;
    }
    return curNode;
}

template<typename T>
int TLinkedList<T>::GetLength() const
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