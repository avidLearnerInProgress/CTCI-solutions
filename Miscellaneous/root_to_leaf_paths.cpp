//https://ide.geeksforgeeks.org/6VVrDyB2s4
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

void printPath(int paths[], int len){
    for(int i=0; i<len; i++)
        cout<<paths[i]<<" ";
    cout<<"\n";
}

void rootToLeafPaths(Node *root, int paths[], int len){
    if(root == NULL) return;
    paths[len] = root->data;
    len++;
    if(root->left == NULL and root->right == NULL)
        printPath(paths, len);
    else{
        rootToLeafPaths(root->left, paths, len);
        rootToLeafPaths(root->right, paths, len);
    }
}

void wrapper(Node *root){
    if(root == NULL) return;
    int paths[1000];
    int len = 0;
    rootToLeafPaths(root, paths, len);
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    wrapper(root);
}