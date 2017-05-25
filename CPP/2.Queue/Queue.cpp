#include <iostream>
#include <string.h>
#include "Queue.h"

using namespace std;

const int MyQueue::maxQueueLen = 100;

MyQueue::MyQueue()
{
	front = -1;
	rear = -1;
	memset(data, 0, maxQueueLen);
}

MyQueue::~MyQueue()
{
	//for using malloc later.
}

int MyQueue::enQueue(int _data)
{
	if(rear == maxQueueLen)
	{
		cout<<"Queue err"<<endl;
		return -1;
	}
	rear++;
	data[rear] = _data;
	return 1;
}

int MyQueue::deQueue(void)
{
	int ret = 0;
	if(front == rear)
	{
		cout<<"Queue is empty !!!!"<<endl;
		return -1;
	}
	front++;
	ret = data[front];
	return ret;
}

int MyQueue::isEmpty(void)
{
	if(front == rear)	return 1;
	else return 0;
}
/*
int MyQueue::isFull(void)
{
	if(front == rear) return 1;
	else return 0;
}
*/
