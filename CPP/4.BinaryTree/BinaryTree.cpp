#include "BinaryTree.h"
#include <stdio.h>

Tree::Tree()
{
	data = 0;
	left = NULL;
	right = NULL;
}

Tree::Tree(int data_data, Tree *node_left, Tree *node_right)
{
	data = data_data;
	left = node_left;
	right = node_right;
}

Tree::~Tree()
{

}

//중위 순회
void Tree::inorder(Tree *node)
{
	if(node == NULL)
	{
		//printf("[%s] \n", __func__);
		return;
	}
	inorder(node->get_left());
	printf("data : %d\n", node->get_data());
	inorder(node->get_right());
}

//전위 순회
void Tree::preorder(Tree *node)
{
	if(node == NULL)
	{
		//printf("[%s] \n", __func__);
		return;
	}
	printf("data : %d\n", node->get_data());
	preorder(node->get_left());
	preorder(node->get_right());
}

//후휘 순회
void Tree::postorder(Tree *node)
{
	if(node == NULL)
	{
		//printf("[%s] \n", __func__);
		return;
	}
	postorder(node->get_left());
	postorder(node->get_right());
	printf("data : %d\n", node->get_data());
}

int Tree::get_data()
{
	return data;
}

Tree *Tree::get_left()
{
	return left;
}

Tree *Tree::get_right()
{
	return right;
}

void Tree::set_left(Tree *node_left)
{
	left = node_left;
}

void Tree::set_right(Tree *node_right)
{
	right = node_right;
}
