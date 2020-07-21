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

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        bool seen[2*n+1];
        int b[n+1];
        int a[2*n+1];
        memset(a, -1, sizeof(a));
        memset(seen, 0, sizeof(seen));
        for(int i=1;i<=n;++i){
            cin >> b[i];
            a[i*2-1] = b[i];
            if(seen[b[i]]){
                cout << "-1\n";
                goto end_of_loop;
            }
            seen[b[i]] = true;
        }
        for(int i=1;i<=2*n;++i){
            if(seen[i]){
                continue;
            }
            for(int j=1;j<=2*n;++j){
                if(a[j] == -1 && a[j-1] < i){
                    a[j] = i;
                    goto end_of_this_loop;
                }
            }
            cout << "-1\n";
            goto end_of_loop;
            end_of_this_loop:;
        }
        for(int i=1;i<=2*n;++i){
            cout << a[i] << ' ';
        }
        cout << endl;
        end_of_loop:;
    }
}

