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

int a[8001];
int n;

bool isSpec[8001];

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(isSpec, 0, sizeof(isSpec));
        cin >> n;
        for(int i=0;i<n;++i)
            cin >> a[i];
        for(int i=0;i<(n-1);++i){
            int s = a[i];
            for(int j=i+1;s<=n && j<n;++j){
                s += a[j];
                if(s <= n)
                    isSpec[s] = 1;
            }
            if(s <= n)
                isSpec[s] = 1;
        }
        int S = 0;
        for(int i=0;i<n;++i)
            S += (isSpec[a[i]]);
        cout << S << endl;
    }
}
