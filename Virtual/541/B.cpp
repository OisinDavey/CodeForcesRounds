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
    int n;
    cin >> n;
    int t=0;
    int a, b, c, d;
    a = 0, b = 0;
    for(int i=0;i<n;++i){
        cin >> c >> d;
//        if(!(a == c && b == d)){
            if(c==d)
                t -= 1;
            t += max(0, 1 + min(c, d) - max(a, b));
            a = c;
            b = d;
//        }
    }cout << t+(c==d) << endl;
}
