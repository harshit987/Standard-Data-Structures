#include<iostream>
#include "struct.h"
#include "query.h"
#include "update.h"

Node* left_rotate(Node** root,Node* x)
{
	
	Node* y = x->right;
	if(y==NULL)
		return NULL;

	Node* parent = x->parent;
	Node* z = y->left;

	x->right = z;
	y->left = x;
	if(parent==NULL)
		*root = y;
	else
	{
		if(parent->left==x)
			parent->left = y;
		else
			parent->right = y;
	}

	x->parent = y;
	y->parent = parent;
	z->parent = x;
	
	x->height = max((x->left)->height,(x->right)->height);
	y->height = max((y->left)->height,(y->right)->height);

	return y;
}
Node* right_rotate(Node** root, Node* x)
{
	Node* y = x->left;
	if(y==NULL)
		return NULL;

	Node* parent = x->parent;
	Node* z = y->right;

	x->left = z;
	y->right = x;
	if(parent==NULL)
		*root = y;
	else
	{
		if(parent->left==x)
			parent->left = y;
		else
			parent->right = y;
	}

	x->parent = y;
	y->parent = parent;
	z->parent = x;

	x->height = max((x->left)->height,(x->right)->height)+1;
	y->height = max((y->left)->height,(y->right)->height)+1;
	
	return y;
}
int getHeight(Node* root)
{
	if(root==NULL)
		return 0;
	else return root->height;
}
Node* avl_insert(Node* root,int x)
{
	Node* z = createNode(x);
	root = insert(root,z);
	z = z->parent;

	while(z!=NULL)
	{
		z->height = max(getHeight(z->left),getHeight(z->right));
		int inbal = 0;
		inbal = getHeight(z->left)-getHeight(z->right);
		if(inbal>1)
		{
			if(x<(z->left)->val)
				z = right_rotate(&root,z);
			else
			{
				z->left = left_rotate(&root,z->left);
				z = right_rotate(&root,z);
			}

		}
		else if(inbal<-1)
		{
			if(x>(z->right)->val)
				z = left_rotate(&root,z);
			else
			{
				z->right = right_rotate(&root,z->right);
				z = left_rotate(&root,z);
			}
		}
		z = z->parent;
	}
}
