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
        string s;
        cin >> s;
        int n = s.size();
        int mount = 0;
        int lowest = 1e09;
        map<int, int> first_seen;
        for(int i=0;i<n;++i){
            if(s[i] == '-'){
                --mount;
            }else{
                ++mount;
            }
            if(first_seen[mount] == 0){
                first_seen[mount] = i+1;
            }
            lowest = min(lowest, mount);
        }
        if(lowest >= 0){
            cout << n << endl;
        }else{
            ll ans = 0;
            for(int i= -1;i>=lowest;--i){
                ans += first_seen[i];
            }
            ans += n;
            cout << ans << endl;
        }
    }
}
