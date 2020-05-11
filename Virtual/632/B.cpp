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
        int b[n];

        for(int i=0;i<n;++i) cin >> a[i];
        for(int i=0;i<n;++i) cin >> b[i];

        bool minus[n];
        bool plus[n];

        memset(minus, 0, sizeof(minus));
        memset(plus, 0, sizeof(plus));

        if(a[0] == -1){
            minus[0] = 1;
            plus[0] = 0;
        }else if(a[0] == 1){
            minus[0] = 0;
            plus[0] = 1;
        }

        for(int i=1;i<n;++i){
            if(a[i] == -1)
                minus[i] = 1;
            if(minus[i-1])
                minus[i] = 1;
            if(a[i] == 1)
                plus[i] = 1;
            if(plus[i-1])
                plus[i] = 1;
        }
        
        bool B = 1;

        for(int i=n-1;i>0;i--){
            if(a[i] > b[i])
                if(!minus[i-1])
                    B = 0;
            if(a[i] < b[i])
                if(!plus[i-1])
                    B = 0;
        }

        if(a[0] != b[0])
            B = 0;

        if(B)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
