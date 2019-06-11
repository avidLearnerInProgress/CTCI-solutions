//https://ide.geeksforgeeks.org/8qLevp7XYB
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


bool checkTail(Node *he, Node *she){
    if(he == NULL && she == NULL)return 0;
    while(he->next != NULL)
        he = he->next;                   

    while(she->next != NULL)
        she = she->next;                    
    
    if(he == she){
        cout<<he->data<<"\n";
        return 1;
    }
    else return 0;
}

Node *incrementPointer(Node* head, int diff){
    if(head == NULL) return NULL;
    int i;
    FOR(i, 0, diff){
        if(head == NULL) return NULL;
        head = head->next;
    }
    return head;
}

Node *intersectionHelper(Node *zack, Node *cody){
    if(zack == NULL && cody == NULL)return NULL;
    while(zack && cody){
        if(zack == cody)
            return zack;
        zack = zack->next;
        cody = cody->next;
    }
    return NULL;
}

Node *checkIntersection(Node *harry, Node *potter){
    if(harry == NULL && potter == NULL)return NULL;
    if(!checkTail(harry, potter)) return NULL;
    
    int h_length = countLL(harry), p_length = countLL(potter);
    cout<<"\n"<<h_length<<"\t"<<p_length<<"\n";
    int diff_hp = abs(h_length - p_length);
    cout<<diff_hp<<"\n";
    Node *new_hp, *i_intersection;

    if(h_length > p_length && diff_hp > 0){
        new_hp = incrementPointer(harry, diff_hp);
        cout<<"New pointer:"<<new_hp->data<<"\n";
        if(new_hp == NULL) return NULL;
        i_intersection = intersectionHelper(new_hp, potter);
    }
    else if(h_length < p_length && diff_hp > 0){
        new_hp = incrementPointer(potter, diff_hp);
        cout<<"New pointer:"<<new_hp->data<<"\n";
        if(new_hp == NULL) return NULL;
        i_intersection = intersectionHelper(new_hp, potter);
    }
    else{
        cout<<"Something is wrong!!\n";
        exit(0);
    }
    return i_intersection;
}

int main(){
    /*Node *list1 = NULL, *list2 = NULL;
    int n, m, data, i; 
    cin>>n>>m;
    
    FOR(i, 0, n){
        cin>>data;
        list1 = insertNode(data, list1);
    }

    FOR(i, 0, m){
        cin>>data;
        list2 = insertNode(data, list2);
    }*/
    
    Node *list1 = createNode(3);
    list1->next = createNode(6);
    list1->next->next = createNode(9);
    list1->next->next->next = createNode(12);
    list1->next->next->next->next = createNode(15);
    list1->next->next->next->next->next = createNode(18);
    
    Node * list2 = createNode(7);
    list2->next = createNode(10);
    list2->next->next = list1->next->next->next;

    printLL(list1);
    cout<<"\n";
    printLL(list2);

    Node *intersect = checkIntersection(list1, list2);
    if(intersect == NULL)cout<<"Intersection node not found!!";
    else cout<<"Intersection node is:-"<<intersect->data<<"";
}