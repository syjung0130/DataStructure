#include <iostream>
#include <string.h>
#include "Queue.h"
#include <stdio.h>

using namespace std;

const int MyQueue::maxQueueLen = 100;

#if(1)
MyQueue::MyQueue()
{
	front = -1;
	rear = -1;
	//default queue size :100
	size = maxQueueLen;
	size = 100;
	buffer = (int *)malloc(_size);	
	buffer = new int[size];
	memset(buffer, 0, size);
#if(0)
	memset(data, 0, maxQueueLen);
#endif
}

MyQueue::MyQueue(int _size)
{
	front = -1;
	rear = -1;
	size = _size;
	//buffer = (int *)malloc(_size);
	buffer = new int[size];
	memset(buffer, 0, _size);
#if(0)
	memset(data, 0, _size);
#endif
}

MyQueue::~MyQueue()
{
	//for using malloc later.
	if(buffer)	delete buffer;
}
#endif

ArrayQueue::ArrayQueue()
{
	front = -1;
	rear = -1;
	//default queue size :100
	size = maxQueueLen;
	size = 100;
	//buffer = (int *)malloc(maxQueueLen);
	buffer = new int[size];
	memset(buffer, 0, size);
#if(0)
	memset(data, 0, maxQueueLen);
#endif
}

ArrayQueue::ArrayQueue(int _size)
{
	front = -1;
	rear = -1;
	size = _size;
	//buffer = (int *)malloc(_size);
	buffer = new int[size];
	memset(buffer, 0, _size);
#if(0)
	memset(data, 0, _size);
#endif
}

ArrayQueue::~ArrayQueue()
{
	//for using malloc later.
	if(buffer)	delete buffer;
}
#define ERR_Q_FULL -1
#define ERR_Q_INIT -2

int ArrayQueue::enQueue(int _data)
{
	if(rear == size-1)
	{
		cout<<"Queue err."<<endl;
		return ERR_Q_INIT;
	}
	//printf("in %s [%d:%d]\n", __func__, front, rear);
	rear++;
	buffer[rear] = _data;
	return 1;
}

int ArrayQueue::deQueue(void)
{
	int ret = 0;
	if(front == rear)
	{
		cout<<"Queue is empty !!!!"<<endl;
		return -1;
	}
	front++;
	ret = buffer[front];
	return ret;
}

int ArrayQueue::isEmpty(void)
{
	if(front == rear)	return 1;
	else return 0;
}

void ArrayQueue::initQueue(void)
{
	front = -1;
	rear = -1;
	memset(buffer, 0, size);
	printf("in %s\n", __func__);
}

#if(1)
CircularQueue::CircularQueue()
{
	front = -1;
	rear = -1;
	//default queue size :100
	//size = maxQueueLen;
	size = 100;
	//buffer = (int *)malloc(size);
	buffer = new int[size];
	memset(buffer, 0, size);
#if(0)
	memset(data, 0, maxQueueLen);
#endif
}

CircularQueue::CircularQueue(int _size)
{
	front = -1;
	rear = -1;
	size = _size;
	//buffer = (int *)malloc(_size);
	buffer = new int[size];
	memset(buffer, 0, _size);
#if(0)
	memset(data, 0, _size);
#endif
}

CircularQueue::~CircularQueue()
{
	//for using malloc later.

	delete buffer;
}

int CircularQueue::enQueue(int _data)
{
	if(isFull() == 1)
	{
		cout<<"Queue is Full"<<endl;
		return -1;
	}
	printf("in %s [%d:%d:%d]\n", __func__, front, rear, size);
	rear++;
	buffer[rear % size] = _data;
	return 1;
}

int CircularQueue::deQueue(void)
{
	int ret = 0;
	if(isEmpty() == 1)
	{
		cout<<"Queue is empty !!!!"<<endl;
		return -1;
	}
	front++;
	ret = buffer[front % size];
	return ret;
}

int CircularQueue::isEmpty(void)
{
	if(front == rear)	return 1;
	else return 0;
}

int CircularQueue::isFull(void)
{
	//if(front == rear) return 1;
	if((rear+1) % size == front) return 1;
	else return 0;
}
#endif
