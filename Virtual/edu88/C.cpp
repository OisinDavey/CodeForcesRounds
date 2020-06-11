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

double x, y;
double t;

double f(ll n){
    return ((x + y)/2) + ((x - y)/(2*n));
}

int main(){
    FastIO;
    int T;
    cin >> T;
    while(T--){
        cin >> x >> y >> t;
        if(x == t){
            cout << 1 << endl;
            continue;
        }
        if(2*t == x + y){
            cout << 2 << endl;
            continue;
        }
        double approx = (x - y)/(2*t - x - y);
        ll guess = floor(approx);
        if(guess % 2 == 0){
            ++guess;
        }
        if(guess < 0){
            guess = 1;
        }
        if(abs(t - f(guess)) >= abs(t - f(guess - 2)) && guess > 2){
            guess -= 2;
        }else if(abs(t - f(guess)) > abs(t - f(guess + 2))){
            guess += 2;
        }
        if(abs(t - f(guess)) == abs(t - (x + y)/2)){
            if(guess > 2){
                cout << 2 << endl;
            }else{
                cout << guess << endl;
            }
        }else if(abs(t - f(guess)) < abs(t - (x + y)/2)){
            cout << guess << endl;
        }else{
            cout << 2 << endl;
        }
    }
}
