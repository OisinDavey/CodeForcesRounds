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
    int T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        pair<ll, ll> p[m];
        ll a[m];
        ll sum[m+1];
        for(int i=0;i<m;++i){
            cin >> p[i].fi >> p[i].se;
            a[i] = p[i].fi;
        }
        sort(a, a+m);
        sum[m] = 0ll;
        for(int i=m-1;~i;--i){
            sum[i] = a[i] + sum[i+1];
        }
        ll best = 0ll;
        if(n<=m){
            best = sum[m-n];
        }
        for(int i=0;i<m;++i){
            //Find the smallest element in a.fi >= a[i].se
            int L =lower_bound(a,a+m,p[i].second)-a;
            ll tmp = sum[L];
            L = m - L;
            if(L > n){
                continue;
            }
            if(p[i].fi < p[i].se){
                tmp += p[i].fi;
                ++L;
            }
            if(L > n){
                continue;
            }
            ll ans = tmp + (n-(ll)L)*(p[i].se);
            best = max(best, ans);
        }
        cout << best << endl;
    }
}
