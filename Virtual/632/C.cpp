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

ll tri(int n){
    return (n*n-n)/2;
}

int main(){
    int n;
    cin >> n;

    ll a[n+1];
    ll b[n+1];
    
    a[0] = 0;
    
    for(int i=1;i<=n;++i) cin >> a[i];
    
    b[0] = 0;
    
    for(int i=1;i<=n;++i) b[i] = b[i-1] + a[i];

    set<ll> S;

    S.insert(b[0]);

    ll l=0;
    ll r=0;

    ll R[n];

    while(r<n){
//        cout << l << ' ' << r << endl;
        auto x = S.find(b[r+1]);
        if(x == S.end()){
            ++r;
            S.insert(b[r]);
        }else{
            R[l] = r;
            S.erase(S.find(b[l]));
            ++l;
        }
    }while(l<=n){
//        cout << l << ' ' << r << endl;
        R[l] = r;
        
        ++l;
    }

    ll ans = 0;
    
    for(int i=0;i<n;++i){
//        cout << R[i] << ' ';
        ans += R[i]-i;
    }

    cout << ans << endl;
}
