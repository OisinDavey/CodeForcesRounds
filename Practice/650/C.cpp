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
    int T;
    cin >> T;
    while(T--){
        int n, k;
        int ans = 0;
        vector<int> lengths;
        int sum = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        int zeroes = 0;
        int ones = 0;
        for(int i=0;i<n;++i){
            if(s[i] == '1'){
                ++ones;
            }else{
                ++zeroes;
            }
        }
        if(ones == 0){
            double L = n;
            ll K = k;
            cout << max(0, (int)ceil(L/(K+1))) << endl;
            goto end_of_loop;
        }else if(zeroes == 0){
            cout << 0 << endl;
            goto end_of_loop;
        }
        for(int i=0;i<n;++i){
            if(s[i] == '0'){
                ++sum;
            }else{
                if(sum != 0){
                    lengths.pb(sum);
                    sum = 0;
                }
            }
        }
        if(sum != 0){
            lengths.pb(sum);
            sum = 0;
        }
        if(lengths.size() == 1){
            if(s[0] == '0' || s[s.size()-1] == '0'){
                cout << lengths[0]/(k+1) << endl;
            }else{
                cout << max(0, (lengths[0]+1)/(k+1) - 1) << endl;
            }
            goto end_of_loop;
        }
        if(s[0] == '0'){
            ans += lengths[0]/(k+1);
        }else{
            ans += max(0, (lengths[0]+1)/(k+1) - 1);
        }
        if(s[s.size()-1] == '0'){
            ans += lengths[lengths.size()-1]/(k+1);
        }else{
            ans += max(0, (lengths[lengths.size()-1]+1)/(k+1) - 1);
        }
        for(int i=1;i<lengths.size()-1;++i){
            ans += max(0, ( (lengths[i]+1)/(k+1) - 1));
        }
        cout << ans << endl;
        end_of_loop:;
    }
}
