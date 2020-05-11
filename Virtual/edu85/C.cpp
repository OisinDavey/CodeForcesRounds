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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        
        ll HD[n][2];

        for(int i=0;i<n;++i) cin >> HD[i][0] >> HD[i][1];

        ll after[n];

        for(int i=1;i<n;++i) after[i] = max(0LL, HD[i][0] - HD[i-1][1]);
        after[0] = max(0LL, HD[0][0] - HD[n-1][1]);

        ll total = 0LL;

        for(int i=0;i<n;++i) total += after[i];

        ll ans = LLONG_MAX - 1;

        for(int i=0;i<n;++i)
            ans = min(ans, HD[i][0] + (total - after[i]));

        cout << ans << endl;
    }
}
