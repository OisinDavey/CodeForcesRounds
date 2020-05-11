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

int main(){
    int demo[3][3] = {{5, 4, 8}, {7, 1, 6}, {3, 2, 0} };

    int n;
    cin >> n;
    
    if(n < 3){
        cout << "-1\n";
        return 0;
    }

    int ans[n][n];

    memset(ans, 0, sizeof(ans));

    int counter = 1;

    for(int k=0;k<n-3;++k){
        if((n-k)%2==0){
            for(int i=0;i<n-k;++i){
                ans[i][k] = counter;
                ++counter;
            }
            for(int j=k+1;j<n;++j){
                ans[n-k-1][j] = counter;
                ++counter;
            }
        }else{
            for(int j=n-1;j>k;--j){
                ans[n-k-1][j] = counter;
                ++counter;
            }
            for(int i=n-k-1;i>=0;--i){
                ans[i][k] = counter;
                ++counter;
            }
        }
//        for(int i=0;i<n;++i){
//            for(int j=0;j<n;++j)
//                cout << ans[i][j] << ' ';
//            cout << endl;
//        }
    }
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            ans[i][n-3+j] = demo[i][j]+counter;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}
