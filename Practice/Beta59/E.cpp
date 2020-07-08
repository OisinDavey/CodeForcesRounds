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

vector<vector<int> > hex_lines(15);

const long long SPACE = 524288;
bitset<SPACE> dp;

int main(){
    hex_lines[0] = {0, 1, 2};
    hex_lines[1] = {3, 4, 5, 6};
    hex_lines[2] = {7, 8, 9, 10, 11};
    hex_lines[3] = {12, 13, 14, 15};
    hex_lines[4] = {16, 17, 18};
    hex_lines[5] = {7, 3, 0};
    hex_lines[6] = {12, 8, 4, 1};
    hex_lines[7] = {16, 13, 9, 5, 2};
    hex_lines[8] = {17, 14, 10, 6};
    hex_lines[9] = {18, 15, 11};
    hex_lines[10] = {2, 6, 11};
    hex_lines[11] = {1, 5, 10, 15};
    hex_lines[12] = {0, 4, 9, 14, 18};
    hex_lines[13] = {3, 8, 13, 17};
    hex_lines[14] = {7, 12, 16};
    dp.set();
    //  0 : current player wins
    //  1 : other player wins
    for(int pos=0;pos<SPACE;++pos){//For Every Combination
        for(vector<int>& line : hex_lines){
            for(int i=0;i<line.size();++i){
                int change = 0;
                for(int j=i;j<line.size();++j){
                    if((pos & (1 << line[j])) == false){
                        break;
                    }
                    change += (1 << line[j]);
                    if(dp[pos - change] == 1){
                        dp[pos] = 0;
                    }
                }
            }
        }
    }
    int mask = 0;
    for(int i=0;i<19;++i){
        char c;
        cin >> c;
        if(c == 'O'){
            mask += (1 << i);
        }
    }
    if(dp[mask]){
        cout << "Lillebror\n";
    }else{
        cout << "Karlsson\n";
    }
}
