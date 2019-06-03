//https://ide.geeksforgeeks.org/nCoLMrqWtn

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

vector<vector<int> > anti_reverse_elements(vector<vector<int> > to_reverse, int n){
    //vector<vector<int> > my_ip_T_R(n);
    for(int i=0; i<n; i++){
        for(int j=0; i<n; i++){
            swap(to_reverse[i][j], to_reverse[n-i-1][j]);
        }
    }
    return to_reverse;
}

vector<vector<int> > reverse_elements(vector<vector<int> > to_reverse, int n){
    //vector<vector<int> > my_ip_T_R(n);
    for(int i=0; i<n; i++){
        for(int j=0; i<n; i++){
            swap(to_reverse[i][j], to_reverse[i][n-j-1]);
        }
    }
    return to_reverse;
}

int main(){
    int i, j, n;
    cin>>n;
    vector<vector<int> > my_ip(n);
    vector<vector<int> > my_ip_T(n);
    int x;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          cin>>x;
          my_ip[i].push_back(x);
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            my_ip_T[i].push_back(my_ip[j][i]);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<my_ip_T[i][j]<<" ";
        }
        cout<<"\n";
    }
    auto reversed = reverse_elements(my_ip_T, n);
    auto antireversed = anti_reverse_elements(my_ip_T, n);

    cout<<"##########-----##########\n";
    cout<<"Input:-"
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<my_ip[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Clockwise (90)º :-"
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<reversed[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"AntiClockwise (90)º :-"
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<antireversed[i][j]<<" ";
        }
        cout<<"\n";
    }
}