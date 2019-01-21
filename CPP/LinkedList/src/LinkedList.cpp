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