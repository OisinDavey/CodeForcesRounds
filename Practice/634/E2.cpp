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

void solve(){
    int n;
    int AL = 200;
    cin >> n;
    int a[n];
    int pref[n][AL+1];
    memset(pref, 0, sizeof(pref));
    vector<int> pos[AL+1];
    for(int i=0;i<n;++i){
        cin >> a[i];
        ++pref[i][a[i]];
        pos[a[i]].pb(i);
        if(i == 0){
            continue;
        }
        for(int c=0;c<=AL;++c){
            pref[i][c] += pref[i-1][c];
        }
    }
    int ans = 0;
    for(int p=0;p<=AL;++p){
        int m = pos[p].size();
        ans = max(pref[n-1][p], ans);
        for(int k=1;k<=(m/2);++k){
            for(int c=0;c<=AL;++c){
                int tmp = 0;
                tmp += 2*k;
                tmp += pref[pos[p][m-k]-1][c]-pref[pos[p][k-1]][c];
                ans = max(tmp, ans);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
