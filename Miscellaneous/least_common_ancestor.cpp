//https://ide.geeksforgeeks.org/PhWfDTcPYG
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

bool findPath(Node *root, int n, vector<Node *> &path){
    if(root == NULL) return false;
    path.push_back(root);
    if(root->data == n)
        return true;
    if(findPath(root->left, n, path) || findPath(root->right, n, path)) return true;
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{   
    if(root == NULL) return -1;
    vector<Node *> path1, path2;
    if(!findPath(root, n1, path1) || !findPath(root, n2, path2))return -1;
    int i;
    for(i=0; i<path1.size() && i<path2.size(); i++){
        if(path1[i] != path2[i])
            break;          
    }
    return path1[i-1]->data;
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<LCA(root, 3, 6)<<"\n";
}