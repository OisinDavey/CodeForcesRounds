//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            100001 
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

vector<int> adj[MX_N];
int p[MX_N];
ll l[MX_N];
ll r[MX_N];
ll dp[MX_N][2];

void fill(int at){
    dp[at][0] = dp[at][1] = 0;
    for(int to : adj[at]){
        if(to == p[at]){
            continue;
        }
        p[to] = at;
        fill(to);
        dp[at][0] += max(dp[to][0] + abs(l[at] - l[to]), dp[to][1] + abs(l[at] - r[to]));
        dp[at][1] += max(dp[to][0] + abs(r[at] - l[to]), dp[to][1] + abs(r[at] - r[to]));
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    p[0] = -1;
    for(int i=0;i<n;++i){
        cin >> l[i] >> r[i];
        adj[i] = {};
    }
    for(int i=1;i<n;++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fill(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
    return;
}

int main(){
    int T;
    FastIO;
    cin >> T;
    while(T--){
        solve();
    }
}
