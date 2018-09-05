#include <stdio.h>

#define N_MAX_TREE_INDEX 15
int N_CURRENT_INDEX = 0;
int tree[N_MAX_TREE_INDEX] = {0,};


void swap(int *a,int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

int max(int a,int b,int c)
{
  int max=0,q;
  if(tree[a]>max) {
    max=tree[a];
    q=a;
  }
  if(tree[b]>max) {
    max=tree[b];
    q=b;
  }
  if(tree[c]>max) {
    max=tree[c];
    q=c;
  }
  return q;
}

int min(int parent_index)
{
  int min_child_index = 0;
  if(tree[parent_index*2] < tree[parent_index*2+1])
  {
    min_child_index =  parent_index*2;
  }
  else 
  {
    min_child_index = parent_index*2+1;
  }

  if (min_child_index > N_CURRENT_INDEX) min_child_index = N_CURRENT_INDEX;
  printf("%s: (min_child_index: %d\n)", __FUNCTION__, min_child_index);

  return min_child_index;
}

void create_heap()
{
  int end = N_CURRENT_INDEX/2;
  int i = 0, nnow = 0, qq = 0;
  for(i=end;i>=1;i--) {
    nnow=i;
    while((qq=max(nnow,nnow*2,nnow*2+1))!=nnow) {
      swap(&tree[nnow],&tree[qq]);
      nnow=qq;
    }
  }
}

void display_heap()
{
  printf("======== display heap =======\n");
  int i = 0;
  for(i = 0; i < N_MAX_TREE_INDEX; i++)
  {
    printf("%d   ",tree[i]);
  }
  printf("\n");
  printf("=============================\n");

}

// 1. 맨 마지막 노드에 삽입할 노드를 추가한다.
// 2. 삽입할 데이터(추가된 노드)를 부모노드와 비교해서 부모노드의 값이 더 작으면 swap한다.
// 3. 만약 더 크거나 현재 순회 index가 root node index일 경우 반복문을 탈출한다.
// 4. 현재 순회 중인 index를 부모노드로 이동한다.(부모노드로 이동한다.) 2,3,4번을 반복한다.
void insert_heap_element(int data)
{
  tree[++N_CURRENT_INDEX] = data;
  printf("%s: heap index(%d), data(%d)\n", __FUNCTION__, N_CURRENT_INDEX, data);
  int index = N_CURRENT_INDEX;
  while(1)
  {
    if (index == 1) break;
    if(tree[index] < tree[index/2])
    {
      printf("need to swap, child[%d]: %d, parent[%d]: %d\n", index, tree[index], index/2 , tree[index/2]);
      swap(&tree[index], &tree[index/2]);
      index = index / 2;
    }
    else
    {
      printf("sorted..\n");
      break;
    }
  }
}

// 1. 루트 노드의 값을 삭제한다. (힙은 우선순위가 높은 것부터 삭제하므로)
// 2. 맨 마지막 노드를 루트노드로 옮긴다.
// 3. 옮겨진 노드의 값을 자식노드들과 비교해서 옮겨진 노드가 자식노드들보다 크면 자식노드들 중 작은 값과 swap한다.
// 4. 더 작거나 인덱스가 마지막 인덱스값과 같으면 반복문을 탈출한다.
// 5. 현재 순회중인 인덱스를 자식노드의 인덱스로 이동(갱신)한다.
int delete_heap_element()
{
  int deleted_data = tree[1];

  tree[1] = tree[N_CURRENT_INDEX];
  tree[N_CURRENT_INDEX--] = 0;

  int index = 1;
  while(1)
  {

    printf("index: %d\n", index);
    if(index >= N_CURRENT_INDEX || tree[index] < tree[min(index)]) break;

    if((tree[index] > tree[index/2]) || (tree[index] > tree[index/2+1]))
    {
      printf("need to swap, target[%d]: %d, child 1[%d]: %d, child 2[%d]: %d\n"
                                                  , index, tree[index], index*2 , tree[index*2], index*2+1, tree[index*2+1]);
      int min_child_index = min(index);
      swap(&tree[index], &tree[min_child_index]);
      index = min_child_index;
    }
    else 
    {
      break;
    }
  }

return deleted_data;
}

int main()
{
  int i = 0;
#if(1) //if create heap using insert_heap_element() function.
  printf("before sorting heap\n");
  display_heap();

  for(i = 0; i < 10; i++)
  {
    insert_heap_element(i);
  }
#else //if create heap using create_heap() function.
  for(i = 0; i < 10; i++)
  {
    tree[i] = i;
    N_CURRENT_INDEX++;
  }
  printf("before sorting heap\n");
  display_heap();
  create_heap();
#endif
  printf("after sorting heap\n");
  display_heap();

  printf("after delete heap\n");
  delete_heap_element();
  delete_heap_element();
  display_heap();

  return 0;
}