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

int n, m;

char board[MX_N][MX_N];

bool valid(int& x, int& y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> board[i][j];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j] == 'B'){
                    //Try and surround them !!
                    for(int k=0;k<4;++k){
                        int x = i + dx4[k];
                        int y = j + dy4[k];
                        if(valid(x, y)){
                            if(board[x][y] == '.'){
                                board[x][y] = '#';
                            }
                        }
                    }
                }
            }
        }
        bool can_reach[n][m];
        memset(can_reach, 0, sizeof(can_reach));
        queue<pair<int, int> > Q;
        if(board[n-1][m-1] != '#'){
            Q.push(mp(n-1, m-1));
            can_reach[n-1][m-1] = true;
        }
        while(!Q.empty()){
            pair<int, int> pos = Q.front();
            Q.pop();
            for(int k=0;k<4;++k){
                int x = pos.fi + dx4[k];
                int y = pos.se + dy4[k];
                if(valid(x, y)){
                    if( (board[x][y] != '#') && (can_reach[x][y] == false) ){
                        can_reach[x][y] = true;
                        Q.push(mp(x, y));
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j] == 'G'){
                    if(can_reach[i][j] == false){
                        cout << "No\n";
                        goto end_of_loop;
                    }
                }else if(board[i][j] == 'B'){
                    if(can_reach[i][j] == true){
                        cout << "No\n";
                        goto end_of_loop;
                    }
                }
            }
        }
        cout << "Yes\n";
        end_of_loop:;
    }
}
