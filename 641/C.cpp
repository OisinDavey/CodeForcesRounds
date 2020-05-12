//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
#define mod7            1000000007
#define modpi           314159
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

using namespace std;

int main(){
    int n;
    cin >> n;
    ll a[n];
    ll L[n];
    ll G[n];
    ll ans[n];

    for(int i=0;i<n;++i) cin >> a[i];

    G[0] = 0;

    for(int i=1;i<n;++i) G[i] = gcd(G[i-1], a[i-1]);

    for(int i=1;i<n;++i) L[i] = lcm(G[i], a[i]);

    ans[1] = L[1];

    for(int i=2;i<n;++i) ans[i] = gcd(ans[i-1], L[i]);
    
    cout << ans[n-1] << endl;
}
