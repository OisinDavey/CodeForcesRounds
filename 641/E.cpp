//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            1001
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

bool Grid[MX_N][MX_N];
bool GB[MX_N][MX_N];
int F[MX_N][MX_N];

int n, m;

bool inRange(pair<int, int> at){
    return (at.fi >= 0 && at.fi < n && at.se >= 0 && at.se < m);
}

void Fill_F(){
    memset(F, -1, sizeof(F) );
    queue<pair<int, int> > Q;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(GB[i][j]){
                Q.push({i, j});
                F[i][j] = 0;
            }
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int i=0;i<4;++i){
            auto at = cur;
            at.fi += dx4[i];
            at.se += dy4[i];
            if(!inRange(at))
                continue;
            if(F[at.fi][at.se] == -1)
                F[at.fi][at.se] = F[cur.fi][cur.se]+1;
            else if(F[at.fi][at.se] > F[cur.fi][cur.se]+1)
                F[at.fi][at.se] = F[cur.fi][cur.se]+1;
            else
                continue;
            Q.push(at);
        }
    }
}

void Fill_GB(){
    memset(GB, 0, sizeof(GB) );
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i<n-1)
                if(Grid[i+1][j] == Grid[i][j])
                    GB[i][j] = 1;
            if(i>0)
                if(Grid[i-1][j] == Grid[i][j])
                    GB[i][j] = 1;
            if(j<m-1)
                if(Grid[i][j+1] == Grid[i][j])
                    GB[i][j] = 1;
            if(j>0)
                if(Grid[i][j-1] == Grid[i][j])
                    GB[i][j] = 1;
        }
    }
}

int main(){
    int Q;
    cin >> n >> m >> Q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char x;
            cin >> x;
            Grid[i][j] = (x=='0')?0:1;
        }
    }

    Fill_GB();

    Fill_F();

    for(int i=0;i<Q;++i){
        int x, y;
        ll P;
        cin >> x >> y >> P;
        --x;
        --y;
        if(F[x][y] == -1)
            cout << Grid[x][y] << endl;
        else{
            if(P < F[x][y]){
                cout << Grid[x][y] << endl;
            }else{
                P -= F[x][y]%2;
                P = P%2;
                if(!P)
                    cout << Grid[x][y] << endl;
                else
                    cout << !Grid[x][y] << endl;
            }
        }
    }
}
