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
    int n, k;
    cin >> n >> k;
    char a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
        if(a[i] == '?'){
            a[i] = '2';
        }
    }
    int cnt[3][k];
    memset(cnt, 0, sizeof(cnt));
    for(int i=0;i<n;++i){
        ++cnt[a[i]-'0'][i%k];
    }
    bool bad = false;
    for(int i=0;i<k;++i){
        if(cnt[0][i]){
            for(int j=i;j<n;j+=k){
                a[j] = '0';
            }
        }
        if(cnt[1][i]){
            for(int j=i;j<n;j+=k){
                a[j] = '1';
            }
        }
        if(cnt[0][i] && cnt[1][i]){
            bad = true;
        }
    }
    int A = 0;
    int B = 0;
    for(int i=0;i<k;++i){
        A += (a[i] == '0');
        B += (a[i] == '1');
    }
    if(A > k/2 || B > k/2){
        bad = true;
    }
    cout << (bad?"NO\n":"YES\n");
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
