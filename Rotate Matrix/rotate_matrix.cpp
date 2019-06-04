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

/*
Approach 1: Take transpose of matrix and then reverse the rows for clockwise 90' rotation.
 			Obviously if we reverse the columns we will get anticlockwise 90' rotation.
Approach 2: As mentioned in the book, rotating invididual elements layer by layer.
			   I have solved it perform anticlockwise 90' rotation, it can be done similarly for clockwise rotatation.
*/
/*
Anticlockwise: Find transpose of matrix(Tm) and then reverse columns of Tm
Clockwise: Find Tm and then reverse rows of TM 
*/

void transpose(vector<vector<int> > &a, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
            if(i!=j)
                swap(a[i][j], a[j][i]);
    }
}

void rreverse_elements(vector<vector<int> > &to_reverse, int n){
    for(int i=0; i<n; i++){
        for(int j=0; i<n; i++){
            swap(to_reverse[i][j], to_reverse[i][n-j-1]);
        }
    }
}

void creverse_elements(vector<vector<int> > &to_reverse, int n){
    for(int i=0; i<n; i++){
        for(int j=0; i<n; i++){
            swap(to_reverse[j][i], to_reverse[n-j-1][i]);
        }
    }
}

int main(){
    int i, j, n;
    cin>>n;
    vector<vector<int> > my_ip(n);
    int x;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          cin>>x;
          my_ip[i].push_back(x);
        }
    }
    
    cout<<"Approach 1:-\n";
    
    //clockwise :- transpose + rowwise transformation
    /*
    1 2 3      1 4 7      7 4 1 
    4 5 6  --> 2 5 8  --> 8 5 2 
    7 8 9      3 6 9      9 6 3
    */
    
    
    //anticlockwise :- transpose + rowwise + columnwise + rowwise transformation
    /*
    1 2 3      1 4 7      7 4 1     9 6 3     3 6 9 
    4 5 6  --> 2 5 8  --> 8 5 2 --> 8 5 2 --> 2 5 8 
    7 8 9      3 6 9      9 6 3     7 4 1     1 4 7
    */

    transpose(my_ip, n);
    cout<<"Transposed:-\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<my_ip[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    //rowwise
    rreverse_elements(my_ip, n);
    cout<<"Clockwise 90 degrees :-\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<my_ip[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    //columnwise
    creverse_elements(my_ip, n);
    rreverse_elements(my_ip, n);
    cout<<"Anticlockwise 90 degrees :-\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<my_ip[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Approach 2:-\n";
    
}