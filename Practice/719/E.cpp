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
    cin >> n;
    char s[n];
    for(int i=0;i<n;++i){
        cin >> s[i];
    }
    if(n == 1){
        cout << "0\n";
        return;
    }
    ll L[n];
    ll R[n];
    ll c = 0ll;
    if(s[0] == '*'){
        c = 1ll;
    }
    L[0] = 0;
    for(int i=1;i<n;++i){
        if(s[i] == '.'){
            L[i] = L[i-1] + c;
        }else{
            L[i] = L[i-1];
            ++c;
        }
    }
    c = 0ll;
    if(s[n-1] == '*'){
        c = 1ll;
    }
    R[n-1] = 0;
    for(int i=n-2;~i;--i){
        if(s[i] == '.'){
            R[i] = R[i+1] + c;
        }else{
            R[i] = R[i+1];
            ++c;
        }
    }
    ll ans = INF;
    for(int i=0;i<n-1;++i){
        ans = min(ans, L[i]+R[i+1]);
    }
    cout << ans << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
