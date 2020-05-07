#include<bits/stdc++.h>

clock_t tStart = clock();
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
	int t;
	cin >> t;
	bool players[3] = {1, 1, 0};
	for(int i=0;i<t;++i){
		int a;
		cin >> a;
		if(!players[a-1]){
			cout << "NO\n";
			return 0;
		}else{
			if(a==1)
				swap(players[1], players[2]);
			else if(a==2)
				swap(players[0], players[2]);
			else
				swap(players[0], players[1]);
		}	
	}cout << "YES\n";
}
