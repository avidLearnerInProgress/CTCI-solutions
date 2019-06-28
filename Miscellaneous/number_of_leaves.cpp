//https://ide.geeksforgeeks.org/bEmseDwEzG
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
int numberOfLeavesRec(Node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else{
        return numberOfLeavesRec(root->left) + numberOfLeavesRec(root->right);
    }
}

//non-recursive
int numberOfLeaves(Node *root){
    if(root == NULL) return 0;
    Node *curr;
    queue<Node *> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        curr = q.front(); q.pop();
        if(curr->left == NULL && curr->right == NULL){
            count+=1;
        }
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    return count;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<numberOfLeaves(root)<<"\n";
    cout<<numberOfLeavesRec(root)<<"\n";
}