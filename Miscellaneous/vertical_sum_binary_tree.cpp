//https://ide.geeksforgeeks.org/49difnOn5x
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

void vertical_sum_util(Node *root, map<int, int> &mp, int h){
    if(root->left)
        vertical_sum_util(root->left, mp, h-1);
    
    mp[h] += root->data;
    
    if(root->right)
        vertical_sum_util(root->right, mp, h+1);
}

void vertical_sum_tree(Node *root){
    if(!root) return;
    int h = 0;
    map<int, int> mp;
    vertical_sum_util(root, mp, h);
    for(auto it=mp.begin(); it!=mp.end(); it++)
        cout<<it->second<<"-->"<<it->first<<"\n";
    
}
int main(){
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    vertical_sum_tree(root);
}