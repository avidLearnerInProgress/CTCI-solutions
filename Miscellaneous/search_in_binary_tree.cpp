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
bool searchInTreeRec(Node* root, int data){
    if(root == NULL) return 0;
    if(root->data == data)return 1;
    bool res = searchInTreeRec(root->left, data);
    if(!res)
        return searchInTreeRec(root->right, data);
    else
        return res; 
}

//Non-recursive
bool searchInTree(Node *root, int data){
    if(root == NULL)return 0;
    if(root->data == data)return 1;
    bool found = false;
    queue<Node *> q;
    q.push(root);
    int max = INT_MIN;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr->data == data) return 1;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
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
    cout<<searchInTree(root, 10);
    cout<<searchInTreeRec(root, 6);
}