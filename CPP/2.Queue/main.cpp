#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    MyQueue* m_queue = new MyQueue();
	m_queue->enQueue(5);
	m_queue->enQueue(100);
	m_queue->enQueue(200);

	//m_queue->print_stack();

	cout<<"[1st] deQueue : "<<m_queue->deQueue()<<endl;
	cout<<"[2nd] deQueue : "<<m_queue->deQueue()<<endl;
	cout<<"[3rd] deQueue : "<<m_queue->deQueue()<<endl;
	cout<<"[4th] deQueue : "<<m_queue->deQueue()<<endl;

}
