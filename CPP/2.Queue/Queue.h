
class MyQueue
{
private:
	int data[100];
	int front;
	int rear;
	static const int maxQueueLen;

public:
	MyQueue();
	~MyQueue();
	int enQueue(int _data);
	int deQueue(void);
	int isEmpty();
	int isFull();
};
