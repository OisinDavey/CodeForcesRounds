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

bool valid(string s){
    int dd, mm, yyyy;
    char ph;
    int dash_count = 0;
    for(char c : s){
        dash_count += (c == '-');
    }
    if(dash_count != 2 || s[2] != '-' || s[5] != '-'){
        return false;
    }
    stringstream ss;
    ss << s;
    ss >> dd >> ph >> mm >> ph >> yyyy;
    if(!(2013 <= yyyy && yyyy <= 2015)){
        return false;
    }
    vector<int> dz = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mm > 12 || mm == 0 || dd == 0){
        return false;
    }
    if(dd > dz[mm]){
        return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    map<string, int> m;
    int n = s.size();
    for(int i=0;i+9<n;++i){
        string tmp = s.substr(i, 10);
        if(valid(tmp)){
            ++m[tmp];
        }
    }
    int most = 0;
    for(auto i=m.begin();i!=m.end();++i){
        most = max(most, i->second);
    }
    for(auto i=m.begin();i!=m.end();++i){
        if(i->second == most){
            cout << i->first << endl;
        }
    }
}
