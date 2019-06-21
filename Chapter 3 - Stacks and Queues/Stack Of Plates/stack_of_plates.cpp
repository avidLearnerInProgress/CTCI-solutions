//
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

class StackSet{
    
    int capacity;
    vector<stack<int>> setStack;

    public:
    StackSet(int c){
        capacity = c;    
        setStack = vector<stack<int>>();
    }

    void spush(int data){
        if(setStack.back().size() == capacity)
            setStack.push_back(stack<int>());
        setStack.back().push(data);
    }

    int spop(){
        if(setStack.size() == 1 && setStack[0].empty())
            return INT_MIN;
        int t = setStack.back().top();
        setStack.back().pop();
        if(setStack.back().empty() && setStack.size() > 1)
            setStack.pop_back();
        return t;
    }

    void spopAt(int index)
    {
        int t;
        if (setStack[index].size() > 1)
                setStack[index].pop();
        else
        {
            if (setStack.size() > 1)
                setStack.erase(setStack.begin() + index);
            else // we only have one stack
                setStack[index].pop();
        }
    }

    int size() const
    {
        int initial = 0;
        for (const std::stack<int>& s : setStack)
            initial += s.size();
        return initial;
    }
    bool empty() const
    {
        return size() == 0;
    }

    int top() const
    {
        assert(!empty());
        return setStack.back().top();
    }
};


int main(){
    StackSet s(4);
    s.spush(10);
    s.spush(20);
    s.spush(30);
    s.spush(40);
    s.spop();
    s.spop();
    s.spush(50);
    s.spush(60);
    s.spush(70);
    s.spush(80);
    s.spopAt(0);
    s.spopAt(1);
    return 0;
}    