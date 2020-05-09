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
        int n;
        cin >> n;
        deque<int> a;
        for(int i=0;i<n;++i){
            int x;
            cin >> x;
            a.push_back(x);
        }int A = 0;
        int B = 0;
        A += a.front();
        a.pop_front();
        ll turn = 1;
        int last = A;
        while(!a.empty()){
            if(turn % 2 == 0){
                int cur = 0;
                while(!a.empty() && cur <= last){
                    cur += a.front();
                    a.pop_front();
                }
                last = cur;
                A += cur;
            }else{
                int cur = 0;
                while(!a.empty() && cur <= last){
                    cur += a.back();
                    a.pop_back();
                }
                last = cur;
                B += cur;
            }
            ++turn;
        }cout << turn << ' ' << A << ' ' << B << endl;
    }
}

