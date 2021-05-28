#include<iostream>
struct node {
	int val;
	struct node* left;
	struct node* right;
	struct node* parent;
	int height;
};
typedef struct node Node;
