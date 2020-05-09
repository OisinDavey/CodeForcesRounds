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

int O(int n){
    return 2*n + 1;
}

int E(int n){
    return 2*n + 2;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n<4)
            cout << "-1";
        else if(n%2==0){
            int x = (n-2)/2;
            for(int i=0;i<=x;++i)
                cout << E(i) << ' ';
            cout << O(x-1) << ' ';
            cout << O(x) << ' ';
            for(int i=(x-2);i>=0;--i)
                cout << O(i) << ' ';
        }else{
            int x = (n-1)/2;
            for(int i=0;i<=x;++i)
                cout << O(i) << ' ';
            cout << E(x-2) << ' ';
            cout << E(x-1) << ' ';
            for(int i=(x-3);i>=0;--i)
                cout << E(i) << ' ';
        }cout << endl;
    }
}
