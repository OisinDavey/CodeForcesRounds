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

const long long big = 1e16;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        ll k;
        cin >> n >> k;
        ll a[n];
        for(int i=0;i<n;++i){
            cin >> a[i];
        }
        ll pows[56];
        pows[0] = 1ll;
        int biggest;
        for(int i=1;i<=55;++i){
            if(pows[i-1] >= big){
                break;
            }else{
                pows[i] = k * pows[i-1];
            }
            biggest = i;
        }
        int cnt = 0;
        set<int> s;
        for(int i=0;i<n;++i){
            ll& x = a[i];
            //Decompose it into sums of unique powers of k
            for(int j=biggest;~j;--j){
                if(x - pows[j] >= 0){
                    x -= pows[j];
                    ++cnt;
                    s.insert(j);
                }
            }
            if(x != 0){
                cout << "NO\n";
                goto end_of_loop;
            }
        }
        if(s.size() != cnt){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
        end_of_loop:;
    }
}
