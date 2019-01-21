#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

namespace sy {
namespace list {

typedef struct NODE 
{
    int data;
    NODE *next;
    NODE *prev;
}NODE;

class LinkedList 
{
public:
    LinkedList();
    virtual ~LinkedList(){}
    virtual void *CreateNode() = 0;
    virtual void InsertNodeAtEnd(int data) = 0;
    virtual void RemoveNode(int index) = 0;
    void copyNode(NODE *destNode, NODE *srcNODE);
    void PrintList();
    int GetLength();
    void IncreaseLength();
    void DecreaseLength();

    // 추후에는 위 메서드들을 private으로 옮기고
    // std::list의 insert(), erase()메서드를 구현해보고 
    //[]연산자 오버로딩까지 해보자
private:
    int mLength;
protected:
    NODE *m_pHead;
};

}//list
}//sy

#endif