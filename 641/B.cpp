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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;++i) cin >> a[i];
        ll dp[n];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;++i)
            for(int j=i+i;j<=n;j+=i)
                if(a[j-1] > a[i-1])
                    dp[j-1] = max(dp[j-1], dp[i-1] + 1);
        ll maxx = 0;
        for(int i=0;i<n;++i)
            maxx = max(maxx, dp[i]);
        cout << maxx+1 << endl;
    }
}
