#include <iostream>
#include "SimpleLinkedList.h"
#include "DoubleLinkedList.h"
#include "TLinkedList.h"

using namespace std;

//************
// test scenario
// TestOneItem() : only one item insert -> remove -> remove -> error처리
// TestMoreThanOneItem(): 5 item insert -> remove first -> remove last -> remove middle
//************

enum class TestListType {
    SimpleList = 0,
    DoubleList = 1
};

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

void testInsertOnlyOneItem(DoubleLinkedList& list)
{
    list.InsertNodeAtEnd(99);
    cout << "insert end" << endl;
    list.PrintList();
}

void testInsert5Item(DoubleLinkedList& list)
{
    list.InsertNodeAtEnd(99);
    list.InsertNodeAtEnd(55);
    list.InsertNodeAtEnd(77);
    list.InsertNodeAtEnd(33);
    list.InsertNodeAtEnd(99);
    cout << "insert end" << endl;
    list.PrintList();
}

void TestOneItem(TestListType listType)
{
    cout << "@@@@ TestOneItem START !!!! @@@@" << endl;
    if (listType == TestListType::SimpleList) 
    {
        SimpleLinkedList list;
        testInsertOnlyOneItem(list);
        list.RemoveNode(0);
        list.RemoveNode(0);
        cout << "remove one item end" << endl;
        list.PrintList();
    }
    else if (listType == TestListType::DoubleList)
    {
        DoubleLinkedList list;
        testInsertOnlyOneItem(list);
        list.RemoveNode(0);
        list.RemoveNode(0);
        cout << "remove one item end" << endl;
        list.PrintList();
    }
    cout << "@@@@ TestOneItem END !!!! @@@@" << endl;

}

void TestMoreThanOneItem(TestListType listType)
{
    cout << "@@@@ TestMoreThanOneItem START !!!! @@@@" << endl;
    if (listType == TestListType::SimpleList)
    {
        SimpleLinkedList list;
        testInsert5Item(list);
        list.RemoveNode(0);
        list.RemoveNode(list.GetLength()-1);
        list.RemoveNode(1);
        cout << "remove first, last, middle items end" << endl;
        list.PrintList();
    }
    else if(listType == TestListType::DoubleList)
    {
        DoubleLinkedList list;
        testInsert5Item(list);
        list.RemoveNode(0);
        list.RemoveNode(list.GetLength()-1);
        list.RemoveNode(1);
        cout << "remove first, last, middle items end" << endl;
        list.PrintList();
    }

    cout << "@@@@ TestMoreThanOneItem END !!!! @@@@" << endl;
}

void TestTemplateList()
{
    cout << "----- TestTemplateList() ------" << endl;
    cout << "TestTemplateList: int items list" << endl;
    TLinkedList<int> iList;
    cout << "iList is empty: " << iList.empty() <<endl;
    iList.push_back(5);
    iList.push_back(9);
    cout << "iList is empty: " << iList.empty() <<endl;
    iList.RemoveNode(0);
    iList.PrintList();
    iList.RemoveAllNodes();
    iList.PrintList();
    cout << "iList is empty: " << iList.empty() <<endl;

    cout << "TestTemplateList: double items list" << endl;
    TLinkedList<double> dList;
    cout << "dList is empty: " << dList.empty() <<endl;
    dList.push_back(5.00);
    dList.push_back(9.00);
    dList.PrintList();
    cout << "dList is empty: " << dList.empty() <<endl;
    dList.RemoveNode(0);
    dList.PrintList();
    dList.RemoveAllNodes();
    dList.PrintList();
    cout << "dList is empty: " << dList.empty() <<endl;


    cout << "TestTemplateList: string items list" << endl;
    TLinkedList<string> sList;
    cout << "sList is empty: " << sList.empty() <<endl;
    sList.push_back("aaaa");
    sList.push_back("hhhh");
    sList.PrintList();
    cout << "sList is empty: " << sList.empty() <<endl;
    sList.RemoveNode(0);
    sList.PrintList();
    sList.RemoveAllNodes();
    sList.PrintList();
    cout << "sList is empty: " << sList.empty() <<endl;
}

int main ()
{
    cout << "Simple Linked List test main()" << endl;

    TestOneItem(TestListType::SimpleList);
    TestMoreThanOneItem(TestListType::SimpleList);

    TestOneItem(TestListType::DoubleList);
    TestMoreThanOneItem(TestListType::DoubleList);

    TestTemplateList();
    return 0;
}