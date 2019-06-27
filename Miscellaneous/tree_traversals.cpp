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

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

int getHeight(Node *root){
    if(root == NULL) return 0;
    return max(1 + getHeight(root->left), 1 + getHeight(root->right));
}

void printCurrentLevel(Node *root, int current){
    if(root == NULL)return;
    if(current==1)cout<<root->data<<" ";
    else if(current>1){
        printCurrentLevel(root->left, current-1);
        printCurrentLevel(root->right, current-1);
    }
}

void levelOrder(Node *root){
    int h = getHeight(root);
    if(h==0)return;

    for(int i=1; i<=h; i++){
        printCurrentLevel(root, i);
    }
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    levelOrder(root);
}