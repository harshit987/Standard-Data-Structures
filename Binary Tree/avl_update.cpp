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
	
	x->height = max((x->left)->height,(x->right)->height)+1;
	y->height = max((y->left)->height,(y->right)->height)+1;

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
		if(z->parent==NULL)
			root = z;
		z = z->parent;
	}
	return root;
}

Node* avl_delete(Node* root, Node* z)
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
		Node* y = Minimum(root,z->right);
		z->val = y->val;
		Node* p = y->parent;
		p->left = y->right;
		parent = p; 
	}
	while(parent!=NULL)
	{
		parent->height = max(getHeight(parent->left),getHeight(parent->right))+1;
		int inbal = getHeight(parent->left)-getHeight(parent->right);
		if(inbal>1)
		{
			if(getHeight(parent->left->left)-getHeight(parent->left->right)>=0)
				parent = right_rotate(&root,parent);
			else
			{
				parent->left = left_rotate(&root,parent->left);
				parent = right_rotate(&root,parent);
			}
		}
		else if(inbal<-1)
		{
			if(getHeight(parent->right->right)-getHeight(parent->right->left)>=0)
				parent = left_rotate(&root,parent);
			else
			{
				parent->right = right_rotate(&root,parent->right);
				parent = left_rotate(&root,parent);
			}
		}
		if(parent->parent==NULL)
			root = parent;
		parent = parent->parent;

	}
	return root;
}