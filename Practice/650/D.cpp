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

int bucket[26];

char find_char(int needed){
    //cout << "Finding character with at least " << needed << " occurences\n";
    for(int i=25;i>=0;--i){
        if(bucket[i] >= needed){
            bucket[i] = 0;
            return (char)(i + 'a');
        }
        bucket[i] = 0;
    }
    return 0;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        int n;
        cin >> s >> n;
        int characters_placed = 0;
        bool used[n];
        int a[n];
        vector<int> zero_positions;
        memset(used, 0, sizeof(used));
        memset(bucket, 0, sizeof(bucket));

        char ans[n];

        for(int i=0;i<n;++i){
            cin >> a[i];
        }
        for(char c : s){
            ++bucket[c - 'a'];
        }
        for(int i=0;i<n;++i){
            if(a[i] == 0){
                zero_positions.pb(i);
            }
        }

        /*
         * Todo:
         *  find all zeroes and place the highest character we can in that position
         *  update array a to get new zeroes
         */

        while(characters_placed < n){
            char cur_char = find_char(zero_positions.size());
            for(int pos : zero_positions){
                ans[pos] = cur_char;
                used[pos] = true;
                ++characters_placed;
            }
            for(int i=0;i<n;++i){
                if(used[i]){
                    continue;
                }
                for(int pos : zero_positions){
                    a[i] -= abs(pos-i);
                }
            }
            zero_positions = {};
            for(int i=0;i<n;++i){
                if(a[i] == 0 && used[i] == false){
                    zero_positions.pb(i);
                }
            }
        }
        for(char c : ans){
            cout << c;
        }
        cout << endl;
    }
}
