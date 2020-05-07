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

struct node{
	int value;
	node* parent;
	int Index;
};

int GlobalIndex = 0;

node* FindGroup(node* at){
	if(at->parent == at)
		return at;
	else
		return at->parent = FindGroup(at->parent);
}

void JoinGroup(node* A, node* B){
	FindGroup(A)->parent = FindGroup(B);
}

int main(){
	int n,m;
	cin >> n >> m;
	node* People[n];
	for(int i=0;i<n;++i){
		People[i] = new node;
		cin >> People[i]->value;
		People[i]->parent = People[i];
		People[i]->Index = i;
	}for(int i=0;i<m;++i){
		int a,b;
		cin >> a >> b;
		--a, --b;
		JoinGroup(People[a], People[b]);
	}map<int, int> M;
	for(int i=0;i<n;++i)
		M[FindGroup(People[i])->Index] = 1000000000;
	for(int i=0;i<n;++i)
		M[FindGroup(People[i])->Index] = min(M[FindGroup(People[i])->Index], People[i]->value);
	ll count = 0;
	for(auto it = M.begin(); it != M.end(); ++it)
		count += it->second;
	cout << count << endl;
}

