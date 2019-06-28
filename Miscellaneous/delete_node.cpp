//https://ide.geeksforgeeks.org/zoqtHL4vFa
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

void deleteDeepest(Node *root, Node* deepest_node){
    if(root == NULL || deepest_node == NULL) return;
    queue<Node *> q;
    q.push(root);
    Node *curr;

    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr == deepest_node){
            curr = NULL;
            delete deepest_node;
            return;
        }
        if(curr->right){
            if(curr->right == deepest_node){
                curr->right = NULL;
                delete deepest_node;
                return;
            }else{
                q.push(curr->right);
            }
        }
        if(curr->left){
            if(curr->left == deepest_node){
                curr->left = NULL;
                delete deepest_node;
                return;
            }else{
                q.push(curr->left);
            }
        }
    }
}

Node* deleteNode(Node* root, int todelete){
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
        if(root->data == todelete)
            return NULL;
        else
            return root;
    }
    else{
        queue<Node *> q;
        q.push(root);
        Node *key, *curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr->data == todelete){
                key = curr;
            }
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        if(key != NULL){
            int k = curr->data;
            deleteDeepest(root, curr);
            key->data = k;
        }
        return root;
    }
    return NULL;
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