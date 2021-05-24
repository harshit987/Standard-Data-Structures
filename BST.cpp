#include<iostream>

struct node {
	int val;
	struct node* left;
	struct node* right;
	struct node* parent;
};
typedef struct node Node;
Node* createNode(int val)
{
	Node* z = (Node*) malloc(sizeof(Node));
	z->val = val;
	z->left = z->right = z->parent = NULL;
	return z;
}
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

int* Search(Node* root, int val)
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

int* Minimum(Node* root)
{
	Node* x = root;
	while(x->left!=NULL)
	{
		x=x->left;
	}
	return x->val;
}

int* Maximum(Node* root)
{
	Node* x = root;
	while(x->right!=NULL)
	{
		x=x->right;
	}
	return x->val;
}



