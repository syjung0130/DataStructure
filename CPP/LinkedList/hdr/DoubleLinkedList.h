#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

typedef struct DLIST_NODE {
    int data;
    DLIST_NODE *next;
    DLIST_NODE *prev;
}DLIST_NODE;

class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    DLIST_NODE *CreateNode();
    void InsertNodeAtEnd(int data);
    void RemoveNode(int index);
    void copyNode(DLIST_NODE *destNode, DLIST_NODE *srcNODE);
    void PrintList();
    int GetLength();
    void IncreaseLength();
    void DecreaseLength();

    // 추후에는 위 메서드들을 private으로 옮기고
    // std::list의 insert(), erase()메서드를 구현해보고 
    //[]연산자 오버로딩까지 해보자
private:
    DLIST_NODE *m_pHead;
    int mLength;
};

#endif