//#include <iostream>
#include <stdio.h>
#include "BinaryTree.h"

int main()
{
//		15			//bTree6
//	  4	   20		//bTree2, bTree5
//	1	  16  25	//bTree1, bTree3, bTree4
	Tree *bTree1 = new Tree(1, NULL, NULL);
	Tree *bTree2 = new Tree(4, bTree1, NULL);
	Tree *bTree3 = new Tree(16, NULL, NULL);
	Tree *bTree4 = new Tree(25, NULL, NULL);
	Tree *bTree5 = new Tree(20, bTree3, bTree4);
	Tree *bTree6 = new Tree(15, bTree2, bTree5);

	Tree *root = bTree6;

	printf("==== inorder =====\n");
	root->inorder(root);
	printf("==================\n\n");

	printf("==== preorder ====\n");
	root->preorder(root);
	printf("==================\n\n");
	
	printf("==== postorder ====\n");
	root->postorder(root);
	printf("===================\n\n");

	return 0;
}
