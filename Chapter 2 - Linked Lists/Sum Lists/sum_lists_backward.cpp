//https://ide.geeksforgeeks.org/9tF9U5WhpC
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

void countLL(Node *head){
    if(head == NULL)return;
    int node_count = 0;
    while(head != NULL){
        node_count++;
        head = head->next;
    }
}

Node *insertNode(int data, Node *head){
    Node *newNode = createNode(data);
    if(head == NULL)
        head = newNode;
    else{
        head->next = newNode;
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
Least significant digit(Unit's place) --> on left
Most significant digit(Hundred's place) --> on right
If the numbers are 321 and 654, the LL will be represented as:-
1->2->3
4->5->6
Now even if the LL's are of different size it doesnt matter here.
Because we are dealing with units to hundred's place from L-R
*/

Node *addrecursive(Node *head1, Node *head2, int carry){
    if(head1 == NULL && head2 == NULL && carry == 0) return NULL;
    int sum = carry;
    if(head1)
    sum += head1->data;
    if(head2)
    sum += head2->data;
    //carry = sum > 9 ? 1 : 0;
    //sum = sum % 10;
    Node *result = createNode(sum % 10);
    result->next = addrecursive(head1 ? head1->next : NULL, head2 ? head2->next : NULL, carry);
    return result;
} 

Node *addition_by_lists(Node *head1, Node *head2){
    if(head1 == NULL || head2 == NULL) return NULL;    
    Node *temp, *prev = NULL;
    Node *result = NULL;
    int sum, carry = 0;

    while(head1 != NULL || head2 != NULL){
        sum = carry + (head1 ? head1->data:0) + (head2 ? head2->data:0);
        
        if(sum >= 10)
            carry = 1;
        else
            carry = 0;
        sum %= 10;
        
        temp = createNode(sum);

        if(result == NULL)
            result = temp;
        else
            prev->next = temp;
        prev = temp;

        if(head1) head1 = head1->next;
        if(head2) head2 = head2->next;
    }
    if(carry > 0)
        temp->next = createNode(carry);
    return result;
}

int main(){
    Node *head1 = NULL, *head2 = NULL;
    int m, n, data, i; 
    cin>>m>>n;
    FOR(i, 0, m){
        cin>>data;
        head1 = insertNodeEnd(data, head1);
    }
    //printLL(head1);
    
    FOR(i, 0, n){
        cin>>data;
        head2 = insertNodeEnd(data, head2);
    }
    //printLL(head2);   
    cout<<"\n";
    //Node *head = addition_by_lists(head1, head2);
    //printLL(head);
    
    //printLL(head2);   
    cout<<"\n";
    Node *head4 = addrecursive(head1, head2, 0);
    printLL(head4);
}