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

ll R, G, H;

ll Trinum(ll h){
    return h * (h + 1) / 2;
}

int dp[MX_N];

int main(){
    cin >> R >> G;

    H = floor((-1.0 + sqrt(8.0 * (R + G) + 1.0))/2.0);

    for(ll h=1LL;h<=H;++h){
        for(ll r=R;r>=0;--r){
            ll g = G - Trinum(H) + Trinum(h) + R - r;

            if(h == 1){
                dp[r] = (r > 0) + (g > 0);
            }else{
                dp[r] = (g >= h) ? dp[r] : 0LL;
                dp[r] += (r >= h) ? dp[r-h] : 0LL;
            }

            dp[r] %= mod7;
        }
    }
    cout << dp[R] << endl;
}
