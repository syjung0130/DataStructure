#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HeapData;
typedef int Priority;

typedef struct _HeapElem
{
	Priority pr;
	HeapData data;
}HeapElem;

typedef struct _Heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *ph);
int HeapIsEmpty(Heap *ph);
void HeapInsert(Heap *ph, HeapData data, Priority pr);
HeapData HeapDelete(Heap *ph);

#endif