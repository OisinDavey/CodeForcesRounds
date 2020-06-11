//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            101
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

ll n, m;
ll invalid[MX_N];
ll maximum;
ll set_size;

ll binpow(ll base, ll expo){
    if(expo == 0){
        return 1LL;
    }
    if(expo == 1){
        return base;
    }
    ll temp = binpow(base, expo/2);
    temp *= temp;
    if(expo % 2 == 1){
        temp *= base;
    }
    return temp;
}

ll a(ll i){
    return i - (long long)(upper_bound(invalid, invalid + n, i) - invalid) + 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        maximum = binpow(2, m);
        set_size = maximum - n;
        for(int i=0;i<n;++i){
            string s;
            cin >> s;
            invalid[i] = stoll(s, 0, 2);
        }
        sort(invalid, invalid + n);
//        for(ll i=0;i<maximum;++i){
//            cout << a(i) << ' ';
//        }
        ll L = 0;
        ll R = maximum-1;
        while(L < R){
            ll M = L + (R - L)/2;
            ll temp = a(M);
            temp -= 1;
            if(temp < (set_size-1)/2){
                L = M+1;
            }else{
                R = M;
            }
        }
        bitset<64> B(L);
        string ans = B.to_string();
        for(int i=64-m;i<64;++i){
            cout << ans[i];
        }
        cout << endl;
    }
}
