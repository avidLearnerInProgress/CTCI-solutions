//https://ide.geeksforgeeks.org/nSkzSzzMM6
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

int maxSumPerLevel(Node *root){
    if(root == NULL) return 0;
    Node *curr, *temp;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int max_sum = INT_MIN, level = 1, sum = 0, max_level = 0;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr == NULL){
            if(sum > max_sum){
                max_sum = sum;
                max_level = level;
            }
            sum = 0;
            if(!q.empty())q.push(NULL);
            level++;
        }
        else{
            sum += curr->data;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return max_sum;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<maxSumPerLevel(root)<<"\n";
}