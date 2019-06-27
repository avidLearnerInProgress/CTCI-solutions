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

void inorder(Node *root){
    //First push everything in stack moving left (L)
    //As there is no leftmost //pop the current (V)
    //Go on right and perform same (R)
    if(root == NULL) return;
    stack<Node *> s;
    Node *curr = root;
    while(!s.empty() && curr != NULL){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void preorder(Node *root){
    if(root == NULL) return;
    stack<Node *> s;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
}

//Two stacks
void postorder(Node *root){
    //Another stack ensures that instead of going for VLR (pre-order) we take the V 
    //and push it in another stack to guarantee RLV (Also, here left is pushed first and then right so we have right out first)
    //LIFO ensures that V occurs at the end and first L and R are looked into
    if(root == NULL) return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while(!s1.empty()){
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)
            s1.push(curr->left);
        if(curr->right)
            s1.push(curr->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

//1stack
void postorder1(Node *root){
    if(root == NULL) return;
    stack<Node *> s;
    Node *curr = root;
    while(1){
        while(curr != NULL){
            s.push(curr);
            s.push(curr);
            curr = curr->left;
        }
        if(s.empty()) return;
        curr = s.top();
        s.pop();
        if(!s.empty() && s.top() == curr)curr = curr->right;
        else{
            cout<<curr->data<<" ";
            curr = NULL;
        }
    }
    
}

int getHeight(Node *root){
    if(root == NULL) return 0;
    return max(1 + getHeight(root->left), 1 + getHeight(root->right));
}

void levelOrder(Node *root)
{
    if(root == NULL)return;
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false){
        Node* current = q.front();
        cout<<current->data<<" ";
        q.pop();
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);
    postorder(root);
    postorder1(root);
    preorder(root);
    inorder(root);
}