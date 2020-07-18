//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            131073 
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

string s;
int n;

int seg[2*MX_N+1];

char val[2*MX_N+1];
int cost[2*MX_N+1][26];

pair<int, int> LR[2*MX_N+1];

void fill_val(int pos){
    if(pos == 1){
        val[pos] = 0;
        LR[pos] = mp(0, n-1);
    }else{
        int par = pos/2;
        val[pos] = val[pos/2]+1;
        pair<int, int> tmp = LR[pos/2];
        int M = tmp.fi + (tmp.se - tmp.fi)/2;
        if(pos == par*2){
            LR[pos] = mp(tmp.fi, M);
        }else{
            LR[pos] = mp(M+1, tmp.se);
        }
    }
    if(pos >= n){
        for(int i=0;i<26;++i){
            if(s[pos-n]-'a' == i){
                cost[pos][i] = 0;
            }else{
                cost[pos][i] = 1;
            }
        }
    }else{
        fill_val(pos*2);
        fill_val(pos*2 + 1);
        for(int i=0;i<26;++i){
            cost[pos][i] = cost[pos*2][i] + cost[pos*2+1][i];
        }
    }
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cin >> s;
        fill_val(1);
        for(int i=(2*n)-1;i>0;--i){
            if(i >= n){
                if(s[i-n]-'a' == val[i]){
                    seg[i] = 0;
                }else{
                    seg[i] = 1;
                }
            }else{
                int tmp1 = 0, tmp2 = 0;
                tmp1 += seg[2*i];
                tmp1 += cost[2*i+1][val[i]];
                tmp2 += seg[2*i+1];
                tmp2 += cost[2*i][val[i]];
                seg[i] = min(tmp1, tmp2);
            }
        }
        cout << seg[1] << endl;
    }
}
