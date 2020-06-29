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
    int n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    stack<int> free;
    stack<int> PQ;
    ll ans[n];
    memset(ans, -1, sizeof(ans));
    for(int i=(1e06);i>=0;--i){
        PQ.push(i);
    }
    for(int i=0;i<n;++i){
        free.push(i);
        while(true){
            if(PQ.empty()){
                cout << "-1\n";
                return 0;
            }
            if(PQ.top() < a[i]){
                if(free.empty()){
                    cout << "-1\n";
                    return 0;
                }
                ans[free.top()] = PQ.top();
                PQ.pop();
                free.pop();
            }else{
                break;
            }
        }
    }
    //Check if it actually worked
    ll mex = 0;
    bool seen[1000001];
    memset(seen, 0, sizeof(seen));
    for(int i=0;i<n;++i){
        if(ans[i] == -1){
            ans[i] = 1e06 - 1;
        }
        seen[ans[i]] = true;
        while(mex < 1e06 && seen[mex]){
            ++mex;
        }
        if(mex != a[i]){
            cout << "-1\n";
            return 0;
        }
//        cout << "mex at " << i << " = " << mex << endl;
    }
    for(int i=0;i<n;++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
