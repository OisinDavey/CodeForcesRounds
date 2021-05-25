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

int Z[1000000];
int k;

int Q(int l, int r){
    cout << "? " << l+1 << " " << r+1 << endl;
    cout.flush();
    int res;
    cin >> res;
    return r-l+1-res;
}

bool in_seg(int at, int l, int r){
    if(Z[at] == -1){
        Z[at] = (at%2)?(Z[at/2] - Z[at-1]):(Q(l, r));
    }
    if(Z[at] < k){
        k -= Z[at];
        return false;
    }
    if(l == r){
        cout << "! " << l+1 << endl;
        cout.flush();
        --Z[at];
        return true;
    }
    int m = l + (r-l)/2;
    if(!in_seg(at*2, l, m)){
        in_seg(at*2 + 1, m+1, r);
    }
    --Z[at];
    return true;
}

int main(){
    int n, t;
    cin >> n >> t;
    memset(Z, -1, sizeof(Z));
    cin >> k;
    --t;
    Z[1] = Q(0, n-1);
    in_seg(1, 0, n-1);
    while(t--){
        cin >> k;
        in_seg(1, 0, n-1);
    }
}
