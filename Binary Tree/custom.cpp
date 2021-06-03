// #include<iostream>
// #include "custom.h"

// Node* createNode(int val)
// {
// 	Node* z = (Node*) malloc(sizeof(Node));
// 	z->left = z->right = z->parent = NULL;
// 	z->height = 0;

// 	// Initialize other Node elements
// 	return z;
// }

// int getKey(Node* root)
// {
// 	// return the required key for BST
// }
// void setKey(Node* root,int val)
// {
// 	// set the value of root's key to val
// }
// void augmentationUpdate(Node* root)
// {
// 	// Add code required to  update augmented node data structure using its children node.

// }

#include<iostream>

#include "custom.h"

Node* createNode(int n_par,int args[])
{
	Node* z = (Node*) malloc(sizeof(Node));
	z->left = z->right = z->parent = NULL;
	z->height = 0;

	// Initialize other Node elements
	z->start = args[0];
	z->end = args[1];
	z->max = args[1];
	return z;
}

int getKey(Node* root)
{
	// return the required key for BST
	return root->start;
}
void setKey(Node* root,int args[])
{
	root->start = args[0];
	root->end = args[1];
	// set the value of root's key to val
}
void augmentationUpdate(Node* root)
{
	// Add code required to  update augmented node data structure using its children node.
	if(root==NULL)
		return;
	int mx = INT8_MIN;
	if(root->left!=NULL)
		mx = max(mx,(root->left)->max);
	if(root->right!=NULL)
		mx = max(mx,(root->right)->max);
	root->max = max(mx,root->end);
}



