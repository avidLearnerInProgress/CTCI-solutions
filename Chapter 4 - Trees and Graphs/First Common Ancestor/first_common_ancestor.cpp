//https://ide.geeksforgeeks.org/KXWdLMTV8d
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

Node *findLCAUtil(Node *root,int n1,int n2,bool &v1,bool &v2){
	if(root == NULL)return NULL;
	if(root->data == n1){
		v1 = true;
		return root;
	}
	if(root->data == n2){
		v2 = true;
		return root;
	}
	Node *lca = findLCAUtil(root->left,n1,n2,v1,v2);
	Node *rca = findLCAUtil(root->right,n1,n2,v1,v2);
	if(lca && rca)return root;
	return(lca!=NULL)?lca:rca;
}

bool find(Node *root, int k){
    if(root == NULL) return NULL;
    if(root->data == k) return root;
    
    if(find(root->left, k) || find(root->right, k)) return true;
    return false;
    
}

Node* LCA(Node *root, int n1, int n2){
    if(root == NULL) return NULL;
    bool v1, v2;
    Node* res = findLCAUtil(root, n1, n2, v1, v2);
    if(v1 && v2 || v1 && find(res, v2) || v2 && find(res, v1))
        return res;
    else
        return NULL;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<LCA(root, 4, 5)->data<<"\n";