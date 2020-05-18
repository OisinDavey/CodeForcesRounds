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

bool pref[200000];
bool suff[200000];
int prefm[200000];
int suffm[200000];
int a[200000];

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(pref, 0, sizeof(pref));
        memset(suff, 0, sizeof(suff));
        int prefbad = 200001;
        int suffbad = -1;
        int n;
        cin >> n;
        int numunique = 0;
        for(int i=0;i<n;++i) cin >> a[i];
        pref[a[0]] = 1;
        prefm[0] = a[0];
        for(int i=1;i<n;++i){
            prefm[i] = max(prefm[i-1], a[i]);
            if(pref[a[i]])
                prefbad = min(i, prefbad);
            pref[a[i]] = 1;
        }
        suff[a[n-1]] = 1;
        suffm[n-1] = a[n-1];
        for(int i=n-2;i>=0;--i){
            suffm[i] = max(suffm[i+1], a[i]);
            if(suff[a[i]])
                suffbad = max(i, suffbad);
            suff[a[i]] = 1;
        }
        vector<int> ans;
        for(int i=0;i<n-1;++i)
            if(i < prefbad && i+1 > suffbad)
                if(prefm[i] == i+1 && suffm[i+1] == n-(i+1))
                    ans.pb(i);
        cout << ans.size() << endl;
        for(int x : ans)
            cout << x+1 << ' ' << n-(x+1) << endl;
    }
}
