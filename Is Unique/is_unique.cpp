//https://ide.geeksforgeeks.org/PXfVawytO8

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

double EPS = 1e-9; 
int INF = 1000000005; 
long long INFF = 1000000000000000005LL; 
double PI = acos(-1); 
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 }; 

#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
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

//hashing occurrences of characters
// TC: O(n) SC: O(n)
bool isUniqueHashing(string x){
    if(x.length() < 1) return false;

    vector<int> bset(128); //ASCI is 128 chars
    int i;
    bset = {0};
    FOR(i, 0, x.length() - 1){
        if(bset[x[i] - 'a']){
            return false;
        }
        bset[x[i] - 'a'] = true;
    }
    return true;
}

//useful only when the input modification is permitted
// TC: O(n logn) SC: O(1)
bool isUniqueSort(string x){
    if(x.length() < 1) return false;    

    sort(x.begin(), x.end());
    FOR(i, 0, x.length() - 2){
        if(x[i] == x[i + 1])
            return false;
    }
    return true;
}

//check bit first, then set bit
//uses constant space --> n * k (n is length of string and k is the bits in each char within string)
bool isUniqueBit(string x){
    if(x.length() < 1) return false;

    int check = 0;
        int value = x[i] - 'a';
    FOR(i, 0, x.length() - 1){
        if((check & (1 << value)) > 0) return false;
        check = check | (1 << value);
    }
    return true;
}

int main(){
    
    int t; cin>>t;
    TC(t){
        string x; 
        cin>>x;
        if(isUniqueSort(x))cout<<"True\n";
        else cout<<"False\n";

        if(isUniqueHashing(x))cout<<"True\n";
        else cout<<"False\n";

        if(isUniqueBit(x))cout<<"True\n";
        else cout<<"False\n";
    }
}