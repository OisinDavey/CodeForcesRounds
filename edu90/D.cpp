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
    FastIO;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ll a[n];
        ll sum[n+1];
        sum[0] = 0;
        for(int i=0;i<n;++i){
            cin >> a[i];
            if(i % 2 == 1){
                sum[i+1] = a[i] + sum[i];
            }else{
                sum[i+1] = -1*a[i] + sum[i];
            }
        }
        ll lowest = INF;
        int lowpos = 0;
        ll best = -INF;
        pair<int, int> bestpos = {0, 0};
        for(int i=0;i<=n;i+=2){
            if(sum[i] < lowest){
                lowest = sum[i];
                lowpos = i;
            }
            if(sum[i] - lowest > best){
                best = sum[i] - lowest;
                bestpos = {lowpos, i};
            }
        }
        lowest = INF;
        lowpos = 0;
        for(int i=1;i<=n;i+=2){
            if(sum[i] < lowest){
                lowest = sum[i];
                lowpos = i;
            }
            if(sum[i] - lowest > best){
                best = sum[i] - lowest;
                bestpos = {lowpos, i};
            }
        }
        reverse(a + bestpos.fi, a + bestpos.se);
        ll evensum = 0;
        for(int i=0;i<n;i+=2){
            evensum += a[i];
        }
        cout << evensum << endl;
    }
}
