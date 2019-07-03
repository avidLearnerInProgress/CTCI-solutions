//https://ide.geeksforgeeks.org/wzItSDJ5Gd
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
 
void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *constructTree(int parent[], int n){
    
    map<int, Node*> mp;
    Node *temp, *root;

    for(int i=0; i<n; i++){
        if(mp.find(i) == mp.end()){
            temp = newNode(i);
            mp[i] = temp;
        }
        if(parent[i] == -1){
            root = mp[i];
        }
        else if(mp.find(parent[i]) == mp.end()){
            temp = newNode(parent[i]);
            temp->left = mp[i];
            mp[parent[i]] = temp;
        }
        else{
            if(!mp[parent[i]]->left)
                mp[parent[i]]->left = mp[i];
            else
            mp[parent[i]]->right = mp[i];
        }
    }
    return root;
}

int main(){
    int inOrder[7] = {1, 5, 5, 2, 2, -1, 3};
    int lv_sz = sizeof(inOrder) / sizeof(inOrder[0]);
    Node *xz = constructTree(inOrder, lv_sz);
    inorder(xz);
}