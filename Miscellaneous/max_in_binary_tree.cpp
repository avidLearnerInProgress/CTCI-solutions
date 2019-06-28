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
int maxInTreeRec(Node *root){
    if(root == NULL) return 0;
    int max_val = INT_MIN;
    int left = maxInTreeRec(root->left);
    int right = maxInTreeRec(root->right);
    max_val = max(max_val, max(left, max(right, root->data)));
    return max_val;
}

//Non-recursive
void maxInTree(Node *root){
    if(root == NULL)return;
    queue<Node *> q;
    q.push(root);
    int max = INT_MIN;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr->data > max)
            max = curr->data;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout<<max<<"\n";
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    maxInTree(root);
    cout<<maxInTreeRec(root);
}