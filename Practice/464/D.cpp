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

int p[26];

int find_set(int at){
    if(p[at] == at){
        return at;
    }else{
        return p[at] = find_set(p[at]);
    }
}

void union_set(int a, int b){
    int _a = find_set(a);
    int _b = find_set(b);
    if(_a == _b){
        return;
    }
    p[_b] = _a;
    return;
}

int main(){
    for(int i=0;i<26;++i){
        p[i] = i;
    }
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i=0;i<n;++i){
        union_set(a[i]-'a', b[i]-'a');
    }
    set<int> kids[26];
    for(int i=0;i<n;++i){
        if(p[a[i]-'a'] != a[i]-'a'){
            kids[find_set(a[i]-'a')].insert(a[i]-'a');
        }
        if(p[b[i]-'a'] != b[i]-'a'){
            kids[find_set(b[i]-'a')].insert(b[i]-'a');
        }
    }
    int ans = 0;
    vector<pair<int, int> > p;
    for(int i=0;i<26;++i){
        if(kids[i].empty()){
            continue;
        }
        ans += kids[i].size();
        for(int x : kids[i]){
            p.pb({x, i});
        }
    }
    cout << ans << endl;
    for(pair<int, int> x : p){
        cout << (char)(x.fi+'a') << ' ' << (char)(x.se+'a') << endl;
    }
}
