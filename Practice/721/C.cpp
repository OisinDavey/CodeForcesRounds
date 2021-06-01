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
    int a[n];
    ll dp[n];
    memset(dp, 0, sizeof(dp));
    set<int> ranking_set;
    map<int, int> rank;
    for(int i=0;i<n;++i){
        cin >> a[i];
        ranking_set.insert(a[i]);
    }
    int cnt = 0;
    for(auto it=ranking_set.begin();it!=ranking_set.end();++it){
        rank[(*it)] = cnt;
        ++cnt;
    }
    for(int i=0;i<n;++i){
        a[i] = rank[a[i]];
    }
    int m = ranking_set.size();
    vector<ll> pos[m];
    vector<ll> pos_pref[m];
    for(int i=0;i<n;++i){
        if(i > 0){
            dp[i] += dp[i-1];
        }
        if(!pos_pref[a[i]].empty()){
            dp[i] += pos_pref[a[i]].back();
            pos_pref[a[i]].pb(pos_pref[a[i]].back());
        }else{
            pos_pref[a[i]].pb(0);
        }
        pos[a[i]].pb(i+1);
        pos_pref[a[i]].back() += pos[a[i]].back();
    }
    ll ans = 0ll;
    for(int i=0;i<n;++i){
        ans += dp[i];
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
