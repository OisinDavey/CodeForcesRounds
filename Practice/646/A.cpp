//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
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

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, x;
        cin >> n >> x;
        int o = 0, e = 0;
        int num;
        for(int i=0;i<n;++i){
            cin >> num;
            o += (num % 2 == 1);
            e += (num % 2 == 0);
        }
        if(o == 0){
            cout << "No\n";
        }else if(x >= o){
            x -= (o - !(o % 2));
            if(x > e){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }else{
            x -= (x - !(x % 2));
            if(x > e){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }
    }
}
