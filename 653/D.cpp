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
        int n, k;
        cin >> n >> k;
        multiset<int> s;
        for(int i=0;i<n;++i){
            int x;
            cin >> x;
            x %= k;
            if(x != 0){
                s.insert(k - (x%k));
            }
        }
        int x = 0;
        ll ans = 0;
        while(!s.empty()){
            multiset<int>::iterator it;
            it = s.lower_bound(x);
//            cout << "Set size " << s.size() << endl;
//            cout << "x and the lower bound value " << x << ' ' << (*it) << endl;
            if(it == s.end()){
                //Do the first element
                ans += (k - x);
                x = 0;
            }else{
                ans += ((*it) - x);
                ++ans;
                x = (*it) + 1;
                multiset<int>::iterator pos = s.find((*it));
                s.erase(pos);
                x %= k;
            }
        }
        cout << ans << endl;
    }
}
