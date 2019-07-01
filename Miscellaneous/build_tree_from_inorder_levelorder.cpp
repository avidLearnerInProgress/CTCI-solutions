//https://ide.geeksforgeeks.org/79dKradnB5
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
1. leftmost in levelorder is root
*/
Node *constructTree(char inOrder[], char levelOrder[], int start, int end, int n){
    if(start > end) return NULL;
    char r = levelOrder[0]; //this is root
    Node *root = newNode(levelOrder[0]);
    int index = -1;
    for(int i=start; i<=end; i++){
        if(inOrder[i] == r){
            index = i;
            break;
        }
    }
    if(index == -1) return NULL;

    unordered_set<char> s;
    for(int i=start; i<index; i++){
        s.insert(inOrder[i]);
    }

    char lleft[s.size()], rright[end - start - s.size()];
    int a = 0, b = 0;

    for(int i=1; i<n; i++){
        if(s.find(levelOrder[i]) != s.end())
            lleft[a++] = levelOrder[i];
        else
            rright[b++] = levelOrder[i];
    }
    root->left = constructTree(inOrder, lleft, start, index-1,  index-start );
    root->right = constructTree(inOrder, rright, index+1, end,  end-index );
    return root;
}

int main(){
    char inOrder[6] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char levelOrder[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int lv_sz = sizeof(inOrder) / sizeof(inOrder[0]);
    Node *xz = constructTree(inOrder, levelOrder, 0, lv_sz-1, lv_sz);
    inorder(xz);
}