//https://ide.geeksforgeeks.org/ly0htMIzxJ
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

//Min-max approach
//On left move update max, on right move update min
bool validateBST(Node *root, int min, int max){
    if(root == NULL) return true;

    if((min != -1 && root->data <= min) || (max != -1 && root->data > max))
    return false;

    if(!(validateBST(root->left, min, root->data)) || !(validateBST(root->right, root->data, max)))
    return false;

    return true;
}

bool checkBST(Node *root){
    return validateBST(root, -1,-1);
}

int main(){
    Node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    cout<<checkBST(root)<<"\n";
}