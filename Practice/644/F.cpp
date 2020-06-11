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

string alph = "abcdefghijklmnopqrstuvwxyz";

int difference(string& a, string& b){
    int ans = 0;
    for(int i=0;i<a.size();++i){
        if(a[i] != b[i]){
            ++ans;
        }
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<string> words(n);
        for(int i=0;i<n;++i){
            cin >> words[i];
        }
        string candidate;
        for(int i=0;i<m;++i){
            for(int j=0;j<26;++j){
                candidate = words[0];
                candidate[i] = alph[j];
                for(int k=0;k<n;++k){
                    int diff = difference(candidate, words[k]);
                    if(diff > 1){
                        break;
                    }
                    if(k == n-1){
                        cout << candidate << endl;
                        goto end_of_loop;
                    }
                }
            }
        }
        cout << "-1\n";
        end_of_loop:;
    }
}
