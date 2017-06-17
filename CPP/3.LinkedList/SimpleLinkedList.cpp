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
};

#if(0)
Node::Node()
{
	memset(name, 0, sizeof(name));
	next = NULL;
}
#endif

SimpleLinkedList::SimpleLinkedList()
{
	head = NULL;
}

SimpleLinkedList::~SimpleLinkedList()
{
	head = NULL;
}

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
		cout<<"["<<iCount<<"]"<<pCur->name<<endl;
		iCount++;
		pCur = pCur->next;
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
		cout<<"["<<iCount<<"]"<<pCur->name<<endl;
		iCount++;
		if(!strcmp(pCur->name, _name))
		{
			cout<<"find name : "<<pCur->name<<endl;
			break;
		}
		pCur = pCur->next;
	}
	return NO_ERR_LIST;
}
