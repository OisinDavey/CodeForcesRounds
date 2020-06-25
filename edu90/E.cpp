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

int sum_of_digits(ll x){
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    int n = s.size();
    int ans = 0;
    for(int i=0;i<n;++i){
        ans += (int)(s[i]-'0');
    }
    return ans;
}

int dp[1000001];

int main(){
    dp[0] = 0;
    for(int i=0;i<1000000;++i){
        dp[i+1] = dp[i] + sum_of_digits(i);
    }
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        if(k == 0){
            int num_nines = n/9;
            int start = n%9;
            if(start != 0){
                cout << start;
            }
            for(int i=0;i<num_nines;++i){
                cout << '9';
            }
            cout << endl;
        }else if(k == 1){
            if(n % 2 == 0){
                if(n < 10){
                    cout << "-1\n";
                }else{
                    int a = (n + 8)/2;
                    a -= 9;
                    if(a < 8){
                        if(a != 0){
                            cout << a;
                        }
                        cout << "9\n";
                    }else{
                        a -= 8;
                        int num_nines = a/9;
                        int start = a % 9;
                        if(start != 0){
                            cout << start;
                        }
                        for(int i=0;i<num_nines;++i){
                            cout << '9';
                        }
                        cout << "89\n";
                    }
                }
            }else{
                int a = (n - 1)/2;
                if(a < 9){
                    cout << a << endl;
                }else{
                    a -= 8;
                    int num_nines = a/9;
                    int start = a % 9;
                    if(start != 0){
                        cout << start;
                    }
                    for(int i=0;i<num_nines;++i){
                        cout << '9';
                    }
                    cout << "8\n";
                }
            }
        }else{
            for(int i=0;i<=700000;++i){
                if(dp[i+k+1] - dp[i] == n){
                    cout << i << endl;
                    break;
                }else if(i == 700000){
                    cout << "-1\n";
                }
            }
        }
    }
}
