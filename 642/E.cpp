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
    FastIO;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        bool a[n];
        ll ML[n];
        ll MF[n];
        ll ZK[n];
        ll F[n];
        for(int i=0;i<n;++i){
            char x;
            cin >> x;
            a[i] = (x=='1');
        }
        ll numones = 0;
        for(int i=0;i<n;++i) numones += (a[i]==1); 
        ll numones2 = numones;
        ll minn = numones; 
        for(int i=0;i<n;++i){
            if(a[i]==1)
                --numones;
            ML[i] = numones;
        }
        for(int i=n-1;i>=0;--i){
            if(a[i]==1)
                --numones2;
            MF[i] = numones2;
        }
        for(int i=0;i<n;++i){
            if(i > (n-k-1))
                ZK[i] = ML[i];
            else
                ZK[i] = ML[i]-ML[i+k-1];
        }
        for(int i=n-1;i>=0;--i){
            if(i > (n-k-1))
                F[i] = (a[i]==0) + ML[i];
            else
                F[i] = (a[i]==0) + min(ZK[i] + F[i+k], ML[i]);
        }
        for(int i=0;i<n;++i)
            minn = min(minn, F[i]+MF[i]);
        cout << minn << endl;
    }
}
