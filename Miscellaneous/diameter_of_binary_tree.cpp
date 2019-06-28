//https://ide.geeksforgeeks.org/D6HPBHA2Gc
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

int height(Node *root){
    if(root == NULL) return 0;
    return(1 + max(height(root->left), height(root->right)));
}

int diameter(Node *root){
    if(root == NULL)return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiam = diameter(root->left);
    int rdiam = diameter(root->right);
    return max(lheight + rheight + 1, max(ldiam, rdiam));
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<diameter(root)<<"\n";
}