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

vector<int> ans;

void flip(vector<bool>& a, int p){
    ans.pb(p);
    for(int i=0;i<=p;++i){
        a[i] = !a[i];
    }
    reverse(a.begin(), a.begin()+p+1);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ans = {};
        vector<bool> a;
        vector<bool> b;
        for(int i=0;i<n;++i){
            char x;
            cin >> x;
            a.pb(x=='1');
        }
        for(int i=0;i<n;++i){
            char x;
            cin >> x;
            b.pb(x=='1');
        }
        for(int p=n-1;~p;--p){
            if(a[p] == b[p]){
                continue;
            }
            if(b[p] == a[0]){
                //Flip twice
                flip(a, 0);
                flip(a, p);
            }else{
                flip(a, p);
            }
        }
        cout << ans.size() << ' ';
        for(int x : ans){
            cout << x+1 << ' ';
        }
        cout << endl;
    }
}
