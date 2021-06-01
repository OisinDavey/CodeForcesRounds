//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            100005 
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

vector<pair<int, ll> > adj[MX_N];//to, weight
ll peak[MX_N];//Min sum to root above subtree
ll sum[MX_N];
int a[MX_N];
int p[MX_N];
int n;

int explored;

int main(){
    explored = 0;
    cin >> n;
    for(int i=0;i<n;++i){
        adj[i] = {};
        cin >> a[i];
    }
    memset(p, -1, sizeof(p));
    for(int u=1;u<n;++u){
        int w, v;
        cin >> v >> w;
        --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    sum[0] = 0;
    peak[0] = 0;
    queue<int> Q;
    Q.push(0);
    memset(p, -1, sizeof(p));
    while(!Q.empty()){
        ++explored;
        int at = Q.front();
        Q.pop();
        for(auto& [to, w] : adj[at]){
            if(p[at] == to){
                continue;
            }
            p[to] = at;
            sum[to] = sum[at]+w;
            peak[to] = min(peak[at], sum[to]);
            if(sum[to] - peak[at] <= a[to]){
                Q.push(to);
            }
        }
    }
    cout << n-explored << endl;
}
