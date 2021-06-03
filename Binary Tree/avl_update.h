#include<iostream>
#include "update.h"
using namespace std;
Node* left_rotate(Node** root,Node* x);
Node* right_rotate(Node** root,Node* x);
int getHeight(Node* root);
Node* avl_insert(Node* root,Node* x);
Node* avl_delete(Node* root, Node* z);
