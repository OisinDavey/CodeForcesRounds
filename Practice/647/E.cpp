//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
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

//Using two pointers
//Containing each number as a set of k values
//when I add a k value, I check if there are p of them, and if so I remove them all and add k+1 in a similar fashion
//
//edge cases:
//  p == 1: 
//      Everything is ones, just take n/2
//  n == 1:
//      just calculate
//
//For final calculation, I will have to do a very large power, so I may use the totient fucntion

int p;

bool bigger(set<int>& A, set<int>& B){


int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n >> p;
        if(n == 1){
            continue;
        }else if(p == 1){
            continue;
        }
        int a[n];
        for(int i=0;i<n;++i){
            cin >> a[i];
        }
        sort(a, a+n);
        int L = 0;
        int R = n-1;
        set<int> A, B;
        A.insert(a[L]);
        B.insert(a[R]);
        while(L < R-1){
            if(bigger(A, B)){
                ++L;
                add(A, a[L]);
            }else{
                --R;
                add(B, a[R]);
            }
        }
        //I want difference between value of A & B mod7
        //This is the same as the difference between A mod7 & B mod7 mod7
        ll ans;
        if(bigger(A, B)){
            ans = ((val(A) + mod7) - val(B)) % mod7;
        }else{
            ans = ((val(B) + mod7) - val(B)) % mod7;
        }
        cout << ans << endl;
    }
}
