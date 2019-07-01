//https://ide.geeksforgeeks.org/8SYiLF9XI3
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
};

Node *newNode(int data){
    Node *curr = new Node();
    curr->data = data;
    curr->left = curr->right = NULL;
    return curr;
}

int printAncestors(Node *node, int data){
    if(node == NULL) return 0;
    if((node->left->data == data) || (node->right->data == data) || printAncestors(node->left, data) || printAncestors(node->right, data)){
        cout<<node->data<<"\n";
        return 1;
    }
    return 0;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<printAncestors(root, 5)<<"\n";    
}