#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BinaryTreeData;

typedef struct _BinaryTreeNode
{
	BinaryTreeData data;
	struct _BinaryTreeNode *left;
	struct _BinaryTreeNode *right;
}BinaryTreeNode;

typedef enum _SubTreeType
{
	LEFT_SUBTREE = 0,
	RIGHT_SUBTREE = 1
}SubTreeType;

BinaryTreeNode *MakeBinaryTreeNode(void);
BinaryTreeData GetData(BinaryTreeNode *bt);
void SetData(BinaryTreeNode *bt, BinaryTreeData data);
BinaryTreeNode *GetSubTree(BinaryTreeNode *bt, SubTreeType nSubTreeType);
void MakeSubTree(BinaryTreeNode *bt, BinaryTreeNode *sub, SubTreeType nSubTreeType);

typedef void VisitFuncPtr(BinaryTreeData data);

void InOrderTraverse(BinaryTreeNode *bt, VisitFuncPtr action);
void PreOrderTraverse(BinaryTreeNode *bt, VisitFuncPtr action);
void PostOrderTraverse(BinaryTreeNode *bt, VisitFuncPtr action);

#endif

