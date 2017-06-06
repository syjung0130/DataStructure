#include <iostream>
#include <string.h>
#include "SimpleLinkedList.h"

//#define NO_ERR
enum
{
	NO_ERR_LIST = 0
};

Node::Node()
{
	memset(name, 0, sizeof(name));
	next = NULL;
}

SimpleLinkedList::SimpleLinkedList()
{
	head = NULL;
}

SimpleLinkedList::~SimpleLinkedList()
{
	head = NULL;
}

int SimpleLinkedList::add_list(char *_name)
{

	return NO_ERR_LIST;
}

int SimpleLinkedList::rm_list(char *_name)
{

	return NO_ERR_LIST;
}

int SimpleLinkedList::search_list(char *_name)
{

	return NO_ERR_LIST;
}
