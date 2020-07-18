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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n+1];
    int ans = 0;
    a[0] = 0;
    for(int i=1;i<=n;++i){
        if(s[i-1] == '('){
            a[i] = a[i-1]+1;
        }else{
            a[i] = a[i-1]-1;
        }
        if(a[i] < 0){
            ++ans;
        }else if(a[i] == 0 && a[i-1] < 0){
            ++ans;
        }
    }
    if(a[n] == 0){
        cout << ans << endl;
    }else{
        cout << "-1\n";
    }
}