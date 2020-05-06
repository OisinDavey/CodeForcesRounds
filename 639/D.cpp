#include<bits/stdc++.h> 
#define MX_N 5001
#define INF 100000000

#define mod7 1000000007

typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}

int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};
int dx4[4] = {0, 0, +1, -1};
int dy4[4] = {+1, -1, 0, 0};

using namespace std;

bool board[1000][1000];
int n,m;

int Glint = 1;
int colors[1000][1000];

bool CheckBlocks(){///Return 1 if good, 0 if bad
    bool b = 0;
    for(int i=0;i<n;++i){
        b=0;
        for(int j=1;j<m;++j){
            if(board[i][j] && b)
                return 0;
            if(board[i][j-1] && !board[i][j])
                b = 1;
        }
    }
    for(int j=0;j<m;++j){
        b=0;
        for(int i=1;i<n;++i){
            if(board[i][j] && b)
                return 0;
            if(board[i-1][j] && !board[i][j])
                b = 1;
        }
    }
    return 1;
}

void fill(int x, int y, int color){
    if(x<0 || x>=n || y<0 || y>=m)
        return;
    if(colors[x][y] != -1)
        return;
    if(!board[x][y])
        return;
    colors[x][y] = color;
    for(int i=0;i<4;++i)
        fill(x+dx4[i], y+dy4[i], color);
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char x;
            cin >> x;
            board[i][j] = (x=='#');
        }
    }bool check = CheckBlocks();
    if(check == 0){
        cout << "-1\n";
        return 0;
    }bool row[n], coll[m];
    for(int i=0;i<n;++i){
        row[i] = 0;
        for(int j=0;j<m;++j){
            if(board[i][j]){
                row[i] = 1;
            }
        }
    }
    for(int j=0;j<m;++j){
        col[j] = 0;
        for(int i=0;i<n;++i){
            if(board[i][j]){
                col[j] = 1;
            }
        }
    }
    memset(colors, -1, sizeof(colors));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j] && colors[i][j]==-1){
                fill(i, j, Glint);
                ++Glint;
            }
        }
    }
    for(int i=0;i<n;++i){
        if(!row[i]){
            for(int j=0;j<m;++j){

    cout << Glint-1 << endl;
}
