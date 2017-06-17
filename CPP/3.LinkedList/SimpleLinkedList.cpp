#include <iostream>
#include <string.h>
#include "SimpleLinkedList.h"

using namespace std;

//#define NO_ERR
enum
{
	NO_ERR_LIST = 0,
	ERROR_MALLOC_FAILED,
	ERROR_EMPTY_LIST,
	ERROR_INVALID_INSTANCE,
};

#ifndef USING_STRUCT_NODE
Node::Node()
{
	memset(name, 0, sizeof(name));
	next = NULL;
}
#endif
void Node::setNext(Node *p)
{
	next = p;
}
Node* Node::getNext()
{
	return next;
}

void Node::setElement(char *_name)
{
	memcpy(name, _name, strlen(_name));
}

char *Node::getElement()
{
	return name;
}

SimpleLinkedList::SimpleLinkedList()
{
	head = NULL;
}

SimpleLinkedList::~SimpleLinkedList()
{
	head = NULL;
}
#ifdef USING_STRUCT_NODE
int SimpleLinkedList::insert_item(char *_name)
{
	//first insert.
	if(head == NULL)
	{
		head = (Node *)malloc(sizeof(Node));
		if(head == NULL)
		{
			return ERROR_MALLOC_FAILED;
		}
		memcpy(head->name, _name, strlen(_name));
		head->next = NULL;
	}
	else//insert current item at rear.
	{
		/* Searching position to insert */
		Node *pCur = head;
		while(pCur->next != NULL)
		{
			pCur = pCur->next;
		}

		/* Insert item at last pos */
		Node *newNode = (Node *)malloc(sizeof(Node));
		memcpy(newNode->name, _name, sizeof(_name));
		pCur->next = newNode;

		pCur = pCur->next;
		pCur->next = NULL;
	}

	return NO_ERR_LIST;
}
#else
int SimpleLinkedList::insert_item(char *_name)
{
	//first insert.
	if(head == NULL)
	{
		//head = (Node *)malloc(sizeof(Node));
		head = new Node();
		if(head == NULL)
		{
			return ERROR_INVALID_INSTANCE;
		}
		Node *newNode = new Node();
		newNode->setElement(_name);
		newNode->setNext(NULL);
	}
	else//insert current item at rear.
	{
		/* Moving position to insert */
		Node *pCur = head;
		while(pCur->getNext() != NULL)
		{
			pCur = pCur->getNext();
		}

		/* Insert item at last pos */
		Node *newNode = new Node();
		newNode->setElement(_name);
		pCur->setNext(newNode);

		/* Set last member's next as NULL to identify rear */
		pCur = pCur->getNext();
		pCur->setNext(NULL);
	}

	return NO_ERR_LIST;
}
#endif
int SimpleLinkedList::remove_item(char *_name)
{

	return NO_ERR_LIST;
}

int SimpleLinkedList::search_list(void)
{
	Node *pCur = head;
	int iCount = 0;

	if(pCur == NULL)
	{
		cout<<"There is no item in list~!!!!"<<endl;
		return ERROR_EMPTY_LIST;
	}

	while(pCur != NULL)
	{
		cout<<"["<<iCount<<"]"<<pCur->getElement()<<endl;
		iCount++;

		pCur = pCur->getNext();
	}
	return NO_ERR_LIST;
}
int SimpleLinkedList::search_list(char *_name)
{
	Node *pCur = head;
	int iCount = 0;

	if(pCur == NULL)
	{
		cout<<"There is no item in list~!!!!"<<endl;
		return ERROR_EMPTY_LIST;
	}

	while(pCur != NULL)
	{
		cout<<"["<<iCount<<"]"<<pCur->getElement()<<endl;
		iCount++;
		if(!strcmp(pCur->getElement(), _name))
		{
			cout<<"find name : "<<pCur->getElement()<<endl;
			break;
		}
		pCur = pCur->getNext();
	}
	return NO_ERR_LIST;
}
