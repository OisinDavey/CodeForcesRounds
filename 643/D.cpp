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

int main(){
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i=0;i<n-1;++i) a[i] = 2;
    a[n-1] = s-2*(n-1);
    if(a[n-1] <= 0){
        cout << "NO\n";
        return 0;
    }
    if(s%2==0){
        cout << "YES\n";
        for(int i=0;i<n;++i){
            cout << a[i] << ' ';
        }
        cout << endl << 1 << endl;
    }else{
        int temp = (s-1)/2;
        if(temp <= (n-1)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for(int i=0;i<n;++i){
                cout << a[i] << ' ';
            }
            cout << endl << 1 << endl;
        }
    }
}
