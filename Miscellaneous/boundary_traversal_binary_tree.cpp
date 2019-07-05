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

//Boundary traversal goes in top to bottom fashion on left --> all leaves --> bottom to top fashion on right
void traverseLeft(Node *root){
    if(!root) return;
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            traverseLeft(root->left);
        }
        else if(root->right){
            cout<<root->data<<" ";
            traverseLeft(root->right);
        }
    }
}

//Boundary traversal goes in top to bottom fashion on left --> all leaves --> bottom to top fashion on right
void traverseRight(Node *root){
    if(!root) return;
    if(root){
        if(root->left){
            traverseRight(root->left);
            cout<<root->data<<" ";
        }
        else if(root->right){
            traverseRight(root->right);
            cout<<root->data<<" ";
        }
    }
}

void traverseLeaves(Node *root){
    if(!root) return;
    else{
        traverseLeaves(root->left);
        if(!(root->left) && !(root->right)){
            cout<<root->data<<" ";
        }
        traverseLeaves(root->right);
    }
}

void boundary_traversal(Node *root){
    if(!root) return;
    else{
        cout<<root->data<<" ";
        traverseLeft(root->left);
        traverseLeaves(root->left);
        traverseLeaves(root->right);
        traverseRight(root->right);
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
    boundary_traversal(root);
    cout<<"\n";
}