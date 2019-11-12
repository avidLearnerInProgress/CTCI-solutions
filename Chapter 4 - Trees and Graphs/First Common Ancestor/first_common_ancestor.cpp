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

Node *findLCA(Node *root, int p, int q, bool visited1, bool visited2){
    if(!root) return NULL;
    //visited booleans are needed to ensure that if p is present and q is not; then p is not returned as the LCA.
    //devoid of visited, the above scenario takes place.

    if(root->data == p){
        visited1 = true;
        return root;
    }
    if(root->data == q){
        visited2 = true;
        return root;
    }
    Node *lLCA = findLCA(root->left, p, q, visited1, visited2);
    Node *rLCA = findLCA(root->right, p, q, visited1, visited2);

    if(visited1 && visited2) return root;
    return lLCA ? lLCA : rLCA;
}

bool find(Node *root, int k){
    if(!root) return false;
    if(root->data == k)return true;
    if(find(root->left, k) || find(root->right, k)) return true; //check for the left and right subtree
    return false;
}

Node* LCA(Node *root, int p, int q){
    if(!root) return NULL;
    bool v1 = false, v2 = false;
    Node *lca = findLCA(root, p, q, v1, v2);
    //if v1 and v2 are returned true; it means that nodes with data p and q are in different subtrees
    if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1)) // conditions with || are needed if q is just below p in the same sub-tree
        return lca;
    else return NULL;
}

int main(){
    Node *root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->left->left->left = newNode(45);
    root->left->left->right = newNode(4);
    Node *p = root->left->left->left;
    Node *q = root->left->left->left;
    cout<<LCA(root, p->data, q->data)->data<<"\n";
}