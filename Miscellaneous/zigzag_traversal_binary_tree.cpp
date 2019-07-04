//
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

void traverse_zigzag(Node *root){
    if(!root) return;
    stack<Node*> cLevel, nLevel;
    cLevel.push(root);
    bool lToR = true;
    while(!cLevel.empty()){
        Node *top = cLevel.top();
        cLevel.pop();
        if(top){
            cout<<top->data<<" ";
            if(lToR){
                nLevel.push(top->left);
                nLevel.push(top->right);
            }
            else{
                nLevel.push(top->right);
                nLevel.push(top->left);
            }
        }
        if(!cLevel.empty()){
            lToR = !lToR;
            swap(cLevel, nLevel);
        }
    }
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    traverse_zigzag(root);
}