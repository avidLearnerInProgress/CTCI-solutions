//https://ide.geeksforgeeks.org/99cYaz4W3i
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

string stringCompression(string x){
    if(x.length() < 1) return "";
    int i, count_compression = 0;
    string result = "";
    FOR(i, 0, x.length() - 1){
        count_compression++;
        if(i+1 >= x.length() || x[i] != x[i+1]){
            result += x[i];
            result += to_string(count_compression);
            count_compression = 0;
        }
    }
    cout<<result<<"\n";
    return (result.length() < x.length() ? result : x);
}

int countCompression(string x){
    if(x.length() < 1) return 0;
    int i, count_compression = 0;
    //string result = "";
    int length_compression = 0;
    FOR(i, 0, x.length() - 1){
        count_compression++;
        if(i+1 >= x.length() || x[i] != x[i+1]){
            length_compression += 1 + count_compression;
            count_compression = 0;
        }
    }
    return length_compression;
}

string lookAheadCompression(string x){
    if(x.length() < 1) return "";
    int count_size = countCompression(x);
    if(count_size < x.length())
        return x;
    
    int count_compression = 0;
    string result = "";
    FOR(i, 0, x.length() - 1){
        count_compression++;
        if(i+1 >= x.length() || x[i] != x[i+1]){
            result += x[i];
            result += to_string(count_compression);
            count_compression = 0;
        }
    }
    return result;
}

int main()
{
    string ip = "aaabbbccdddeefghiiijjkk";
    cout<<stringCompression(ip)<<"\n";
    cout<<lookAheadCompression(ip)<<"\n";
    return 0;
}