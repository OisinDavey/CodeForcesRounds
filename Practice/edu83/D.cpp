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

const long long mod = 998244353;

void modulo(ll& x){
    if(x >= mod){
        x %= mod;
    }
}

ll binpow(ll base, ll expo){
    if(expo == 0ll){
        return 1ll;
    }else if(expo == 1ll){
        modulo(base);
        return base;
    }
    ll tmp = binpow(base, expo/2ll);
    tmp *= tmp;
    modulo(tmp);
    if(expo % 2ll == 1ll){
        tmp *= base;
        modulo(tmp);
    }
    return tmp;
}

ll fact[MX_N];

ll inv(ll a){
    return binpow(a, mod - 2ll);
}

ll _div(ll a, ll b){
    ll tmp = inv(b);
    tmp *= a;
    modulo(tmp);
    return tmp;
}

ll choose(ll n, ll k){
    ll tmp = fact[k] * fact[n - k];
    modulo(tmp);
    return _div(fact[n], tmp);
}

int main(){
    fact[0] = 1ll;
    for(int i=1;i<MX_N;++i){
        fact[i] = fact[i-1] * i;
        modulo(fact[i]);
    }

    ll n, m;
    cin >> n >> m;

    if(n == 2){
        cout << "0\n";
    }else{
        ll res = choose(m, n-1);
        modulo(res);
        res *= (n-2);
        modulo(res);
        res *= binpow(2, n-3);
        modulo(res);
        cout << res << endl;
    }
}
