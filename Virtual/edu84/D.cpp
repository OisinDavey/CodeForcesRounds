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

vector<int> operator*(vector<int>& a, vector<int>& b){
    int n = a.size();
    vector<int> res(n);
    for(int i=0;i<n;++i){
        res[i] = b[a[i]];
    }
    return res;
}

vector<int> binpow(vector<int>& base, int expo){
    if(expo == 1){
        return base;
    }else if(expo % 2 == 1){
        vector<int> tmp = binpow(base, expo/2);
        vector<int> res = tmp * base;
        res = tmp * res;
        return res;
    }else{
        vector<int> tmp = binpow(base, expo/2);
        vector<int> res = tmp * tmp;
        return res;
    }
}

bool rep(vector<int>& a, vector<int>& C){//returns whether or not the array a (ie A^k) has an infinite cycle such that Ɐ i ϵ subcycle, C[i] is invariant
    int m = a.size();
    bool vis[m];
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<m;++i){
        if(vis[i]){
            continue;
        }
        vis[i] = true;
        int cur_pos = a[i];
        bool bad = false;
        while(cur_pos != i){
            vis[cur_pos] = true;
            if(C[cur_pos] != C[i]){
                bad = true;
            }
            cur_pos = a[cur_pos];
        }
        if(!bad){
            return true;
        }
    }
    return false;
}

int solve(){
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for(int i=0;i<n;++i){
        cin >> p[i];
        --p[i];
    }
    for(int i=0;i<n;++i){
        cin >> c[i];
        --c[i];
    }
    vector<vector<int> > cycles;
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<n;++i){
        if(vis[i]){
            continue;
        }
        vis[i] = true;
        vector<int> tmp = {i};
        int cur_pos = p[i];
        while(cur_pos != i){
            vis[cur_pos] = true;
            tmp.pb(cur_pos);
            cur_pos = p[cur_pos];
        }
        cycles.pb(tmp);
    }
    ll best = INF;
    for(vector<int>& cycle : cycles){
        int m = cycle.size();
        sort(All(cycle));
        vector<int> A(m);
        vector<int> C(m);
        vector<pair<int, int> > tmp(m);
        bool seen[m+1];
        memset(seen, 0, sizeof(seen));
        for(int i=0;i<m;++i){
            A[i] = p[cycle[i]];
            tmp[i] = mp(A[i], i);
            C[i] = c[cycle[i]];
        }
        sort(All(tmp));
        map<int, int> pos;
        for(int i=0;i<m;++i){
            pos[tmp[i].fi] = i;
        }
        for(int i=0;i<m;++i){
            A[i] = pos[A[i]];
        }

        for(int k=1;k<=m;++k){
            if(seen[gcd(k, m)]){
                continue;
            }
            seen[gcd(k, m)] = true;
            vector<int> a = binpow(A, k);
            if(rep(a, C)){
                best = min(best, (ll)k);
            }
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
