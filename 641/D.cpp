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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        int b[n];
        for(int i=0;i<n;++i){
            cin >> a[i];
            if(a[i] < k)
                b[i] = -1;
            else if(a[i] == k)
                b[i] = 0;
            else
                b[i] = 1;
        }
        bool KinA = 0;
        for(int i=0;i<n;++i)
            if(b[i]==0)
                KinA=1;
        if(!KinA){
            cout << "no\n";
            continue;
        }
        if(n==1){
            cout << "yes\n";
            continue;
        }
        bool B = 0;
        for(int i=0;i<n;++i){
            if(i < n-1)
                if(b[i] >= 0 && b[i+1] >= 0)
                   B = 1;
            if(i < n-2)
                if(b[i] >= 0 && b[i+2] >= 0)
                    B = 1;
        }
        if(B)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
