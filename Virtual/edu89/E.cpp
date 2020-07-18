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

const long long mod = 998244353;

using namespace std;

//Note
//I claim that the array a can be broken into concurrent segments such that for each segment i, the minimum of the suffix starting at i 
//is equal to a[i] for any i in the segment (l, r)
//
//if this isnt the case, it wont work
//if it is, take the product of all segment sizes bar the first one

void modulo(ll& x){
    if(x >= mod){
        x %= mod;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=0;i<m;++i){
        cin >> b[i];
    }
    ll suff[n];
    suff[n-1] = a[n-1];
    for(int i=n-2;i>=0;--i){
        suff[i] = min(a[i], suff[i+1]);
    }
    if(suff[0] != b[0]){
        cout << "0\n";
        return 0;
    }else if(suff[n-1] != b[m-1]){
        cout << "0\n";
        return 0;
    }
    map<ll, ll> occ;
    for(int i=0;i<n;++i){
        ++occ[suff[i]];
    }
    ll ans = 1;
    for(int i=1;i<m;++i){
        ans *= occ[b[i]];
        modulo(ans);
    }
    cout << ans << endl;
}
