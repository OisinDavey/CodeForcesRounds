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

bool can_get(string& a, string& b){
    int it = 0;
    for(int i=0;i<(int)b.size();++i){
        if(b[i] == a[it]){
            ++it;
            if(it == (int)a.size()){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int lo = 0;
    int hi = n-1;
    int p[n];
    int turn[n];
    for(int i=0;i<n;++i){
        cin >> p[i];
        --p[i];
        turn[p[i]] = i;
    }
    while(lo < hi){
        int mid = lo + (hi - lo + 1)/2;
        string tmp = "";
        for(int i=0;i<n;++i){
            if(turn[i] >= mid){
                tmp += a[i];
            }
        }
        if(can_get(b, tmp)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    cout << lo << endl;
}
