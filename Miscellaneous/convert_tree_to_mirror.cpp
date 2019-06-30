//https://ide.geeksforgeeks.org/S4RimM71BC
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
Node* convertMirror(Node *root){
    if(root == NULL) return NULL;
    convertMirror(root->left);
    convertMirror(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool checkMirror(Node *r1, Node *r2){
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    //if(r1->data != r2->data) return false;
    else return r1->data == r2->data && checkMirror(r1->left, r2->right) && checkMirror(r1->right, r2->left);
}

int main(){
    Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 
    cout<<checkMirror(a, b)<<"\n";
    Node *tp = convertMirror(a);
    inOrder(tp);
}