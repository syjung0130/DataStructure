#ifndef __SIMPLELINKEDLIST_H__
#define __SIMPLELINKEDLIST_H__

// const unsigned int NAME_LENGTH = 20;

typedef struct NODE {
    int data;
    // char name[NAME_LENGTH];
    NODE *next;
}NODE;

class SimpleLinkedList {
public:
    SimpleLinkedList();
    ~SimpleLinkedList();
    NODE *CreateNode();
    void InsertNodeAtEnd(int data);
    void RemoveNode(int index);
    void copyNode(NODE *destNode, NODE *srcNODE);
    void PrintList();
    int GetLength();

    // 추후에는 위 메서드들을 private으로 옮기고
    // std::list의 insert(), erase()메서드를 구현해보고 
    //[]연산자 오버로딩까지 해보자
private:
    NODE *m_pHead;
    int mLength;
};

#endif