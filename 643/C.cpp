//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
#define mod7            1000000007
#define modpi           314159
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

using namespace std;

ll tri(ll x){
    return x*(x+1)/2;
}

ll NinRange(ll a, ll b, ll c, ll d){
    if(a > d)
        return (d-c+1)*(b-a+1);
    a = max(a, c);
    d = min(d, b);
    if(a > b || c > d)
        return 0;
    return (a-c)*(d-a+1)+tri(d-a)+(b-d)*(d-c+1);
}

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll count = 0;
    for(int x = A;x<=B;++x){
        ll a = B+x;
        ll b = C+x;
        ll c = C;
        ll d = D;
        count += NinRange(a, b, c, d);
    }
    cout << count << endl;
}