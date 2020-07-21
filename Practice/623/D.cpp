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

struct comp{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        if(a.se == b.se){
            return a.fi > b.fi;
        }else{
            return a.se < b.se;
        }
    }
};

int main(){
    ll ans = 0ll;
    int n;
    cin >> n;
    map<int, vector<int> > m;
    set<int> s;
    pair<ll, ll> a[n];
    for(int i=0;i<n;++i){
        cin >> a[i].fi;
    }
    for(int i=0;i<n;++i){
        cin >> a[i].se;
    }
    sort(a, a+n);
    for(int i=0;i<n;++i){
        m[a[i].fi].pb(i);
        s.insert(a[i].fi);
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, comp> PQ;
    vector<int> ord;
    ll cur_pos = -1;
    for(int i=0;i<n;++i){
        cur_pos = max(cur_pos+1, a[i].fi);
        ord.pb(cur_pos);
    }
    for(int x : ord){
        if(s.find(x) != s.end()){
            vector<int>& v = m[x];
            for(int y : v){
                PQ.push(a[y]);
            }
        }
        pair<ll, ll> p = PQ.top();
        PQ.pop();
        ans += (x - p.fi)*p.se;
    }
    cout << ans << endl;
}
