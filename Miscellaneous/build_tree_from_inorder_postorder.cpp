//https://ide.geeksforgeeks.org/BxtFjTjqXC
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
Value of root:-
1. Appears on first position in pre-order
2. Appears on last position in post-order
*/
/*
Leftmost node appears on first position in inorder
*/
Node *buildTree(char inOrder[], char postOrder[], unordered_map<char, int> mp, int start, int end){
    if(start > end) return NULL;
    static int postOrder_inx = end;
    char curr = postOrder[postOrder_inx];
    postOrder_inx--;
    Node *r = newNode(curr);
    if(start == end) return r;
    int inOrder_inx = mp[curr]; 
    r->right = buildTree(inOrder, postOrder, mp, inOrder_inx+1, end);
    r->left = buildTree(inOrder, postOrder, mp, start, inOrder_inx-1);
    return r;
}

Node* constructTree(char inOrder[], char postOrder[], int len){
    unordered_map<char, int> mp;
    for(int i=0; i<len; i++){
        mp[inOrder[i]] = i;
    }
    int start = 0, end = len-1;
    return buildTree(inOrder, postOrder, mp, start, end);
}

int main(){
    char inOrder[6] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char postOrder[6] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int pre_sz = sizeof(postOrder)/sizeof(postOrder[0]);
    Node *xz = constructTree(inOrder, postOrder, pre_sz);
    inorder(xz);
}