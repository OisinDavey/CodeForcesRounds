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

ll fenw[100001];

void update(int at, int val){
    ++at;
    while(at < 100001){
        fenw[at] += val;
        at += (at)&(-at);
    }
    return;
}

ll query(int at){
    ++at;
    ll res = 0ll;
    while(at > 0){
        res += fenw[at];
        at -= (at)&(-at);
    }
    return res;
}

ll inversions(string& a, string& b){
    vector<int> A, N, T, O;
    int n = a.size();
    for(int i=0;i<n;++i){
        switch(a[i]){
            case 'A':
                A.pb(i);
                break;
            case 'N':
                N.pb(i);
                break;
            case 'T':
                T.pb(i);
                break;
            case 'O':
                O.pb(i);
                break;
        }
    }
    int _A = 0, _N = 0, _T = 0, _O = 0;
    int p[n];
    for(int i=0;i<n;++i){
        switch(b[i]){
            case 'A':
                p[i] = A[_A];
                ++_A;
                break;
            case 'N':
                p[i] = N[_N];
                ++_N;
                break;
            case 'T':
                p[i] = T[_T];
                ++_T;
                break;
            case 'O':
                p[i] = O[_O];
                ++_O;
                break;
        }
    }
    for(int i=0;i<=n;++i){
        fenw[i] = 0;
    }
    update(p[n-1], +1);
    ll ans = 0;
    for(int i=n-2;~i;--i){
        int delta = query(p[i]);
        ans += delta;
        update(p[i], +1);
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    string best = s;
    ll ans = 0;
    int A = 0, N = 0, T = 0, O = 0;
    for(char c : s){
        A += (c == 'A');
        N += (c == 'N');
        T += (c == 'T');
        O += (c == 'O');
    }
    vector<string> perms = {"ANTO", "ANOT", "ATNO", "ATON", "AONT", "AOTN", "NATO", "NAOT", "NTAO", "NTOA", "NOAT", "NOTA", "TANO", "TAON", "TNAO", "TNOA", "TOAN", "TONA", "OANT", "OATN", "ONAT", "ONTA", "OTAN", "OTNA"};
    for(string a : perms){
        string tst = "";
        for(char c : a){
            int cnt;
            switch(c){
                case 'A':
                    cnt = A;
                    break;
                case 'N':
                    cnt = N;
                    break;
                case 'T':
                    cnt = T;
                    break;
                case 'O':
                    cnt = O;
                    break;
            }
            for(int i=0;i<cnt;++i){
                tst += c;
            }
        }
        ll tmp = inversions(s, tst);
        if(tmp > ans){
            ans = tmp;
            best = tst;
        }
    }
    cout << best << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
