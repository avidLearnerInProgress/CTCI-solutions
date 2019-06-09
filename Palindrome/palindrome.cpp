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

//Stack based extra space
bool isSLLPalindrome1(Node *head){
    
    if(head == NULL) return false;
    Node *walker = head, *runner = head;
    stack<int> st;

    while(runner!=NULL && runner->next!=NULL){
        st.push((int)walker->data);
        walker = walker->next;
        runner = runner->next->next;
    }
    if(runner)
        runner = runner->next;
    
    while(walker != NULL){
        int top = (int)st.top();
        if(top != walker->data)
            return false;
        walker = walker->next;
    }
    return true;
}


int main(){
    Node *head = NULL;
    int n,data, i; cin>>n;
    FOR(i, 0, n){
        cin>>data;
        head = insertNodeEnd(data, head);
    }
    printLL(head);
    cout<<"\n";
    cout<<isSLLPalindrome1(head);
}
