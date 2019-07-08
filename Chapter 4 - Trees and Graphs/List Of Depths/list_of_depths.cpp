//https://ide.geeksforgeeks.org/BvwxQrFKmN
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

//Non-recursive
void levelOrder(Node *root){
    if(root == NULL)return;
    queue<Node *> q;
    vector<Node *> level;
    q.push(root);
    q.push(NULL);
    int height = 1;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
                height++;
            }
            for(auto x=0; x<level.size(); x++)
                if(x == level.size() - 1)
                    cout<<level[x]->data<<"\n";
                else
                    cout<<level[x]->data<<"->";
            level.clear();
        }
        else{
            level.push_back(curr);
            if(curr->left) 
                q.push(curr->left);
            if(curr->right) 
                q.push(curr->right);
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
    levelOrder(root);
}