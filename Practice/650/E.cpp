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

int bucket[26];

bool can_be_done(int n, int k){
    int cur_pos = 0;
    int cycle = 1;
    int available = 0;
    cur_pos += k;
    cur_pos %= n;
    while(cur_pos != 0){
        ++cycle;
        cur_pos += k;
        cur_pos %= n;
    }
    for(int item : bucket){
        available += item/cycle;
    }
    int need = n/cycle;
    return (need <= available);
}

void solve(){
    int n, k;
    cin >> n >> k;
    memset(bucket, 0, sizeof(bucket));
    for(int i=0;i<n;++i){
        char x;
        cin >> x;
        ++bucket[x-'a'];
    }
    int best = -1;
    for(int i=1;i<=n;++i){
        if(can_be_done(i, k)){
            best = i;
        }
    }
    cout << best << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
