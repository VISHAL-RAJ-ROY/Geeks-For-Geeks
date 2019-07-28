/*
Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. 
A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.
For example, consider the following binary tree.
*/
#include <iostream>
#include <cstdio>
using namespace std;

int ct = 0;

class node  
{  
    public: 
    int data;  
    node *left, *right;  
}; 

int dfs( node * root ) {
    if( !root ) return 2;
    int l = dfs(root->left), r = dfs(root->right);
    if( l == 0 || r == 0 ) {
        return 1;
    }
    if( l == 1 || r == 1 ) {
        ct++;
        return 2;
    }
    ct++; return 0;
}

node* newNode( int data )  
{  
    node* temp = new node(); 
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
}  

int main() {
    node *root = newNode(20);  
    root->left = newNode(8);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
    root->right = newNode(22);  
    root->right->right = newNode(25); 
    cout<<(dfs(root) < 1 ? 1 : 0) + ct<<"\n";
	return 0;
}
