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
        int n, x;
        cin >> n >> x;
        ll a[n];
        for(int i=0;i<n;++i){
            cin >> a[i];
        }
        ll sum[n+1];
        sum[0] = 0;
        for(int i=1;i<=n;++i){
            sum[i] = sum[i-1] + a[i-1];
        }
        for(int i=0;i<=n;++i){
            sum[i] %= x;
        }
        vector<pair<int, int> > v;
        v.pb(mp(0, 0));
        for(int i=1;i<=n;++i){
            if(sum[i] == sum[i-1]){
                v[v.size()-1].se = i;
            }else{
                v.pb(mp(i, i));
            }
        }
        int best = -1;
        for(int i=0;i<v.size();++i){
            //Find earliest occurance of not at
            int pos = v[i].fi;
            for(int j=0;j<i;++j){
                if(sum[v[j].fi] != sum[v[i].fi]){
                    pos = v[j].fi;
                    break;
                }
            }
            if(pos != v[i].fi){
                best = max(best, v[i].se - pos);
            }
        }
        if(best == -INF){
            cout << "-1\n";
        }else{
            cout << best << endl;
        }
    }
}
