//https://ide.geeksforgeeks.org/elbhFhdSAG
#include <bits/stdc++.h> // Include every standard library 
using namespace std; 
typedef long long LL; 
typedef pair<int, int> pii; 
typedef pair<LL, LL> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<LL> vl; 
typedef vector<vl> vvl; 

double EPS=1e-9; 
int INF=1000000005; 
long long INFF=1000000000000000005LL; 
double PI=acos(-1); 
int dirx[8]={ -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8]={ 0, 1, -1, 0, -1, 1, -1, 1 }; 

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define FOR(a, b, c) for (int(a)=(b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a)=(b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a)=(b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a)=(b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a)=(b); (a) <= (c); ++(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define MAX(a, b) a=max(a, b) 
#define MIN(a, b) a=min(a, b) 
#define SQR(x) ((LL)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SIZE(v) (int)v.size() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define PERMUTE next_permutation 
#define TC(t) while (t--) 
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

struct Node{
    int data;
    struct Node *next;
};

Node* createNode(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printLL(Node *head){
    if(head == NULL)return;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int countLL(Node *head){
    if(head == NULL)return 0;
    int node_count = 0;
    while(head != NULL){
        node_count++;
        head = head->next;
    }
    return node_count;
}

Node *insertNode(int data, Node *head){
    Node *newNode = createNode(data);
    if(head == NULL)
        head = newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node *insertNodeEnd(int data, Node *head)
{
	Node *newNode=createNode(data);
	Node *traverse=head;
	if(head==NULL){
		newNode->next=NULL;
		head=newNode;
		return head;
	}
	while(traverse->next!=NULL)
		traverse=traverse->next;
	traverse->next=newNode;
	newNode->next=NULL;
	return head;
}

/* 
Here we perform LL addition as the numbers appear in the input
The size of both the LL's matter here because the hundredth's place is on left followed by unit's to the right

3 2 1 -A
8 9 6 -B

4 5 6 -C
8 9   -D

A and B has no issues. C and D will have a problem as 8 gets aligned to hundredth's place.
However its actual place value is tens place
*/

Node *addition_same_sz(Node *head1, Node* head2, int *carry){
    if(head1 == NULL || head2 == NULL)return NULL;
    int sum;
    Node *result = new Node();
    result->next = addition_same_sz(head1->next, head2->next, carry);
    sum = head1->data + head2->data + *carry;
    *carry = sum/10;
    sum = sum % 10;
    result->data = sum;
    return result;
}

void swapHeads(Node **a, Node **b){
    Node *t = *a;
    *a = *b;
    *b = t;
}

void push(struct Node** head_ref, int new_data) 
{ 
    Node *new_node = new Node();
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

void add_carry_to_remaining(Node *head1, Node *curr, int *carry, Node **result){
    int sum;
    if(head1 != curr){
        add_carry_to_remaining(head1->next, curr, carry, result);
        sum = head1->data + *carry;
        *carry = sum/10;
        sum %= 10;
    }
    push(result, sum);
}

void addition_by_lists_forward(Node *head1, Node *head2, Node **result){
    if(head1 == NULL){
        *result = head2;
        return;
    }
    if(head2 == NULL)
    {
        *result = head1;
        return;
    }
    Node *curr;
    int length1 = countLL(head1);
    int length2 = countLL(head2);
    int carry = 0;

    if(length1 == length2){
        *result = addition_same_sz(head1, head2, &carry);
    }

    else{
        int diff = abs(length1 - length2);
        if(length1 < length2){
            swapHeads(&head1, &head2);
        }
        curr = head1;
        while(diff--)
            curr = curr->next;
        
        *result = addition_same_sz(curr, head2, &carry);
        add_carry_to_remaining(head1, curr, &carry, result);
    }

    if(carry)
        push(result, carry);
}

int main(){
    Node *head1 = NULL, *head2 = NULL;
    int m, n, data, i; 
    cin>>m>>n;
    FOR(i, 0, m){
        cin>>data;
        head1 = insertNodeEnd(data, head1);
    }
    
    FOR(i, 0, n){
        cin>>data;
        head2 = insertNodeEnd(data, head2);
    }
    Node *result = NULL;
    addition_by_lists_forward(head1, head2, &result);
    printLL(result);
}