#include <stdio.h>
#include "binary_tree.h"

void showIntData(int data)
{
	printf("%d ", data);
}

int main()
{
	printf("binary_tree main\n");
	BinaryTreeNode *bt1 = MakeBinaryTreeNode();
	BinaryTreeNode *bt2 = MakeBinaryTreeNode();
	BinaryTreeNode *bt3 = MakeBinaryTreeNode();
	BinaryTreeNode *bt4 = MakeBinaryTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeSubTree(bt1, bt2, LEFT_SUBTREE);
	MakeSubTree(bt1, bt3, RIGHT_SUBTREE);
	MakeSubTree(bt2, bt4, LEFT_SUBTREE);

	// printf("%d \n", GetData(GetSubTree(bt1, LEFT_SUBTREE)));
	// printf("%d \n", GetData(GetSubTree(GetSubTree(bt1, LEFT_SUBTREE), LEFT_SUBTREE)));
	// InOrderTraverse(bt1);
	InOrderTraverse(bt1, showIntData);
	printf("\n");
}