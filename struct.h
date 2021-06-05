#include<iostream>
struct node {
	int val;
	struct node* left;
	struct node* right;
	struct node* parent;
	int height;
};
typedef struct node Node;

Node* createNode(int val)
{
	Node* z = (Node*) malloc(sizeof(Node));
	z->val = val;
	z->left = z->right = z->parent = NULL;
	z->height = 0;
	return z;
}
