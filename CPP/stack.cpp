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
	++pos;
	buffer[pos] = _data;
	return 1;
}

int MyStack::pop()
{
	 return buffer[pos];
	 pos--;
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
