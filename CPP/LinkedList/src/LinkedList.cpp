#include "LinkedList.h"
#include <iostream>

using namespace std;

namespace sy {
namespace list {

LinkedList::LinkedList()
: m_pHead(nullptr),
mLength(0)
{
}

NODE *LinkedList::CreateNode()
{
    cout << "SimpleLinkedList::CreateNode()" << endl;
    NODE *pNODE = (NODE *)malloc(sizeof(NODE));
    pNODE->next = NULL;
    pNODE->data = 0;
    
    return pNODE;
}

void LinkedList::RemoveAllNodes()
{
    cout << "RemoveAllNodes()" << endl;
    if (GetLength() == 0) 
    {
        return;
    }
    while (m_pHead->next != NULL)
    {
        printf("RemoveAllNodes(): free momory - addr(0x%2X), data(%d)\n", m_pHead, m_pHead->data);
        NODE *tempNode = m_pHead;
        m_pHead = m_pHead->next;
        free(tempNode);
    }
}

void LinkedList::PrintList()
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

int LinkedList::GetLength()
{
    return mLength;
}

void LinkedList::IncreaseLength()
{
    mLength++;
}

void LinkedList::DecreaseLength()
{
    mLength--;
}

void LinkedList::copyNode(NODE *destNode, NODE *srcNode)
{
    memcpy(destNode, srcNode, sizeof(NODE));
}

}
}