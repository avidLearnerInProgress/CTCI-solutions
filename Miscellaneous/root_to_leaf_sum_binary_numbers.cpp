//https://ide.geeksforgeeks.org/6VVrDyB2s4
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

int to_dec(string n) 
{ 
    int res = 0, base = 1;
    int len = n.length(); 
    for (int i = len-1; i>=0; i--) { 
        if (n[i] == '1') 
            res += base; 
        base = base*2; 
    } 
    return res;
} 

//sum of root to leaf paths binary numbers
int rootToLeafPathIterative(Node *root){
    if(!root) return 0;
    stack<pair<Node *, string>> st;
    int ans = 0;
    st.push(make_pair(root, to_string(root->data)));
    while(!st.empty()){
        pair<Node*, string> n = st.top();
        st.pop();
        if(n.first->left == NULL && n.first->right == NULL){
            ans += to_dec(n.second);
            continue;
        }
        if((n.first)->left)
            st.push(n.first->left, n.second + to_string((n.first->left)->data));
        if((n.first)->right)
            st.push(n.first->right, n.second + to_string((n.first->right)->data));
    }
    return ans;
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(1);
    root->left->left = newNode(1);
    root->left->right = newNode(0);
    root->right->left = newNode(1);
    root->right->right = newNode(0);
    cout<<rootToLeafPathIterative(root)<<"\n";
}
