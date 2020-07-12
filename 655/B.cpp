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
    bitset<1000001> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    vector<ll> primes;
    for(int i=0;i<1000001;++i){
        if(sieve[i]){
            primes.pb(i);
            for(int j=i+i;j<1000001;j+=i){
                sieve[j] = 0;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        pair<ll, ll> ans;
        for(ll p : primes){
            if(p > n){
                break;
            }
            if(n%p == 0ll){
                ans = mp((n/p), (n/p)*(p-1ll));
                goto end_of_loop;
            }
        }
        ans = mp(1ll, n-1ll);
        end_of_loop:;
        cout << ans.fi << ' ' << ans.se << endl;
    }
}
