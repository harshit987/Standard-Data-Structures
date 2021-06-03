#include<iostream>
#include "avl_update.h"
#define COUNT 10 
void print2DUtil(Node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->start<<"\n"; 
  
    // Process left child 
    print2DUtil(root->left, space); 

} 

int main()
{
	int arr[] = {1,2};
	Node* root = createNode(2,arr);
	// cout << root->start << " " << root->end << " "<<root->max << endl;
	print2DUtil(root,0);
	cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

	arr[0] = 2;
	arr[1] = 3;
	Node* z = createNode(2,arr);
	root = avl_insert(root,z);
	print2DUtil(root,0);
	cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	// cout << root->start << " " << root->end << " "<<root->max << endl;
	arr[0] = -1;
	arr[1] = 4;
	z = createNode(2,arr);
	root = avl_insert(root,z);
	print2DUtil(root,0);
	cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	// cout << root->start << " " << root->end << " "<<root->max << endl;
	arr[0] = 1.5;
	arr[1] = 3;
	z = createNode(2,arr);
	root = avl_insert(root,z);
	cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	// cout << root->start << " " << root->end << " "<<root->max<<endl;
	print2DUtil(root,0);
	arr[0] = 1.4;
	arr[1] = 3;
	z = createNode(2,arr);
	root = avl_insert(root,z);
	print2DUtil(root,0);
	cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	// cout << root->start << " " << root->end << " "<<root->max << endl;
	return 0;
}