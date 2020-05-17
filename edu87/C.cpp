//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define PI              3.141592653589793238
#define MX_N            5001
#define INF             100000000
#define mod7            1000000007
#define modpi           314159
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

using namespace std;

void minmax(vector<double>& M, double& x, double& y){
    M[0] = max(M[0], y);
    M[1] = max(M[1], x);
    M[2] = min(M[2], y);
    M[3] = min(M[3], x);
}

double solve(double n, double a){
    double x = 0.0;
    double y = 0.0;
    double b = 2*PI/n;
    double e = 0.00000001;
    vector<double> M = {y, x, y, x};
    while(a + e < PI/2){            /*First Quarter*/
        a += b;
        y += sin(a);
        x += cos(a);
        minmax(M, x, y);
    }
    while(a + e < PI){              /*Second Quarter*/
        a += b;
        y += sin(PI - a);
        x -= cos(PI - a);
        minmax(M, x, y);
    }
    while(a + e < 3*PI/2){          /*Third Quarter*/
        a += b;
        y -= sin(a - PI);
        x -= cos(a - PI);
        minmax(M, x, y);
    }    
    while(a + e < 2*PI){            /*Fourth Quarter*/
        a += b;
        y -= sin(2*PI - a);
        x += cos(2*PI - a);
        minmax(M, x, y);
    }   
    return max(M[1] - M[3], M[0] - M[2]);
}

int main(){
    FastIO;
    int t;
    cin >> t;
    while(t--){
        double n;
        cin >> n;
        n *= 2;
        double l = -2*PI/n;
        double r = 0;
        double e = 0.00000001;
        while(r - l > e){
            double m1 = l + (r - l)/3;
            double m2 = r - (r - l)/3;
            double f1 = solve(n, m1);
            double f2 = solve(n, m2);
            if(f1 > f2)
                l = m1;
            else
                r = m2;
        }
        cout << fixed << setprecision(9) << solve(n, l) << endl;
    }
}
