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
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a == b){
            cout << "0\n";
        }else if(a > b){
            if(a % b != 0){
                cout << "-1\n";
                continue;
            }
            ll x = a/b;
            int ans = 0;
            while(x % 8 == 0){
                ++ans;
                x/=8;
            }while(x % 4 == 0){
                ++ans;
                x/=4;
            }while(x % 2 == 0){
                ++ans;
                x/=2;
            }
            if(x == 1){
                cout << ans << endl;
            }else{
                cout << "-1\n";
            }
        }else{
            if(b % a != 0){
                cout << "-1\n";
                continue;
            }
            ll x = b/a;
            int ans = 0;
            while(x % 8 == 0){
                ++ans;
                x/=8;
            }while(x % 4 == 0){
                ++ans;
                x/=4;
            }while(x % 2 == 0){
                ++ans;
                x/=2;
            }
            if(x == 1){
                cout << ans << endl;
            }else{
                cout << "-1\n";
            }
        }
    }
}
