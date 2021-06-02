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

int dp[501][501][2][2];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int j = 0;
    int r = 0;
    int m = 0;
    for(int x=0;x<n/2;++x){
        i += (s[x] == s[n-x-1] && s[x] == '0');
        j += (s[x] != s[n-x-1]);
    }
    if(n%2 == 1 && s[n/2] == '0'){
        m = 1;
    }
    int ans = dp[i][j][r][m];
    cout << ((ans == 0)?"DRAW\n":((ans > 0)?"BOB\n":"ALICE\n"));
    return;
}

int main(){
    for(int i=0;i<501;++i){
        for(int j=0;j<501;++j){
            for(int r=1;~r;--r){
                for(int m=0;m<2;++m){
                    int ans = 1000000009;
                    if(j > 0 && r == 0){
                        ans = min(ans, -dp[i][j][1][m]);
                    }
                    if(j > 0){
                        ans = min(ans, 1-dp[i][j-1][0][m]);
                    }
                    if(i > 0){
                        ans = min(ans, 1-dp[i-1][j+1][0][m]);
                    }
                    if(m == 1){
                        ans = min(ans, 1-dp[i][j][0][0]);
                    }
                    dp[i][j][r][m] = (ans == 1000000009)?0:ans;
//                    if(i == 0 && j == 0 && m == 0){
//                        dp[i][j][r][m] = 0;
//                    }
                }
            }
        }
    }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
