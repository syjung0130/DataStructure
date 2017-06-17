#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

int main()
{
	Node *new_node = new Node();
	SimpleLinkedList *m_sList = new SimpleLinkedList();

	m_sList->insert_item("apple");
	m_sList->insert_item("mango");
	m_sList->insert_item("banana");

	m_sList->search_list();

	m_sList->search_list("banana");
}
