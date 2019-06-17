//https://ide.geeksforgeeks.org/NHYJuLKGyv
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

class StackMin{
    stack<int> minStack;
    int minEle, temp;

    public:
    bool isEmpty(){
        if(minStack.empty()){
            //cout<<"Stack is empty."<<"\n";
            return true;
        }
        return false;
    }

    void getPeek(){
        if(isEmpty()){
            cout<<"Stack is empty."<<"\n";
            return;
        }
        int top = minStack.top();
        cout<<"Current top - ";
        if(top < minEle)cout<<minEle<<"\n";
        else cout<<top<<"\n";
    }
    
    void minStackPush(int data){
        if(isEmpty()){
            minStack.push(data); minEle = data;
        }
        else{
            if(data < minEle){
                minEle = data;
                minStack.push(data*2 - minEle);
            }
            else
                minStack.push(data);
        }
    }

    void minStackPop(){
        if(isEmpty()) {
            cout<<"Stack is empty."<<"\n";
            return;
        }
        int top = minStack.top();
        minStack.pop();

        cout<<"Current top - ";
        if(top < minEle){
            cout<<minEle<<"\n";
            minEle = 2*minEle - top;
        }
        else
            cout<<top<<"\n";     
    }
};

int main(){
    StackMin min;
    min.minStackPush(10);
    min.minStackPush(20);
    min.minStackPush(30);
    min.minStackPush(40);
    min.minStackPop();
    min.minStackPop();
    return 0;
}    