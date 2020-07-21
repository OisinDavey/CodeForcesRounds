//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            500001 
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

ll h[MX_N];
ll dp[MX_N][2];

int L[MX_N];
int R[MX_N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> h[i];
    }
    if(n == 1){
        cout << h[0] << endl;
        return 0;
    }
    for(int i=0;i<n;++i){
        int pos = i-1;
        while(true){
            if(pos == -1){
                L[i] = -1;
                break;
            }else{
                if(h[pos] <= h[i]){
                    L[i] = pos;
                    break;
                }else{
                    pos = L[pos];
                }
            }
        }
    }
    for(int i=n-1;~i;--i){
        int pos = i+1;
        while(true){
            if(pos == n){
                R[i] = n;
                break;
            }else{
                if(h[pos] <= h[i]){
                    R[i] = pos;
                    break;
                }else{
                    pos = R[pos];
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        dp[i][0] = 0ll;
        dp[i][0] += h[i]*(i-L[i]);
        if(L[i] != -1){
            dp[i][0] += dp[L[i]][0];
        }
    }
    for(int i=n-1;~i;--i){
        dp[i][1] = 0ll;
        dp[i][1] += h[i]*(R[i]-i);
        if(R[i] != n){
            dp[i][1] += dp[R[i]][1];
        }
    }
    pair<int, ll> best = mp(-1, -1ll);
    for(int i=0;i<n-1;++i){
        if(dp[i][0] + dp[i+1][1] > best.se){
            best.fi = i;
            best.se = dp[i][0] + dp[i+1][1];
        }
    }
    ll ans[n];
    ans[best.fi] = h[best.fi];
    for(int i=best.fi-1;~i;--i){
        ans[i] = min(h[i], ans[i+1]);
    }
    for(int i=best.fi+1;i<n;++i){
        if(i == best.fi+1){
            ans[i] = h[i];
        }else{
            ans[i] = min(h[i], ans[i-1]);
        }
    }
    for(int i=0;i<n;++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
