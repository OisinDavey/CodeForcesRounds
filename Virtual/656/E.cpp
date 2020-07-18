//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            200001
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

vector<int> ans;
vector<int> adj[MX_N];
vector<pair<int, int> > undir;
bool visited[MX_N];

void dfs_order(int at){
    visited[at] = true;
    for(int to : adj[at]){
        if(visited[to]){
            continue;
        }
        dfs_order(to);
    }
    ans.pb(at);
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<m;++i){
            int t, u, v;
            cin >> t >> u >> v;
            --u;
            --v;
            if(t == 1){
                adj[u].pb(v);
            }else{
                undir.pb(mp(u, v));
            }
        }
        for(int i=0;i<n;++i){
            if(visited[i]){
                continue;
            }
            dfs_order(i);
        }
        reverse(All(ans));
        int pos[MX_N];
        for(int i=0;i<ans.size();++i){
            pos[ans[i]] = i;
        }
        for(pair<int, int> p : undir){
            if(pos[p.fi] < pos[p.se]){
                adj[p.fi].pb(p.se);
            }else{
                adj[p.se].pb(p.fi);
            }
        }
        for(int at=0;at<n;++at){
            for(int to : adj[at]){
                if(pos[at] > pos[to]){
                    cout << "NO\n";
                    goto end_of_loop;
                }
            }
        }
        cout << "YES\n";
        for(int at=0;at<n;++at){
            for(int to : adj[at]){
                cout << at+1 << ' ' << to+1 << endl;
            }
        }
        end_of_loop:;
        memset(visited, 0, sizeof(visited));
        ans = {};
        undir = {};
        for(int at=0;at<n;++at){
            adj[at] = {};
        }
    }
}
