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
        ll a, b, p;
        cin >> a >> b >> p;
        string s;
        cin >> s;
        int n = s.size();
        ll dp[n];
        dp[n-1] = 0;
        for(int i=n-2;~i;--i){
            dp[i] = dp[i+1];
            if((i == n-2) || (s[i] != s[i+1])){
                if(s[i] == 'A'){
                    dp[i] += a;
                }else{
                    dp[i] += b;
                }
            }
        }
        int best = -1;
        for(int i=0;i<n;++i){
            if(dp[i] <= p){
                best = i;
                break;
            }
        }
        //best is furthest we can go without buying
        if(best == -1){
            cout << n << endl;
        }else{
            cout << best+1 << endl;
        }
    }
}
