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

bool sieve[2000000];

vector<ll> primes;

void fill_sieve(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int i=2;i<2000000;++i)
        if(!sieve[i])
            for(int j=i+i;j<2000000;j+=i)
                sieve[j] = 1;
    for(int i=2;i<2000000;++i)
        if(!sieve[i])
            primes.push_back((ll)i);
    return;
}

ll f(ll n){
    for(int i=0;i<primes.size();++i)
        if(n%primes[i]==0)
            return primes[i];
    return -1;
}

int main(){
    fill_sieve();
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(n%2==0){
            cout << n + 2*k << endl;
        }else{
            cout << n + f(n) + 2*(k-1) << endl;
        }
    }
}
