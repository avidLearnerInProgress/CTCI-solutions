//https://ide.geeksforgeeks.org/y77j6rFI5L
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

Node *bstFromArray(const vector<int> arr, int start, int end){
        if(start > end) return NULL;

        int mid = (start + end) / 2;
        Node *current = newNode(arr[mid]);
        current->left = bstFromArray(arr, start, mid - 1);
        current->right = bstFromArray(arr, mid + 1, end);
        return current;
}

void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);    
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *root = bstFromArray(arr, 0, arr.size() - 1);
    inOrder(root);
}