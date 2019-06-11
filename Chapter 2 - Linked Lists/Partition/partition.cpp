//https://ide.geeksforgeeks.org/OV6WGEik40
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

//Non stable version
//Extra space --> Use 2 ll pointers and seggregate based on x
Node *partitionUnstable(Node *head, int x){
    if(head == NULL) return NULL;
    
    Node *curr = head, *tail = head;

    while(curr != NULL){
        Node *next = curr->next;

        if(curr->data < x){
            curr->next = head;
            head = curr;
        }
        else{
            tail->next = curr;
            tail = curr;
        }
        curr = next;
    }
    tail->next = NULL;
    return head;
}


//Stable version
//Use 2 queue and dummy nodes
Node *partitionStable(Node *head, int x){
    if(head == NULL) return NULL;
    Node *d1 = createNode(0);
    d1->next = head;
    //cout<<d1->data<<"\n";
    Node *d2 = createNode(0);
    //cout<<d1->data<<"\n";
    Node *x1 = d1, *x2 = d2;

    while(head != NULL){
        if(head->data < x){
            x1->next = head;
            x1 = x1->next;
        }
        else{
            x2->next = head;
            x2 = x2->next;
        }
        head = head->next;
    }
    x2->next = NULL;
    x1->next = d2->next;
    return d1->next;
}


int main(){
    /*Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(4);*/
    
    //n - number of nodes in LL
    
    Node *head = NULL;
    int n,data, i; cin>>n;
    FOR(i, 0, n){
        cin>>data;
        head = insertNodeEnd(data, head);
    }
    printLL(head);
    //cout<<"\n";
    //head = partitionUnstable(head, 5);
    //printLL(head);
    cout<<"\n";
    head = partitionStable(head, 5);
    printLL(head);
}
