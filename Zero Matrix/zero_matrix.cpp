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

void printMatrix(vector<vector<int> > matrix, int n){
    int i, j;
    FOR(i, 0, n){
        FOR(j, 0, n)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }
}

void nullifyRow(vector<vector<int> > &fill, int row){
    int i;
    FOR(i, 0, fill.size())
        fill[row][i] = 0;
}

void nullifyCol(vector<vector<int> > &fill, int col){
    int i;
    FOR(i, 0, fill[0].size())
        fill[i][col] = 0;
}
void setZero(vector<vector<int> > &fill, int n){
    if(fill[0].size() <= 0 || fill.size() <= 0) return;
    int rsz = fill.size(), csz = fill[0].size();
    vector<int> rowZero(rsz, 0);
    vector<int> colZero(csz, 0);
    int i,j;
    FOR(i, 0, n){
        FOR(j, 0, n){
            if(fill[i][j]==0){
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }
    
    FOR(i, 0, fill.size()){
        if(rowZero[i])
            nullifyRow(fill, i);
    }
    
    FOR(j, 0, fill[0].size()){
        if(colZero[j])
            nullifyCol(fill, j);
    }
}

void setZeroSpaceOptimised(vector<vector<int> > &fill, int n){
    if(fill.size() <= 0 || fill[0].size() <= 0) return;
    //check for 0th rows and cols and set the bools if 0 is present
    //check remaining matrix and if any 0 found set i0 or 0j
    //next nullify all rows and cols for which i0 or 0j is true
    //recheck the true set in step 1 and nullify the 0th col and row
    bool row_zero = false, col_zero = false;
    int i,j,k,l;

    FOR(i, 0, fill[0].size())
        if(fill[i][0] == 0){
            col_zero = true;
            break;
        }

    FOR(i, 0, fill.size())
        if(fill[0][i] == 0){
            row_zero = true;
            break;
        }
    
    FOR(i, 1, fill.size()){
        FOR(j, 1, fill[0].size()){
            if(fill[i][j] == 0){
                fill[i][0] = 0;
                fill[0][j] = 0;
            }
        }
    }

    FOR(i, 1, fill.size()){
        if(fill[i][0] == 0)
            nullifyRow(fill, i);
    }
    
    FOR(j, 1, fill[0].size()){
        if(fill[0][j] == 0)
            nullifyCol(fill, j);
    }

    if(row_zero)
        nullifyRow(fill, 0);
    if(col_zero)
        nullifyCol(fill, 0);

 //   printMatrix(fill, n);
}

int main()
{
    int n, i, j; 
    cin>>n; //dimension
    vector<vector<int> > fill(n);
    int x; 
    FOR(i, 0, n){
        FOR(j, 0, n){
            cin>>x;
            fill[i].push_back(x);
        }
    }
    printMatrix(fill, n);
    //setZero(fill, n);
    //cout<<"Set to Zero:-\n";
    //printMatrix(fill, n);
    setZeroSpaceOptimised(fill, n);
    cout<<"Set to Zero Optimised:-\n";
    printMatrix(fill, n);
    return 0;
}