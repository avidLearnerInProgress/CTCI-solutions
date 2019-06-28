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
Node* insertInTreeRec(Node* root, int data){
    if(root == NULL) return NULL;
    if(root->left == NULL){
        root->left = newNode(data);
        return root->left; 
    }
    else if(root->right == NULL){
        root->right = newNode(data);
        return root->right;
    }
    else{
        insertInTreeRec(root->left, data);
        insertInTreeRec(root->right, data);
    }
    return NULL;
}

//Non-recursive
void insertInTree(Node *root, int data){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left == NULL){
            curr->left = newNode(data);
            break;
            //return curr->left;
        }
        else
            q.push(curr->left);
        
        if(curr->right == NULL){
            curr->right = newNode(data);
            break;
            //return curr->right;
        }
        else
            q.push(curr->right);
    }
    return;
}

void inOrder(Node *root){
    if(root == NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    //if(insertInTree(root, 10) != NULL)
       // cout<<insertInTree(root, 10)->data;
    insertInTreeRec(root, 12);
    inOrder(root);
}