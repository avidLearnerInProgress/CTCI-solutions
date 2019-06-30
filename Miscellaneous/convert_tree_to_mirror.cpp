//
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

//recursive
Node* convertMirror(Node *root){
    if(root == NULL) return NULL;
    convertMirror(root->left);
    convertMirror(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    Node *tp = convertMirror(root);
    inOrder(tp);
}