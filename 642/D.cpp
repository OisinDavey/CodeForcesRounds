//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
#define mod7            1000000007
#define modpi           314159
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


struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.fi < b.fi)
            return 1;
        else if(b.fi < a.fi)
            return 0;
        else if(a.se > b.se)
            return 1;
        else
            return 0;
    }
};

int main(){
    FastIO;
    int t;
    cin >> t;
    while(t--){
        int n;
        int gint = 1;
        cin >> n;
        priority_queue<pair<int, int> , vector<pair<int, int> >, comp> PQ;
        PQ.push({n, 0});
        int ans[n];
        memset(ans, 0, sizeof(ans));
        while(!PQ.empty()){
            pair<int, int> at = PQ.top();
            PQ.pop();
            if(at.fi % 2 == 0){
                int pos = at.se;
                int siz = (at.fi-1)/2;
                pos += siz;
                ans[pos] = gint++;
                if(at.fi > 1){
                    PQ.push({siz+1, pos+1});
                    if(at.fi > 2)
                        PQ.push({siz , at.se});
                }
            }else{
                int pos = at.se;
                int siz = (at.fi-1)/2;
                pos += siz;
                ans[pos] = gint++;
                if(at.fi > 1){
                    PQ.push({siz, pos+1});
                    if(at.fi > 2)
                        PQ.push({siz, at.se});
                }
            }
        }
        for(int i=0;i<n;++i) cout << ans[i] << ' ';
        cout << endl;
    }
}
