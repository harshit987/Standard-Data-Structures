#include<iostream>
// #include "struct.h"
// #include "custom.h"
#include "query.h"

Node* Search(Node* root, int val)
{
	Node* x = root;
	while(x!=NULL)
	{
		if(getKey(x) == val)
			return x;
		else if(getKey(x)<val)
			x = x->right;
		else
			x = x->left;
	}  
	return NULL;
}

Node* Minimum(Node* root)
{
	Node* x = root;
	while(x->left!=NULL)
	{
		x=x->left;
	}
	return x;
}

Node* Maximum(Node* root)
{
	Node* x = root;
	while(x->right!=NULL)
	{
		x=x->right;
	}
	return x;
}
