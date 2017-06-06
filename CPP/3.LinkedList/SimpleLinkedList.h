#include <iostream>

class Node
{
private:
	char name[100];
	Node *next;

public:
	Node();
};

class SimpleLinkedList
{
private:
	Node *head;

public:
	SimpleLinkedList();
	~SimpleLinkedList();
	int add_list(char *_name);
	int rm_list(char *_name);
	int search_list(char *_name);
};