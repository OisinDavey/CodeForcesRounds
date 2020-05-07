#include<bits/stdc++.h>

//clock_t tStart = clock();
//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

#define MX_N 5001
#define INF 100000000
#define mod7 1000000007
#define LSB(i) ((i) & -(i))
#define ii pair<int,int>
#define biton(N,NUM) (NUM & (1<<N))

typedef long double lf;
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
	ll n, d;
	cin >> n >> d;
	ll P, F;
	ll A;
	for(int i=0;i<n;++i){
		cin >> A;
		
		if(i == 0){
			F = 0;
			P = A;
		}else{
			P += A;
		}
		
		if(P > d){
			cout << -1 << endl;
			return 0;
		}
		
		if(-A > 2*d){
			cout << -1 << endl;
			return 0;
		}

		if(A == 0){
			if(P < 0){
				++F;
				P = 0;
			}
		}else if(-P > d){
			P = -d;
			++F;
		}
	}cout << F << endl;
}
