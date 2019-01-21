#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

//************
// test scenario
// TestOneItem() : only one item insert -> remove -> remove -> error처리
// TestMoreThanOneItem(): 5 item insert -> remove first -> remove last -> remove middle
//************

void testInsertOnlyOneItem(SimpleLinkedList& list)
{
    list.InsertNodeAtEnd(99);
    cout << "insert end" << endl;
    list.PrintList();
}

void testInsert5Item(SimpleLinkedList& list)
{
    list.InsertNodeAtEnd(99);
    list.InsertNodeAtEnd(55);
    list.InsertNodeAtEnd(77);
    list.InsertNodeAtEnd(33);
    list.InsertNodeAtEnd(99);
    cout << "insert end" << endl;
    list.PrintList();
}

void TestOneItem()
{
    cout << "@@@@ TestOneItem START !!!! @@@@" << endl;
    SimpleLinkedList list;
    testInsertOnlyOneItem(list);
    list.RemoveNode(0);
    list.RemoveNode(0);
    cout << "remove one item end" << endl;
    list.PrintList();
    cout << "@@@@ TestOneItem END !!!! @@@@" << endl;
}

void TestMoreThanOneItem()
{
    cout << "@@@@ TestMoreThanOneItem START !!!! @@@@" << endl;
    SimpleLinkedList list;
    testInsert5Item(list);
    list.RemoveNode(0);
    list.RemoveNode(list.GetLength()-1);
    list.RemoveNode(1);
    cout << "remove first, last, middle items end" << endl;
    list.PrintList();
    cout << "@@@@ TestMoreThanOneItem END !!!! @@@@" << endl;
}

int main ()
{
    cout << "Simple Linked List test main()" << endl;

    TestOneItem();
    TestMoreThanOneItem();

    return 0;
}