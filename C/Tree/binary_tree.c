#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

BinaryTreeNode *MakeBinaryTreeNode(void)
{
	BinaryTreeNode *bt = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

BinaryTreeData GetData(BinaryTreeNode *bt)
{
	return bt->data;
}

void SetData(BinaryTreeNode *bt, BinaryTreeData data)
{
	bt->data = data;
}

BinaryTreeNode *GetSubTree(BinaryTreeNode *bt, SubTreeType nSubTreeType)
{
	BinaryTreeNode* pSubTreeNode = NULL;
	if(nSubTreeType == LEFT_SUBTREE)
	{
		pSubTreeNode = bt->left;
	}
	else if(nSubTreeType == RIGHT_SUBTREE)
	{
		pSubTreeNode = bt->right;
	}

	return pSubTreeNode;
}

void MakeSubTree(BinaryTreeNode *bt, BinaryTreeNode *sub, SubTreeType nSubTreeType)
{
	if(nSubTreeType == LEFT_SUBTREE)
	{
		if(bt->left != NULL)
		{
			free(bt->left);
		}
		bt->left = sub;
	}
	else if(nSubTreeType == RIGHT_SUBTREE)
	{
		if(bt->right != NULL)
		{
			free(bt->right);
		}
		bt->right = sub;
	}
}

void InOrderTraverse(BinaryTreeNode *bt, VisitFuncPtr action)
{
	if(bt == NULL)
	{
		return;
	}
	InOrderTraverse(bt->left, action);
	action(bt->data);
	InOrderTraverse(bt->right, action);
}

void PreOrderTraverse(BinaryTreeNode *bt, VisitFuncPtr action)
{
	if(bt == NULL)
	{
		return;
	}
	action(bt->data);
	PreOrderTraverse(bt->left, action);
	PreOrderTraverse(bt->right, action);
}

void PostOrderTraverse(BinaryTreeNode *bt, VisitFuncPtr action)
{
	if(bt == NULL)
	{
		return;
	}
	PostOrderTraverse(bt->left, action);
	PostOrderTraverse(bt->right, action);
	action(bt->data);
}