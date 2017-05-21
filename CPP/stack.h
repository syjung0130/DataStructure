
class MyStack
{
private:
#if(1)
	//const int MAX_STACK_SIZE = 100;
	static const int MaxBufferSize;
	int *buffer;
#else
#define MAX_STACK_SIZE 100
	int data_array[MAX_STACK_SIZE];
#endif
	int pos;

public:
	MyStack();
	MyStack(int _size);
	~MyStack();
	int push(int _data);
	int pop();
	int peek();
	void print_stack();
};
