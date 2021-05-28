#include<iostream>
#include "struct.h"


Node* insert(Node* root,int val)
{
	Node* parent = NULL;
	Node* x = root;

	Node* z = createNode(val);

	while(x!=NULL)
	{
		parent = x;
		if(x->val<z->val)
			x = x->right;
		else
			x = x->left;
	}
	z->parent = parent;
	if(parent==NULL)
		root = z;
	else
	{
		if(parent->val<z->val)
			parent->right = z;
		else
			parent->left = z;
	}
	return root;
}







