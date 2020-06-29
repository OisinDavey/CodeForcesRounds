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

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> both, a, b;
    for(int i=0;i<n;++i){
        int t;
        bool _a, _b;
        cin >> t >> _a >> _b;
        if(_a && _b){
            both.pb(t);
        }else if(_a){
            a.pb(t);
        }else if(_b){
            b.pb(t);
        }
    }
    sort(All(both));
    sort(All(a));
    sort(All(b));
    int x = both.size(), y = a.size(), z = b.size();
    ll pref_both[x + 1];
    ll pref_a[y + 1];
    ll pref_b[z + 1];
    pref_both[0] = 0; 
    pref_a[0] = 0;
    pref_b[0] = 0; 
    for(int i=1;i<=x;++i){
        pref_both[i] = pref_both[i-1] + both[i-1];
    }
    for(int i=1;i<=y;++i){
        pref_a[i] = pref_a[i-1] + a[i-1];
    }
    for(int i=1;i<=z;++i){
        pref_b[i] = pref_b[i-1] + b[i-1];
    }
    ll ans = INF;
    for(int i=0;i <= min(x, k);++i){
        if( (k - i) > y || (k - i) > z){
            continue;
        }
        ans = min(ans, pref_both[i] + pref_a[k - i] + pref_b[k - i]);
    }
    if(ans == INF){
        cout << "-1\n";
    }else{
        cout << ans << endl;
    }
}
