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
        ll a, b, c, d, n;
        cin >> a >> b >> c >> d >> n;
        ll A, B, C, D, N;
        B = a, A = b, C = d, D = c, N = n;
        if(a-c >= n){
            a -= n;
            n = 0;
        }else{
            n -= (a-c);
            a = c;
            if(b-d >= n){
                b -= n;
                n = 0;
            }else{
                n -= (b-d);
                b = d;
            }
        }
        if(A-C >= N){
            A -= N;
            N = 0;
        }else{
            N -= (A-C);
            A = C;
            if(B-D >= N){
                B -= N;
                N = 0;
            }else{
                N -= (B-D);
                B = D;
            }
        }
        cout << min(a*b, A*B) << endl;
    }
}
