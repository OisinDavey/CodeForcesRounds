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
        int n, k;
        cin >> n >> k;
        int a[n+1];
        int v[n+1];
        int m[n+1];
        for(int i=0;i<n;++i){
            cin >> a[i];
        }
        a[n] = 2140000001;
        m[n] = 0;
        v[n] = 0;
        sort(a, a+n+1);
        for(int i=0;i<n;++i){
            int tmp;
            cin >> tmp;
        }
        for(int i=0;i<n;++i){
            auto tmp = upper_bound(a, a+n+1, a[i]+k);
            v[i] = (tmp - a) - i;
        }
        for(int i=n-1;~i;--i){
            m[i] = max(m[i+1], v[i]);
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            ans = max(ans, v[i] + m[i+v[i]]);
        }
        cout << ans << endl;
    }
}
