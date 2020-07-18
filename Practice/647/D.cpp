//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            500001 
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
vector<int> ord[MX_N];
int color[MX_N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        ord[t].pb(i);
        color[i] = t;
    }
    for(int i=1;i<=n;++i){
        for(int at : ord[i]){
            set<int> s;
            for(int to : adj[at]){
                if(color[to] == color[at]){
                    cout << "-1\n";
                    return 0;
                }else if(color[to] < color[at]){
                    s.insert(color[to]);
                }
            }
            if(s.size() != color[at]-1){
                cout << "-1\n";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int at : ord[i]){
            cout << at+1 << ' ';
        }
    }
    cout << endl;
}
