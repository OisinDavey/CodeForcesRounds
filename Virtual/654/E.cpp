//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            100001 
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

int n, p;
int a[MX_N];

int C(int val){
    //Calculate number of number in a less that or equal to val
    int L = 0;
    int R = n-1;
    while(L < R){
        int M = L + (1 + R - L)/2;
        if(a[M] > val){
            R = M - 1;
        }else{
            L = M;
        }
    }
    return L + 1;
}

bool no_dip(int val){
    int worst = 1e09;
    for(int i=0;i<n;++i){
        worst = min(worst, (C(val + i) - i));
    }
    return (worst > 0);
}

int peak(int val){
    int best = -1;
    for(int i=0;i<n;++i){
        best = max(best, (C(val + i) - i));
    }
    return best;
}

int main(){
    cin >> n >> p;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a, a+n);
    int start;
    int finish;
    {
        int L = a[0];
        int R = 1e09 + 1;
        while(L < R){
            int M = L + (R - L)/2;
            if(no_dip(M)){
                R = M;
            }else{
                L = M + 1;
            }
        }
        start = L;
    }
    {
        int L = 0;
        int R = 1e09 + 1;
        while(L < R){
            int M = L + (1 + R - L)/2;
            if(peak(M) >= p){
                R = M - 1;
            }else{
                L = M;
            }
        }
        finish = L;
    }
    int range = (finish - start + 1);
    if(range <= 0){
        cout << "0\n\n";
    }else{
        cout << range << endl;
        for(int i=start;i<=finish;++i){
            cout << i << ' ';
        }
        cout << endl;
    }
}
