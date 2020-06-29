//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            2000000 
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

ll dp[MX_N + 1][2];

int main(){
    int T;
    cin >> T;
    int n = MX_N;
    for(int i=n-2;i>=1;--i){
        dp[i][1] = 4LL + dp[i+1][0] + 2 * dp[i+2][0];
        dp[i][0] = max(dp[i+1][0], dp[i+1][1]) + 2 * max(dp[i+2][0], dp[i+2][1]);
        if(dp[i][0] >= mod7){
            dp[i][0] %= mod7;
        }
        if(dp[i][1] >= mod7){
            dp[i][1] %= mod7;
        }
    }
    while(T--){
        cin >> n;
        cout << max(dp[MX_N + 1 - n][0], dp[MX_N + 1 - n][1]) << endl;
    }
}
