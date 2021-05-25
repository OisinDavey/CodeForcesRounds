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

int Q(int t, int i, int j, int x){
    cout << "? " << t << ' ' << i+1 << ' ' << j+1 << ' ' << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    int ans[n+1];
    ans[n] = n-1;
    for(int i=0;i+1<n;i+=2){
        int tmp = Q(1, i, i+1, n-1);
        if(tmp == n-1){
            if(Q(2, i, i+1, n-1) == n){
                ans[n] = i;
                break;
            }
        }
        if(tmp == n){
            ans[n] = i+1;
            break;
        }
    }
    for(int i=0;i<n;++i){
        if(i == ans[n]){
            continue;
        }
        int tmp = Q(2, ans[n], i, 1);
        if(tmp == 2){
            if(Q(1, ans[n], i, 1) == 1){
                ans[1] = i;
            }else{
                ans[2] = i;
            }
        }else{
            ans[tmp] = i;
        }
    }
    int O[n+1];
    for(int i=1;i<=n;++i){
        O[ans[i]+1] = i;
    }
    cout << "! ";
    for(int i=1;i<=n;++i){
        cout << O[i] << ' ';
    }
    cout << endl;
    cout.flush();
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
