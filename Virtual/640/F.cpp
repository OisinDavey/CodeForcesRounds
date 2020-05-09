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
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0){
            cout << 1;
            for(int i=0;i<c;++i)
                cout << 1;
        }else if(b == 0 && c == 0){
            cout << 0;
            for(int i=0;i<a;++i)
                cout << 0;
        }else{
            cout << 0;
            for(int i=0;i<a;++i)
                cout << 0;
            if(b % 2 == 0)
                for(int i=0;i<(b-1);++i)
                    cout << !(i%2);
            else
                for(int i=0;i<b;++i)
                    cout << !(i%2);
            for(int i=0;i<c;++i)
                cout << 1;
            if(b%2 == 0)
                cout << 0;
        }cout << endl;
    }
}
