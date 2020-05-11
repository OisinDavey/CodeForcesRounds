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
        pair<int, int> prev = {0, 0};
        pair<int, int> cur;
        bool b = 1;
        for(int i=0;i<n;++i){
            cin >> cur.first >> cur.second;
            int A = cur.first - prev.first;
            int B = cur.second - prev.second;
            if(B > A)
                b = 0;
            if(B < 0 || A < 0)
                b = 0;
            prev = cur;
        }if(b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
