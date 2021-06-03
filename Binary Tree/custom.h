// #include<iostream>

// // Add required elements in the node
// struct node {
// 	struct node* left;
// 	struct node* right;
// 	struct node* parent;
// 	int height;
// 	// Add other requried node elements



// };
// typedef struct node Node;

// Node* createNode(int val);
// int getKey(Node* root);
// void setKey(Node* root, int val);
// void augmentationUpdate(Node* root);

#include<iostream>
#include<limits>
using namespace std;
// Add required elements in the node
struct node {
	struct node* left;
	struct node* right;
	struct node* parent;
	int height;
	// Add other requried node elements

	int start,end,max;


};
typedef struct node Node;

Node* createNode(int n_par,int args[]);
int getKey(Node* root);
void setKey(Node* root, int args[]);
void augmentationUpdate(Node* root);
