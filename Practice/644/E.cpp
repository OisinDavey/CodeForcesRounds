//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            51
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

//Global Variables
char a[MX_N][MX_N];
bool valid[MX_N][MX_N];
int n;

int dx2[2] = {-1, +0};
int dy2[2] = {+0, -1};

bool isvalid(int& x, int& y){
    return(x >=0 && x < n && y >=0 && y < n);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin >> a[i][j];
            }
        }
        memset(valid, 0, sizeof(valid));
        queue<pair<int, int> > Q;
        for(int i=0;i<n;++i){
            if(a[i][n-1] == '1'){
                valid[i][n-1] = 1;
                Q.push(mp(i, n-1));
            }
            if(a[n-1][i] == '1'){
                valid[n-1][i] = 1;
                Q.push(mp(n-1, i));
            }
        }
        while(!Q.empty()){
            pair<int, int> at = Q.front();
            Q.pop();
            for(int i=0;i<2;++i){
                int x = at.fi + dx2[i];
                int y = at.se + dy2[i];
                if(isvalid(x, y)){
                    if(a[x][y] == '1' && valid[x][y] == false){
                        valid[x][y] = true;
                        Q.push(mp(x, y));
                    }
                }
            }
        }
//        for(int i=0;i<n;++i){
//            for(int j=0;j<n;++j){
//                cout << valid[i][j] << ' ';
//            }
//            cout << endl;
//        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(a[i][j] == '1'){
                    if(valid[i][j] == false){
                        cout << "NO\n";
                        goto end_of_loop;
                    }
                }
            }
        }
        cout << "YES\n";
        end_of_loop:;
    }
}
