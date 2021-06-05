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

Node* createNode(int n_par,float args[])
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

float getKey(Node* root)
{
	// return the required key for BST
	return root->start;
}
void setKey(Node* root,float args[])
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
	float mx = -100000000;
	if(root->left!=NULL){
		mx = max(mx,(root->left)->max);
		// cout <<(root->left)->max<<endl;
	}
	if(root->right!=NULL){
		mx = max(mx,(root->right)->max);
		// cout << (root->right)->max<<endl;
	}
	root->max = max(mx,root->end);
	// cout << root->start << " "<<root->end<<" "<<root->max<<endl;
	// cout << mx<<endl;
}



