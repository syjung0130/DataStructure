#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList()
: LinkedList()
{
    cout << "DoubleLinkedList()" << endl;
}

DoubleLinkedList::~DoubleLinkedList()
{
    cout << "~DoubleLinkedList()" << endl;
    if (GetLength() == 0) 
    {
        return;
    }
    while (m_pHead->next != NULL)
    {
        printf("~DoubleLinkedList: free momory - addr(0x%2X), data(%d)\n", m_pHead, m_pHead->data);
        NODE *tempNode = m_pHead;
        m_pHead = m_pHead->next;
        free(tempNode);
    }
}

void DoubleLinkedList::InsertNodeAtEnd(int data)
{
    NODE *pNODE = (NODE *)CreateNode();
    pNODE->data = data;

    cout << "DoubleLinkedList::InsertNodeAtEnd()" << endl;

    if(m_pHead == NULL) //if only one node existed
    {
        m_pHead = pNODE;
    }
    else // if two or more than nodes are existed
    {
        NODE *pCurrentNode = m_pHead;
        while(pCurrentNode->next != NULL)
        {
            pCurrentNode = pCurrentNode->next;
        }
        pCurrentNode->next = pNODE;
        pNODE->prev = pCurrentNode;
    }
    IncreaseLength();
}

void DoubleLinkedList::RemoveNode(int index)
{
    NODE *pTempNode = m_pHead;

    cout << "DoubleLinkedList::RemoveNode()" << endl;
    DecreaseLength();
    if(index > GetLength()-1)
    {
        cout << "Invalid index parameter !!!!" << endl;
        return;
    }

    // 삭제할 노드가 하나 뿐일 경우
    if(GetLength() == 1)
    {
        free(m_pHead);
        m_pHead = NULL;
        return;
    }

    // 첫번째 노드를 삭제할 경우
    if(index == 0)
    {
        NODE *pBeRemovedNode = m_pHead;
        m_pHead = pBeRemovedNode->next;
        m_pHead->prev = NULL;        
        free(pBeRemovedNode);
        return;
    }

    // 삭제할 인덱스 바로 전 노드까지 이동
    for(int i = 0; i < index-1; i++)
    {
        pTempNode = pTempNode->next;
    }
    // 노드 삭제
    NODE *pBeRemovedNode = pTempNode->next;
    pTempNode->next = pBeRemovedNode->next;
    pBeRemovedNode->next->prev = pTempNode;
    free(pBeRemovedNode);
}
