# DataStructure

1.Stack
--------
![300px-Data_stack.svg](./img/300px-Data_stack.svg.png)

 - LIFO(Last In First Out)구조,  즉 제일 마지막에 push 한 data가 pop할 때 먼저 나오게 된다.

 - 예를 들면 프로세스의 context switching시나, 함수 호출 시, 인터럽트 발생 시 현재 수행중인 주소를 스택에 넣은 뒤 다음 함수로 진입 후, 복귀할 때 스택에서 다시 이전의 주소로 돌아옴.

 - 고정크기의 배열을 주로 사용하며, 크기 제한을 없애기 위해서는 연결리스트로 구현하면 가능하다.
 - push 할때는 인덱스를 증가시킨 뒤에 값을 넣고 pop할 때에는 값을 꺼내온 다음 인덱스연산을 하는 것을 주의.
 - (과자 다이제스트 처럼 한쪽 구멍이 막혀있는 통에 하나씩 물건을 쌓고 다시 빼는 것을 상상하면 쉽다.)


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



2.Queue
--------
![300px-Data_Queue.svg](./img/300px-Data_Queue.svg.png)

- FIFO구조(First In First Out)로 먼저 넣은 것이 먼저 나오는 자료구조.
- EnQueue때에는 rear++, DeQueue때에는 front++
- 스택이 윗 뚜껑만 열려있는 원통이라고 하면, 큐는 양쪽 구멍이 모두 뚤려있는 원통이라고 상상하면 이해가 쉬움.
- 계속 넣고 빼다 보면 index가 배열의 끝으로 이동하기 때문에 다시 init을 해주어야 한다.
- 그래서 대부분 원형 큐를 많이 사용한다. 이전의 스택과 지금의 큐 모두 고정 크기의 배열을 사용한다.
- 크기 제한이 없이 사용하기 위해서는 연결리스트를 이용한 큐를 사용하면 됨.
- 비었을 경우는 front와 rear가 같을 때, 꽉찬경우는 rear+1이 front와 같을 때로 판단함.


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

![Circular_Buffer_Animation](./img/Circular_Buffer_Animation.gif)

https://github.com/unlocker-sy/DataStructure


3.Linked List

- Node 의 선언
Node는 data를 저장, 조작하기 위한 추상적인 개념. 여기서는 클래스로 정의.
데이터와 다음 Node를 가리키는 변수, 그리고 이 변수들의 setter, getter함수들을 선언.


- head, 첫 Node의 생성.
head는 첫 번째 Node를 가리키고 있어야함.
그래서 head값의 초기화는 첫 번째 삽입할 때 함.


- node의 삽입. ( 두번째 삽입할 때부터)
끝에 삽입할 경우를 예로 들면,
위치를 끝까지 이동,
새로운 node를 생성
node의 data를 삽입할 data로 set.
현재 위치의 node의 next를 새로운 Node로 set.
새로운 node의 next를 NULL로 set



- 조회함수
처음부터 끝까지 조회(출력)하는 함수,
같은 data를 찾는 함수를 오버로딩해서 두개를 만듬.



- node의 삭제
head를 삭제할 경우 head를 next로 이동하고
그 이후의 node는 그 이전의 node를 기억하고 있어야하고
삭제할 node를 찾으면 이전 node의 next를 삭제할 node의 next로 set함.

(https://github.com/unlocker-sy/DataStructure/tree/master/CPP/3.LinkedList)



