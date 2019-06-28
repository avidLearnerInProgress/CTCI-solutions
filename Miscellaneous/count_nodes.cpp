//https://ide.geeksforgeeks.org/c7Z5Z9kWZT
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

void levelOrderCount(Node *root)
{
    if(root == NULL)return;
    queue<Node*> q;
    int cnt = 0;
    q.push(root);
    while(q.empty() == false){
        Node* current = q.front();
        //cout<<current->data<<" ";
        cnt++;
        q.pop();
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
    cout<<cnt<<"\n";
}



int levelOrderCountRec(Node *root)
{
    if(root == NULL)return 0;
    else return 1 + levelOrderCountRec(root->left) + levelOrderCountRec(root->right);
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    levelOrderCount(root);
    cout<<levelOrderCountRec(root);
}