#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    MyQueue* m_arrayQueue = new ArrayQueue(5);
	MyQueue* m_circularQueue = new CircularQueue(5);

	/* Check Array Queue */
	((ArrayQueue *)m_arrayQueue)->enQueue(5);
	((ArrayQueue *)m_arrayQueue)->enQueue(100);
	((ArrayQueue *)m_arrayQueue)->enQueue(200);
	cout<<"[1st] deQueue : "<<((ArrayQueue *)m_arrayQueue)->deQueue()<<endl;
	cout<<"[2nd] deQueue : "<<((ArrayQueue *)m_arrayQueue)->deQueue()<<endl;
	cout<<"[3rd] deQueue : "<<((ArrayQueue *)m_arrayQueue)->deQueue()<<endl;
	cout<<"[4th] deQueue : "<<((ArrayQueue *)m_arrayQueue)->deQueue()<<endl;

	((ArrayQueue *)m_arrayQueue)->initQueue();
	((ArrayQueue *)m_arrayQueue)->enQueue(5);
	((ArrayQueue *)m_arrayQueue)->enQueue(100);
	((ArrayQueue *)m_arrayQueue)->enQueue(200);
	((ArrayQueue *)m_arrayQueue)->enQueue(100);
	((ArrayQueue *)m_arrayQueue)->enQueue(200);
	((ArrayQueue *)m_arrayQueue)->enQueue(500);
	((ArrayQueue *)m_arrayQueue)->enQueue(500);

	/* Check Circular Queue */
	((CircularQueue *)m_circularQueue)->enQueue(5);
	((CircularQueue *)m_circularQueue)->enQueue(100);
	((CircularQueue *)m_circularQueue)->enQueue(200);
	cout<<"[1st] deQueue : "<<((CircularQueue *)m_circularQueue)->deQueue()<<endl;
	cout<<"[2nd] deQueue : "<<((CircularQueue *)m_circularQueue)->deQueue()<<endl;
	cout<<"[3rd] deQueue : "<<((CircularQueue *)m_circularQueue)->deQueue()<<endl;
	cout<<"[4th] deQueue : "<<((CircularQueue *)m_circularQueue)->deQueue()<<endl;
	((CircularQueue *)m_circularQueue)->enQueue(5);
	((CircularQueue *)m_circularQueue)->enQueue(100);
	((CircularQueue *)m_circularQueue)->enQueue(200);
	((CircularQueue *)m_circularQueue)->enQueue(100);
	((CircularQueue *)m_circularQueue)->enQueue(500);
	((CircularQueue *)m_circularQueue)->enQueue(500);
	((CircularQueue *)m_circularQueue)->enQueue(900);
/*
	m_queue->enQueue(5);
	m_queue->enQueue(100);
	m_queue->enQueue(200);

	//m_queue->print_stack();

	cout<<"[1st] deQueue : "<<m_queue->deQueue()<<endl;
	cout<<"[2nd] deQueue : "<<m_queue->deQueue()<<endl;
	cout<<"[3rd] deQueue : "<<m_queue->deQueue()<<endl;
	cout<<"[4th] deQueue : "<<m_queue->deQueue()<<endl;
*/

}
