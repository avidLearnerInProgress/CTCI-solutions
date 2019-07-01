//https://ide.geeksforgeeks.org/NbkbzGY7PD
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node *left, *right;
};

Node *newNode(char data){
    Node *curr = new Node();
    curr->data = data;
    curr->left = curr->right = NULL;
    return curr;
}
 
void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

/*
1. Hash preorder chars with char as key and their position in preorder as value, start =0, end =last-1;
2. for each char in preorder -
    find its equivalent position from inorder --> ind
    recursively build tree around root->left and root->right. For left : (start, ind-1) ||  For right: (ind+1, end)
*/

Node *buildTree(char inOrder[], char preOrder[], unordered_map<char, int> mp, int start, int end){
    if(start > end) return NULL;
    static int preorder_inx = 0;
    char curr = preOrder[preorder_inx];
    preorder_inx++;
    Node *r = newNode(curr);
    if(start == end) return r;
    int inorder_inx = mp[curr]; 
    r->left = buildTree(inOrder, preOrder, mp, start, inorder_inx-1);
    r->right = buildTree(inOrder, preOrder, mp, inorder_inx+1, end);
    return r;
}


Node* constructTree(char inOrder[], char preOrder[], int len){
    
    unordered_map<char, int> mp;
    for(int i=0; i<len; i++){
        mp[inOrder[i]] = i;
    }
    int start = 0, end = len-1;
    return buildTree(inOrder, preOrder, mp, start, end);
}

int main(){
    char inOrder[6] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char preOrder[6] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int pre_sz = sizeof(preOrder)/sizeof(preOrder[0]);
    Node *xz = constructTree(inOrder, preOrder, pre_sz);
    inorder(xz);
}