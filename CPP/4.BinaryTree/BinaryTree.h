#include <iostream>

class Tree
{
private:
	int data;
	Tree *left;
	Tree *right;

public:
	Tree();
	Tree(int data_data, Tree *node_left, Tree *node_right);
	~Tree();

	void inorder(Tree *node);
	void preorder(Tree *node);
	void postorder(Tree *node);
	int get_data();
	Tree *get_left();
	Tree *get_right();
	void set_left(Tree *node_left);
	void set_right(Tree *node_right);
};
