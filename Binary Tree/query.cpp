#include<iostream>
#include "struct.h"
Node* createNode(int val)
{
	Node* z = (Node*) malloc(sizeof(Node));
	z->val = val;
	z->left = z->right = z->parent = NULL;
	z->height = 0;
	return z;
}

Node* Search(Node* root, int val)
{
	Node* x = root;
	while(x!=NULL)
	{
		if(x->val == val)
			return x;
		else if(x->val<val)
			x = x->right;
		else
			x = x->left;
	}  
	return NULL;
}

int Minimum(Node* root)
{
	Node* x = root;
	while(x->left!=NULL)
	{
		x=x->left;
	}
	return x->val;
}

int Maximum(Node* root)
{
	Node* x = root;
	while(x->right!=NULL)
	{
		x=x->right;
	}
	return x->val;
}
