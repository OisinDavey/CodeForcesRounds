//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[2*n];
    for(int i=0;i<2*n;++i){
        cin >> a[i];
    }
    vector<int> v;
    bool proc[2*n];
    memset(proc, 0, sizeof(proc));
    for(int i=0;i<2*n;++i){
        if(proc[i]){
            continue;
        }
        v.pb(1);
        for(int j=i+1;j<2*n;++j){
            if(a[j] < a[i]){
                v[v.size()-1]++;
                proc[j] = true;
            }else{
                break;
            }
        }
    }
    sort(All(v));
    int m = v.size();
    bool dp[m][2*n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<m;++i){
        dp[i][0] = true;
    }
    dp[m-1][v[m-1]] = true;
    for(int i=m-2;~i;--i){
        for(int j=1;j<=2*n;++j){
            if(j == v[i]){
                dp[i][j] = true;
            }else{
                if(dp[i+1][j]){
                    dp[i][j] = true;
                }else if(j >= v[i]){
                    if(dp[i+1][j-v[i]]){
                        dp[i][j] = true;
                    }
                }
            }
        }
    }
    if(dp[0][n]){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
