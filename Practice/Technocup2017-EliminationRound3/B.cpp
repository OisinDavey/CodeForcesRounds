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
    string a, b;
    cin >> a >> b;
    map<int, int> m;
    for(int i=0;i<26;++i){
        m[i] = -1;
    }
    int n = a.size();
    for(int i=0;i<n;++i){
        int _a = a[i]-'a';
        int _b = b[i]-'a';
        if(m[_a] == -1 && m[_b] == -1){
            m[_a] = _b;
            m[_b] = _a;
        }else if((m[_a] == -1 && m[_b] != -1) || (m[_a] != -1 && m[_b] == -1)){
            cout << "-1\n";
            return 0;
        }else if(m[_a] != _b || m[_b] != _a){
            cout << "-1\n";
            return 0;
        }
    }
    bool done[26];
    memset(done, 0, sizeof(done));
    vector<pair<char, char> > ans;
    for(int i=0;i<n;++i){
        int _a = a[i]-'a';
        int _b = b[i]-'a';
        if(!done[_a]){
            done[_a] = true;
            done[_b] = true;
            if(a[i] != b[i]){
                ans.pb({a[i], b[i]});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto& [ca, cb] : ans){
        cout << ca << ' ' << cb << endl;
    }
}
