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

void solve(ll n){
    if(n == 1){
        cout << "FastestFinger\n";
        return;
    }
    if(n == 2){
        cout << "Ashishgup\n";
        return;
    }
    int twos = 0;
    int others = 0;
    int i = 2;
    while(i <= sqrt(n)){
        while(n % i == 0){
            n /= i;
            if(i == 2){
                ++twos;
            }else{
                ++others;
            }
        }
        ++i;
    }
    if(n == 2){
        ++twos;
    }else if(n != 1){
        ++others;
    }
    if(twos == 0){
        cout << "Ashishgup\n";
    }else if(others == 0){
        cout << "FastestFinger\n";
    }else if(others + twos <= 2){
        cout << "FastestFinger\n";
    }else{
        cout << "Ashishgup\n";
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //FastestFinger
        //Ashishgup
        ll n;
        cin >> n;
        solve(n);
    }
}
