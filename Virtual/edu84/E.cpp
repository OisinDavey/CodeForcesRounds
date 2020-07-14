//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            200001 
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

const long long mod = 998244353;

void modulo(ll& x){
    if(x >= mod){
        x %= mod;
    }
}

ll binpow(ll base, int expo){
    if(expo == 0){
        return 1ll;
    }
    if(expo == 1){
        return base;
    }
    ll tmp = binpow(base, expo/2);
    tmp *= tmp;
    modulo(tmp);
    if(expo % 2 == 1){
        tmp *= base;
        modulo(tmp);
    }
    return tmp;
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        if(i == n){
            cout << "10\n";
        }else{
            ll tmp = binpow(10ll, n-i-1);
            ll tmp2 = 180ll + 81ll*(ll)(n-i-1);
            tmp *= tmp2;
            modulo(tmp);
            cout << tmp << ' ';
        }
    }
//    int blocks[10];
//    memset(blocks, 0, sizeof(blocks));
//    for(int i=0;i<100000;++i){
//        stringstream ss;
//        ss << i;
//        string s;
//        ss >> s;
//        while(s.size() < 5){
//            s = '0' + s;
//        }
//        int last_pos = 0;
//        for(int j=0;j<s.size();++j){
//            if(s[j] != s[last_pos]){
//                blocks[j - last_pos]++;
//                last_pos = j;
//            }
//        }
//        blocks[s.size() - last_pos]++;
//    }
//    for(int i=1;i<=5;++i){
//        cout << blocks[i] << ' ';
//    }
//    cout << endl;
}
