#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

MyStack::MyStack()
{
	pos = 0;
	memset(data_array, 0, 100);
	cout<<"Constructor ~~~~"<<endl;
}

int MyStack::push()
{
	return 1;
}

int MyStack::pop()
{
	return 1;
}

int MyStack::peek()
{
	return 1;
}
