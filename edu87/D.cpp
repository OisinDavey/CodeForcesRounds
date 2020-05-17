//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
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
#define lsb(x)          (x&(-x))

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

ll BIT[1000001];

int n;

void increment(int at){
    while(at <= n){
        ++BIT[at];
        at += lsb(at);
    }
}

ll sumn(int at){
    ll ans = 0ll;
    while(at != 0){
        ans += BIT[at];
        at -= lsb(at);
    }
    return ans;
}

void decrement(ll k){
    int l = 0;
    int r = n;
    while(l < r){
        int m = l + (r-l)/2;
        if(sumn(m) < k)
            l = m + 1;
        else
            r = m;
    }
    while(l <= n){
        --BIT[l];
        l += lsb(l);
    }
}

int main(){
    FastIO;
    int q;
    cin >> n >> q;
    memset(BIT, 0, sizeof(BIT));
    int A;
    for(int i=0;i<n;++i){
        cin >> A;
        increment(A);
    }
    int k;
    for(int i=0;i<q;++i){
        cin >> k;
        if(k > 0)
            increment(k);
        else
            decrement(-1*k);
    }
    for(int i=1;i<=n;++i){
        if(BIT[i] > 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << "0\n";
}
