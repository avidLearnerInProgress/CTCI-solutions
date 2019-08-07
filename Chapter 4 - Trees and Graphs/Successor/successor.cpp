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

/*
if right subtree is present for a node:-
    return leftmost child of right subtree
else:
    while n is right child of parent:
        traverse up
    return n.parent //parent has yet not been traversed
 */

Node *leftMostOfRight(Node *n){
    if(n == NULL) return NULL;
    while(n->left != NULL)
        n = n->left;
    return n;
}

Node *rightMost(Node *n){
    if(n == NULL)  return NULL;
    while(n->right != NULL)
        n = n->right;
    return n;
}


Node *temp = new Node;

Node *findParent(Node *n, Node *x){
    if(!n) return NULL;
    if(n == x || (temp = findParent(n->left, x)) || (temp = findParent(n->right, x) ))
    {
        if(temp){
            if(n->left == temp){
                cout<<n->data<<"\n";
                return NULL;
            }
        }
        return n;
    }
    return NULL;
}

void inorderSuccessor(Node *n, Node *x){
    //if right is not null
    if(n->right != NULL){
        Node *is = leftMostOfRight(n->right);
        cout<<is->data<<"\n";
    }
    
    //if right is null
    else{
        Node *right = rightMost(n);
        if(right == x)
            cout<<"Not possible\n";
        else{
            findParent(n, x);
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
    inorderSuccessor(root, root->left);
}