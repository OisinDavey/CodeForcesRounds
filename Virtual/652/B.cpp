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
        bool s[n];
        for(int i=0;i<n;++i){
            char x;
            cin >> x;
            s[i] = (x == '1');
        }
        vector<bool> v;
        v.pb(s[0]);
        for(int i=1;i<n;++i){
            if(s[i-1] != s[i]){
                v.pb(s[i]);
            }
        }
        if(v.size() == 1){
            for(int i=0;i<n;++i){
                if(s[i]){
                    cout << '1';
                }else{
                    cout << '0';
                }
            }
            cout << endl;
        }else if(v.size() == 2){
            if(s[0] == false){
                for(int i=0;i<n;++i){
                    if(s[i]){
                        cout << '1';
                    }else{
                        cout << '0';
                    }
                }
                cout << endl;
            }else{
                cout << "0\n";
            }
        }else{
            /* 
             * if start is zeroes, keep them all
             * otherwise, remove first & second groups 1-0
             * for every 1-0 pair, keep 1 zero, 
             * if last is ones, keep them all
             */
            int first_one = -1;
            int last_zero = -1;
            for(int i=0;i<n;++i){
                if(s[i]){
                    first_one = i;
                    break;
                }
            }
            for(int i=n-1;i>=0;--i){
                if(s[i] == false){
                    last_zero = i;
                    break;
                }
            }
            for(int i=0;i<first_one;++i){
                cout << s[i];
            }
            cout << '0';
            for(int i=last_zero+1;i<n;++i){
                cout << s[i];
            }
            cout << endl;
        }
    }
}
