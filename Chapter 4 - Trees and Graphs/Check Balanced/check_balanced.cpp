//https://ide.geeksforgeeks.org/fPKHhbbGDb
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

int getHeight(Node *root){
    if(!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

//Non optimised. We calculate height at each node and then recurse for balancing aspect. 
bool checkBalanced(Node *root){
    if(!root) return true;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    int hDiff = abs(lHeight - rHeight);
    if(hDiff > 1)
        return false;
    else
        return checkBalanced(root->left) && checkBalanced(root->right);
}

//Not needed, lets do the recusrive actions along with calculating heights
int checkBalancedAndCalHeight(Node *root){
    if(!root) return -1;
    int lHeight = checkBalancedAndCalHeight(root->left);
    if(lHeight == INT_MIN) return INT_MIN;
    int rHeight = checkBalancedAndCalHeight(root->right);
    if(rHeight == INT_MIN) return INT_MIN;

    int hDiff = abs(lHeight - rHeight);
    if(hDiff > 1)
        return INT_MIN;
    else
        return 1 + max(lHeight, rHeight);
}

bool checkBalancedOptimised(Node *root){
    return checkBalancedAndCalHeight(root) != INT_MIN;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<checkBalanced(root)<<"\n";
    cout<<checkBalancedOptimised(root)<<"\n";
}