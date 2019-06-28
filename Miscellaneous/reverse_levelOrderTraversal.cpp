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

void reverse_levelOrderTraversal(Node *root)
{
    if(root == NULL)return;
    queue<Node*> q; stack<Node *> s;
    q.push(root);
    while(q.empty() == false){
        Node* current = q.front();
        s.push(current);
        q.pop();
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    reverse_levelOrderTraversal(root);
    
}