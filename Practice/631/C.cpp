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

int main(){
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<ll> l(m);
    for(int i=0;i<m;++i) cin >> l[i];
    reverse(All(l));
    ll S = accumulate(All(l), 0ll);
    ll O = S-n;
    int it = 0;
    vector<int> ans;
    for(int i=0;i<m;++i){
        if(O == 0){//We've done all overlap we need
            ans.pb(it);
            it += l[i];
        }else if(O > 0){//We need to overlap some more
             if(l[i]-1 <= O){//Do as much overlap as we can
                if(it < l[i]){//We can only go so left
                    ans.pb(0);
                    O -= it;
                    it = l[i];
                }else{//We can go as left as we want
                    ans.pb(it - (l[i]-1));
                    O -= l[i]-1;
                    it += 1;
                }
            }else{//Do remaining overlap
                if(it < O){//We can only go so left
                    ans.pb(0);
                    O -= it;
                    it = l[i];
                }else{
                    ans.pb(it - O);
                    it += l[i]-O;
                    O = 0;
                }
            }
        }else{//We've overdone it tbh
            break;
        }
    }
    if(O == 0 && it == n){
        for(int i = ans.size()-1;i>=0;--i)
            cout << 1+ans[i] << ' ';
        cout << endl;
    }else{
        cout << "-1\n";
    }
}
