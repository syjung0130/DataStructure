#include "SimpleLinkedList.h"
#include <iostream>

using namespace std;

SimpleLinkedList::SimpleLinkedList()
:m_pHead(NULL),
 mLength(0)
{
    cout << "SimpleLinkedList()" << endl;
}

SimpleLinkedList::~SimpleLinkedList()
{
    cout << "~SimpleLinkedList()" << endl;
    if (GetLength() == 0) {
        return;
    }
    while (m_pHead->next != NULL)
    {
        printf("~SimpleLinkedList: free momory - addr(0x%2X), data(%d)\n", m_pHead, m_pHead->data);
        NODE *tempNode = m_pHead;
        m_pHead = m_pHead->next;
        free(tempNode);
    }
}

NODE* SimpleLinkedList::CreateNode()
{
    cout << "SimpleLinkedList::CreateNode()" << endl;
    NODE *pNODE = (NODE *)malloc(sizeof(NODE));
    pNODE->next = NULL;
    pNODE->data = 0;
    
    return pNODE;
}

void SimpleLinkedList::InsertNodeAtEnd(int data)
{
    NODE *pNODE = CreateNode();
    pNODE->data = data;

    cout << "SimpleLinkedList::InsertNodeAtEnd()" << endl;

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
    }
    IncreaseLength();
}

void SimpleLinkedList::RemoveNode(int index)
{
    NODE *pTempNode = m_pHead;

    cout << "SimpleLinkedList::RemoveNode()" << endl;
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
        free(pBeRemovedNode);
        return;
    }

    // 삭제할 인덱스 바로 전 노드까지 이동
    for(int i = 0; i < index-1; i++)
    {
        pTempNode = pTempNode->next;
    }
    NODE *pBeRemovedNode = pTempNode->next;
    pTempNode->next = pBeRemovedNode->next;
    free(pBeRemovedNode);
}

void SimpleLinkedList::copyNode(NODE *destNode, NODE *srcNode)
{
    // swallow copy.. if using name member, need to deepcopy
    memcpy(destNode, srcNode, sizeof(NODE));
}

void SimpleLinkedList::PrintList()
{
    NODE *pNODE = m_pHead;
    cout << "SimpleLinkedList::PrintList()" << endl;
    if(pNODE == NULL)
    {
        cout << "List element is not exist !!!!!" <<endl;
        return;
    }
    cout << "#### List Items ####" << endl;
    while(pNODE != NULL)
    {
        cout << pNODE->data << endl;
        pNODE = pNODE->next;
    }
    cout << "####################" << endl;
}

int SimpleLinkedList::GetLength()
{
    return mLength;
}

void SimpleLinkedList::IncreaseLength()
{
    mLength++;
}

void SimpleLinkedList::DecreaseLength()
{
    mLength--;
}