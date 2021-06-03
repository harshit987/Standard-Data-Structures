#include<iostream>
// #include "struct.h"
#include "update.h"


Node* insert(Node* root,Node* z)
{
	Node* parent = NULL;
	Node* x = root;

	while(x!=NULL)
	{
		x->height++;
		parent = x;
		if(getKey(x)<getKey(z))
			x = x->right;
		else
			x = x->left;
	}
	z->parent = parent;
	if(parent==NULL)
		root = z;
	else
	{
		if(getKey(parent)<getKey(z))
			parent->right = z;
		else
			parent->left = z;
	}
	return root;
}

Node* del(Node* root,Node* z)
{
	Node* parent = z->parent;
	if(z->left==NULL&&z->right==NULL)
	{
		if(parent==NULL)
			root = NULL;
		else if(parent->right==z)
			parent->right=NULL;
		else
			parent->left= NULL;
	}
	else if(z->left==NULL)
	{
		if(parent==NULL)
			root = z->right;
		else if(parent->left == z) 
			parent->left = z->right;
		else
			parent->right = z->right;
	}
	else if(z->right == NULL)
	{
		if(parent==NULL)
			root = z->left;
		else if(parent->left == z)
			parent->left = z->left;
		else
			parent->right = z->left;
	}
	else
	{
		Node* y = Minimum(z->right);
		int args[] = {y->start,y->end};
		setKey(z,args);
		// z->val = y->val;
		Node* p = y->parent;
		p->left = y->right; 
	}
	return root;
}







