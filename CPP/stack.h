
class MyStack
{
private:
#if(0)
	const int MAX_STACK_SIZE = 100;
	int data_array[MAX_STACK_SIZE];
#else
	int data_array[100];
#endif
	int pos;

public:
	MyStack();
	int push();
	int pop();
	int peek();
};
