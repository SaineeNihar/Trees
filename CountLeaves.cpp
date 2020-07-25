#include<bits/stdc++.h> 
using namespace std; 
class Node 
{ 
	public:
    int data; 
	Node* left, *right; 
}; 
Node *newNode(int data) 
{ 
	Node *newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return (newNode); 
} 
int findLeaves(Node *root)
{
    if(!root)
        return 0;
    if(!root->left and !root->right)
        return 1;       
    int a=findLeaves(root->left);
    int b=findLeaves(root->right);
    return a+b;
}

int main(void) 
{ 
	Node *root = newNode(10); 
	root->left	 = newNode(2); 
	root->right	 = newNode(10); 
	root->left->left = newNode(20); 
	root->left->right = newNode(1); 
	root->right->right = newNode(-25); 
	root->right->right->left = newNode(3); 
	root->right->right->right = newNode(4); 
	cout << "Count is " << findLeaves(root); 
	return 0; 
} 
