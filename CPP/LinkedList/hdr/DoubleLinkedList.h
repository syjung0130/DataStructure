#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

typedef struct NODE {
    int data;
    NODE *next;
    NODE *prev;
}NODE;

class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    NODE *CreateNode();
    void InsertNodeAtEnd(int data);
    void RemoveNode(int index);
    void copyNode(NODE *destNode, NODE *srcNODE);
    void PrintList();
    int GetLength();
    void IncreaseLength();
    void DecreaseLength();

    // 추후에는 위 메서드들을 private으로 옮기고
    // std::list의 insert(), erase()메서드를 구현해보고 
    //[]연산자 오버로딩까지 해보자
private:
    NODE *m_pHead;
    int mLength;
};

#endif