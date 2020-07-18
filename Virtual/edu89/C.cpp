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
        int n, m;
        cin >> n >> m;
        bool board[n][m];
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> board[i][j];
            }
        }
        pair<int, int> diff[n + m];
        for(int i=0;i<(n + m - 1);++i){
            diff[i] = mp(0, 0);
            int x_pos = i;
            for(int y_pos=0;y_pos<(n + m - 1);++y_pos){
                if(x_pos < 0 || y_pos < 0 || x_pos >= n || y_pos >= m){
                    --x_pos;
                    continue;
                }
                if(board[x_pos][y_pos]){
                    ++diff[i].fi;
                }else{
                    ++diff[i].se;
                }
                --x_pos;
            }
        }
        //Either choose between making all zeroes or all ones
        int mid = (n + m - 1)/2;
        for(int i=0;i<mid;++i){
            int seyes = diff[i].fi + diff[i].se;
            int ones = diff[i].fi + diff[(n + m - 1) - i - 1].fi;
            int zeroes = diff[i].se + diff[(n + m - 1) - i - 1].se;
            ans += (2*seyes - max(ones, zeroes));
        }
        cout << ans << endl;
    }
}
