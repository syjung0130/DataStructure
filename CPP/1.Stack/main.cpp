#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    MyStack* m_stack = new MyStack(100);
	m_stack->push(5);
	m_stack->push(100);
	m_stack->push(200);

	m_stack->print_stack();

	cout<<"[1st] peek : "<<m_stack->peek()<<endl;
	cout<<"[1st] pop : "<<m_stack->pop()<<endl;
	cout<<"[2nd] peek : "<<m_stack->peek()<<endl;
	cout<<"[2nd] pop : "<<m_stack->pop()<<endl;

}
