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

bool palindromePermutation(string str){
    if(str.length() < 1) return false;
    int hash[26] = {0};
    int i, ctoi;
    
    FOR(i, 0, str.length()){
        ctoi = getFrequency(str[i]);
        if(ctoi != -1)
            hash[ctoi]++;
    }
    bool found_n = false;    
    FOR(i, 0, 27){
        if(hash[i] % 2 == 1 && found_n) return false;
        if(hash[i] % 2 == 1 && !found_n) found_n = true;
    }
    return found_n;
}

bool palindromePermutationCountOnGo(string str){
    if(str.length() < 1) return false;
    int hash[26] = {0};
    int i, ctoi, count_odd = 0;
    
    FOR(i, 0, str.length()){
        ctoi = getFrequency(str[i]);
        if(ctoi != -1)
            hash[ctoi]++;
            if(hash[ctoi] % 2 )
                count_odd++;
            else
                count_odd--;
    }
    return count_odd<=1;    
}

int toggle(int ind, int bit_vector){
    if(ind < 0) return bit_vector;
    int mask = 1 << ind;
    //toggle
    if((mask & bit_vector) == 0)
        bit_vector = bit_vector | mask; 
    else
        bit_vector = bit_vector & ~mask;    
    return bit_vector;
}

int createBitVector(string x){
    int i, bit_vector = 0;
    FOR(i, 0, x.length()){
        bit_vector = toggle(getFrequency(x[i]), bit_vector);
    }
    return bit_vector;
}

bool checkOneSetBit(int bit_vector){
    return ((bit_vector) & (bit_vector-1) == 0);
}

bool palindromePermutationBit(string x){
    if(x.length() < 1) return false;
    int bit_vector = createBitVector(x);
    return bit_vector == 0 || checkOneSetBit(bit_vector);
}

int main()
{
    string ip = "TACTD COA";
    if(palindromePermutation(ip)) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    if(palindromePermutationCountOnGo(ip)) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    if(palindromePermutationBit(ip)) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}