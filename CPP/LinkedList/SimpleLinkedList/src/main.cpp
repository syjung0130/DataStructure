#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

int main ()
{
    cout << "Simple Linked List main()" << endl;

    SimpleLinkedList list;
    list.InsertNodeAtEnd(99);
    // list.InsertNodeAtEnd(55);
    // list.InsertNodeAtEnd(77);
    // list.InsertNodeAtEnd(33);
    // list.InsertNodeAtEnd(99);
    cout << "insert end" << endl;
    list.PrintList();

    list.RemoveNode(0);
    cout << "remove end" << endl;
    list.PrintList();

    return 0;
}