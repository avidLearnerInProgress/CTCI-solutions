//https://ide.geeksforgeeks.org/o9WfoOwWrP
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
        if(cLevel.empty()){
            lToR = !lToR;
            swap(cLevel, nLevel);
        }
    }
}

int height(Node *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printLToR(Node *root, int level){
    if(root == NULL) return;
    if(level == 1) cout<<root->data<<" ";
    else if(level > 1){
        printLToR(root->left, level-1);
        printLToR(root->right, level-1);
    }
}

void printRToL(Node *root, int level){
    if(root == NULL) return;
    if(level == 1) cout<<root->data<<" ";
    else if(level > 1){
        printRToL(root->right, level-1);
        printRToL(root->left, level-1);
    }
}

void traverse_zigzag_rec(Node *root){
    if(root == NULL) return;
    int h = height(root);
    bool flag = false;

    for(int i=1; i<=h; i++){
        if(!flag){
            printLToR(root, i);
            flag = true;
        }
        else{
            printRToL(root, i);
            flag = false;
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
    cout<<"\n";
    traverse_zigzag_rec(root);
}