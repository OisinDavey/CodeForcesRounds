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

const long long INF = 1e11;

using namespace std;

bool cheque_o(vector<ll>& a, ll x, ll k){
    bool parity = 1;
    int n = a.size();
    int count = 0;
    for(int i=0;i<n;++i){
        if(!parity){
            if(a[i] <= x){
                ++count;
                parity = !parity;
            }
        }else{
            ++count;
            parity = !parity;
        }
    }
    return (count >= k);
}

bool cheque_e(vector<ll>& a, ll x, ll k){
    bool parity = 1;
    int n = a.size();
    int count = 0;
    for(int i=0;i<n;++i){
        if(parity){
            if(a[i] <= x){
                ++count;
                parity = !parity;
            }
        }else{
            ++count;
            parity = !parity;
        }
    }
    return (count >= k);
}

int main(){
    FastIO;
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    ll L = 0;
    ll R = INF;
    while(L < R){
        ll M = L + (R - L)/2;
        if(cheque_e(a, M, k) || cheque_o(a, M, k)){
            R = M;
        }else{
            L = M + 1;
        }
    }
    cout << L << endl;
}
