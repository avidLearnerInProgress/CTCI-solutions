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

bool findPath(Node *root, int n, vector<Node *> &path){
    if(root == NULL) return false;
    path.push_back(root);
    if(root->data == n)
        return true;
    if(findPath(root->left, n, path) || findPath(root->right, n, path)) return true;
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{   
    if(root == NULL) return -1;
    vector<Node *> path1, path2;
    if(!findPath(root, n1, path1) || !findPath(root, n2, path2))return -1;
    int i;
    for(i=0; i<path1.size() && i<path2.size(); i++){
        if(path1[i] != path2[i])
            break;          
    }
    return path1[i-1]->data;
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

Node* LCAv2(Node *root, int n1, int n2){
    if(root == NULL) return NULL;
    bool v1, v2;
    Node* res = findLCAUtil(root, n1, n2, v1, v2);
    if(v1 && v2)
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
    cout<<LCA(root, 3, 6)<<"\n";
    cout<<LCAv2(root, 2, 3)->data<<"\n";
}