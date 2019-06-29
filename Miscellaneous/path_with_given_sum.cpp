//https://ide.geeksforgeeks.org/hVsJkaT2vQ
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
bool pathWithGivenSumRec(Node *root, int sum){
    if(root == NULL) return (sum == 0);
    int rsum = sum - root->data;
    if(root->left and root->right || (!root->left and !root->right)) 
    return pathWithGivenSumRec(root->left, rsum) || pathWithGivenSumRec(root->right, rsum);
    //if(root->left = NULL) return pathWithGivenSumRec(root->right, rsum);
    //if(root->right == NULL) return pathWithGivenSumRec(root->left, rsum);
    else if(root->left)
    return pathWithGivenSumRec(root->left, rsum) ;
    else
    return pathWithGivenSumRec(root->right, rsum);
}

//non-recursive
bool pathWithGivenSum(Node *root, int sum){
    if(root == NULL) return sum == 0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *top = q.front();
        q.pop();
        int rsum = sum - top->data;
        if(rsum == 0) return 1; //path found in tree
        else{
            if(top->left)
            q.push(top->left);
            if(top->right)
            q.push(top->right);
        }
    }
    return false;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<pathWithGivenSum(root, 10)<<"\n";
    cout<<pathWithGivenSumRec(root, 10)<<"\n";
}