#include <iostream>

class Node
{
private:
	char name[100];
	Node *next;

public:
	Node();
	void setNext(Node *p);
	Node* getNext();
	void setElement(char *_name);
	char *getElement();
};

class SimpleLinkedList
{
private:
	Node *head;

public:
	SimpleLinkedList();
	~SimpleLinkedList();
	int insert_item(char *_name);
	int remove_item(char *_name);
	int search_list();
	int search_list(char *_name);
};