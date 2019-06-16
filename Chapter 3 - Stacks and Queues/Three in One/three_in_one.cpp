//https://ide.geeksforgeeks.org/dOeWzpwJod
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

class KStacks{
    int *stackData, *topOfStacks, *nextIndex;
    int n, k, nextAvailable;
    
    public:
    KStacks(int a, int b){
        n = a; k = b;
        stackData = new int[n];
        topOfStacks = new int[k];
        nextIndex = new int[n];
        nextAvailable = 0;
        int x;
        FOR(x, 0, n) topOfStacks[x] = -1;
        FOR(x, 0, n-1) nextIndex[x] = x + 1;
        nextIndex[n-1] = -1;
    }
    
    void push(int k, int data){
        if(nextAvailable == -1){
            cout<<"SO"<<"\n"; //stackoverflow 
            return;
        }
        
        //very similar to 3 way swapping --> 
        //a->b->c->d
        
        int temp = nextAvailable;
        nextAvailable = nextIndex[temp];
        nextIndex[temp] = topOfStacks[k];
        topOfStacks[k] = temp;
    
        //push operation
        stackData[temp] = data;
    }
    
    int pop(int k){
        if(topOfStacks[k] == -1){
            cout<<"Empty stack..!"<<"\n";
            return -1;
        }
        
        //reverse of push 3 way swapping
        int temp = topOfStacks[k];
        topOfStacks[k] = nextIndex[temp];
        nextIndex[temp] = nextAvailable;
        nextAvailable = temp;
        return stackData[temp];
    }
};

int main(){
    int n = 6, k = 10;
    KStacks ks(n, k);
    ks.push(0, 10);
    ks.push(0, 11);
    ks.push(0, 12);
    ks.push(1, 13);
    cout<<ks.pop(0)<<"\n";
    cout<<ks.pop(0)<<"\n";
    cout<<ks.pop(1)<<"\n";
    cout<<ks.pop(0)<<"\n";
    cout<<ks.pop(0)<<"\n";
}    