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

int sum(ll x){
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    int ans = 0;
    for(char c : s){
        ans += (c-'0');
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ll n;
        int s;
        cin >> n >> s;
        if(sum(n) <= s){
            cout << "0\n";
            continue;
        }
        ll p = 1ll;
        ll tmp = n;
        for(int i=1;true;++i){
            n += p*(10ll - ((n/p)%10));
            if(sum(n) <= s){
                break;
            }
            p *= 10ll;
        }
        cout << n-tmp << endl;
    }
}
