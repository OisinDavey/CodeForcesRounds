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
    int a[n];
    for(int i=0;i<n;++i)
        cin >> a[i];
    sort(a, a+n);
    int b[n];
    memset(b, 0, sizeof(b));
    int l=0;
    int r=n-1;
    int i=0;
    while(l < r){
        b[l] = a[i];
        b[r] = a[i+1];
        i+=2;
        ++l;
        --r;
    }
    if(l==r){
        b[l]=a[i];
    }
    for(int x : b)
        cout << x << ' ';
    cout << endl;
}
