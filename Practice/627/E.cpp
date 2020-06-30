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

void modulo(int& x, int& mod){
    if(x >= mod){
        x %= mod;
    }
}

int main(){
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    int dp[n][h];
    memset(dp, 0, sizeof(dp));
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<h;++j){
            int pos_1 = j+a[i];
            modulo(pos_1, h);
            int pos_2 = j+a[i]-1;
            modulo(pos_2, h);
            int val_1 = (pos_1 >= l && pos_1 <= r) + ((i== n-1)?0:dp[i+1][pos_1]);
            int val_2 = (pos_2 >= l && pos_2 <= r) + ((i== n-1)?0:dp[i+1][pos_2]);
            dp[i][j] = max(val_1, val_2);
        }
    }
    cout << dp[0][0] << endl;
}
