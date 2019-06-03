//https://ide.geeksforgeeks.org/1YN376nxPW
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

int getFrequency(char x){
    int ind = -1;
    if(x >= 'a' && x <= 'z') 
        ind = x - 'a';
    if(x >= 'A' && x <= 'Z')
        ind = x - 'A';
    return ind;
}
bool oneAwayHashed(string s1, string s2){
    if(s1.length() < 1 || s2.length() < 1) return false;
    if(abs(s1.length() - s2.length()) > 1) return false;
    
    int visited[256] = {0};
    int i,j;
    if(s1.length() >= s2.length()){    
        s1 = s1; s2 = s2;
    }
    else{
        s1 = s2; s2 = s1;
    }

    FOR(i, 0, s1.length()) visited[s1[i]]++;
    FOR(i, 0, s2.length()) visited[s2[i]]--;

    int count = 0;
    FOR(i, 0, 256){
        if(visited[i]> 0)
            count += visited[i];
    }
    return count <= 1;
}

bool oneAway(string s1, string s2){
    if(s1.length() < 1 || s2.length() < 1) return false;
    if(abs(s1.length() - s2.length()) > 1) return false;

    //bigger_str = s1, smaller_str = s2
    if(s1.length() >= s2.length()){    
        s1 = s1; s2 = s2; 
    }
    else{
        s1 = s2; s2 = s1;
    }
    cout<<s1<<" "<<s2;

    int i = 0, j = 0;
    bool found = false; //calculate difference - one away
    while(i < s1.length() && j < s2.length()){
        if(s1[i] != s2[j]){
            if(found) return false; // testecase --> "tail" "pale" will break this loop
            found = true;
            if(s1.length() == s2.length())j++; //move shorter pointer only when both strings are of same length. 
            //If they are moved when they are of unqeqal lengths; it will be big problem
        }
        else
            j++; //move shorter pointer ahead when both chars in s1 and s3 are ruqal
        i++; //
    }
    return true;
}

int main()
{
    string s1 = "pale", s2 = "bale", s3 = "pale", s4 = "pal", s5 = "bble", s6 = "xale";
    cout<<oneAwayHashed(s1, s2)<<"\n";
    cout<<oneAwayHashed(s3, s4)<<"\n";
    cout<<oneAwayHashed(s5, s6)<<"\n";
    cout<<"###########\n";
    cout<<oneAway(s1, s2)<<"\n";
    cout<<oneAway(s3, s4)<<"\n";
    cout<<oneAway(s5, s6)<<"\n";
}
