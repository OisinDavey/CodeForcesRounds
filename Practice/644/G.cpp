//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            51 
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
    FastIO;
    bool ans[MX_N][MX_N];
    int n, m, a, b;
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> a >> b;
        memset(ans, 0, sizeof(ans));
        int d;
        int pos = 0;
        if(a*n != b*m){
            cout << "NO\n";
            goto end_of_loop;
        }
        for(int i=1;i<m;++i){
            if((i*n)%m == 0){
                d = i;
                break;
            }
        }
        for(int i=0;i<n;++i){
           for(int j=0;j<a;++j){
               ans[i][(pos+j)%m] = 1;
           }
           pos += d;
        }
        cout << "YES\n";
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout << ans[i][j];
            }
            cout << endl;
        }
        end_of_loop:;
    }
}
