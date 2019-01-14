#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

const int MyStack::MaxBufferSize = 100;

MyStack::MyStack()
{
	pos = -1;
#if(0)
	memset(data_array, 0, 100);
#endif
	cout<<"Constructor ~~~~"<<endl;
}

MyStack::MyStack(int _size)
{
	pos = -1;
	//MaxBufferSize = _size;
	cout<<"MaxBufferSize : "<<MaxBufferSize<<endl;
	buffer = new int[MaxBufferSize];
	memset(buffer, 0, MaxBufferSize);
}
MyStack::~MyStack()
{
	delete buffer;
}

int MyStack::push(int _data)
{
	if(pos >= MaxBufferSize)
	{
		cout<<"Stack is full !!!!"<<endl;
		return 0;
	}
	++pos;
	buffer[pos] = _data;
	return 1;
}

int MyStack::pop()
{
	int ret = 0;

	if(pos < 0)
	{
		cout<<"Stack is empty!!!!"<<endl;
		return 0;
	}

	ret = buffer[pos];
	pos--;

	return ret;
}

int MyStack::peek()
{
	return buffer[pos];
}

void MyStack::print_stack()
{
	for(int cnt = 0;cnt <= pos;cnt++)
	{
		cout<<cnt<<" : "<<buffer[cnt]<<endl;
	}
}
