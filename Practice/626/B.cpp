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
    int n, m, k;
    cin >> n >> m >> k;
    bool a[n+1];
    bool b[m+1];
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    for(int i=1;i<=m;++i){
        cin >> b[i];
    }
    map<int, ll> freqa;
    map<int, ll> freqb;
    a[0] = 0;
    b[0] = 0;
    ll sa[n+1];
    ll sb[m+1];
    memset(sa, 0, sizeof(sa));
    memset(sb, 0, sizeof(sb));
    for(int i=1;i<=n;++i){
        if(a[i] == 0){
            sa[i] = 0ll;
            if(i != 1){
                freqa[sa[i-1]]++;
            }
        }else{
            sa[i] = sa[i-1] + 1ll;
        }
    }
    if(sa[n] != 0ll){
        freqa[sa[n]]++;
    }
    for(int i=1;i<=m;++i){
        if(b[i] == 0){
            sb[i] = 0ll;
            if(i != 1){
                freqb[sb[i-1]]++;
            }
        }else{
            sb[i] = sb[i-1] + 1ll;
        }
    }
    if(sb[m] != 0ll){
        freqb[sb[m]]++;
    }
    map<int, ll> ma;
    map<int, ll> mb;
    ll ans = 0ll;
    for(auto it = freqa.begin(); it != freqa.end();++it){
        int x = it->first;
        ll freq = it->second;
        for(int i=0;i<x;++i){
            int tmp = x-i;
            ma[tmp] += freq*(i+1);
        }
    }
    for(auto it = freqb.begin(); it != freqb.end();++it){
        int x = it->first;
        ll freq = it->second;
        for(int i=0;i<x;++i){
            int tmp = x-i;
            mb[tmp] += freq*(i+1);
        }
    }
    for(auto it = ma.begin();it!=ma.end();++it){
        int x = it->first;
        ll freq = it->second;
        if(x > k){
            continue;
        }
        if(k%x != 0){
            continue;
        }
        ans += freq*mb[k/x];
    }
    cout << ans << endl;
}
