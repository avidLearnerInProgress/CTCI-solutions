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

bool pathWithGivenSumRec(Node *root, int sum){
    if(root == NULL) return false;
    if(sum == root->data && root->left == NULL && root->right == NULL)
        return true;
    return pathWithGivenSumRec(root->left, sum - root->data) || pathWithGivenSumRec(root->right, sum - root->data);
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<pathWithGivenSumRec(root, 10)<<"\n";
}