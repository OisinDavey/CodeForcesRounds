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
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int a[n];
        bitset<1025> in_set;
        in_set.set();
        in_set.flip();
        for(int i=0;i<n;++i){
            cin >> a[i];
            in_set[a[i]] = 1;
        }
        int best = (1 << 30);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int k = a[i] ^ a[j];
                for(int v=0;v<n;++v){
                    if(!in_set[a[v] ^ k]){
                        break;
                    }else{
                        if(v == n-1){
                            best = min(best, k);
                        }
                    }
                }
            }
        }
        if(best == (1 << 30)){
            cout << "-1\n";
        }else{
            cout << best << endl;
        }
    }
}
