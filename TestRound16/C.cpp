#include<bits/stdc++.h> 
#define MX_N 5001
#define INF 100000000

#define mod7 1000000007

typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}

int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};
int dx4[4] = {0, 0, +1, -1};
int dy4[4] = {+1, -1, 0, 0};

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        set<pair<int,int>> vert;
        set<pair<int,int>> hori;
        int x=0, y=0;
        ll T = 0;
        for(char c : s){
            T += 1;
            if(c=='N'){
                if(vert.find({x, y}) == vert.end())
                    T += 4;
                vert.insert({x, y});
                ++y;
            }else if(c=='S'){
                if(vert.find({x, y-1}) == vert.end())
                    T += 4;
                vert.insert({x, y-1});
                --y;
            }else if(c=='E'){
                if(hori.find({x, y}) == hori.end())
                    T += 4;
                hori.insert({x, y});
                ++x;
            }else{
                if(hori.find({x-1, y}) == hori.end())
                    T += 4;
                hori.insert({x-1, y});
                --x;
            }
        }cout << T << endl;
    }
}
