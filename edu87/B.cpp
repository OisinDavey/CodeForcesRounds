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

int main(){
    FastIO;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int in[3];
        in[0] = 0, in[1] = 0, in[2] = 0;
        int l=0;
        int r=0;
        in[s[0]-'1'] = 1;
        int minn = INF;
        while(l < s.size()){
            while(in[0] > 0 && in[1] > 0 && in[2] > 0){
                minn = min(minn, r-l+1);
                in[s[l]-'1']--;
                ++l;
            }while(in[0] == 0 || in[1] == 0 || in[2] == 0){
                if(r < s.size()-1){
                    ++r;
                    in[s[r]-'1']++;
                }else{
                    l = s.size();
                    break;
                }
            }
        }cout << ((minn==INF)?0:minn) << endl;
    }
}

