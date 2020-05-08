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

struct node{
    vector<node* > neighbours;
    int depth;
    int numdesc;
    bool industry;
    int id;
    node* parent;
};

struct comp{
    bool operator()(node* a, node* b){
        return (a->depth - a->numdesc) < (b->depth - b->numdesc);
    }
};

node* G[200001];
bool visited[200001];

int fill(node* at){
    //cout << "Fill\n";

    if(at->id != 1)
        at->depth = at->parent->depth + 1;

    for(node* x : at->neighbours){
        if(x == at->parent)
            continue;
        x->parent = at;
        at->numdesc += (1+fill(x));
    }return at->numdesc;
}

ll sum = 0;

void dfs(node* at, int numtourist ){
    if(at->industry == 0)
        numtourist+=1;
    else
        sum+=numtourist;

    for(node* x : at->neighbours){
        if(x == at->parent)
            continue;
        dfs(x, numtourist);
    }return;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;++i){
        G[i] = new node;
        G[i]->industry = 0;
        G[i]->numdesc = 0;
        G[i]->id = i+1;
    }
    for(int i=1;i<n;++i){
        int u, v;
        cin >> u >> v;
        G[u-1]->neighbours.push_back(G[v-1]);
        G[v-1]->neighbours.push_back(G[u-1]);
    }

    G[0]->depth = 0;
    G[0]->parent = G[0];
    
    fill(G[0]);
//    dfs(G[0]);

    priority_queue<node*, vector<node* >, comp> PQ;

    for(int i=0;i<n;++i)
        PQ.push(G[i]);

//    while(!PQ.empty()){
//        auto x = PQ.top();
//        cout << x->id << ' ';
//        PQ.pop();
//    }

    vector<node* > industries;

    for(int i=0;i<k;++i){
        auto x = PQ.top();
        x->industry = 1;
        industries.push_back(x);
        PQ.pop();
    }

//    for(auto x : industries){
//        node* at = x;
////        cout << at->id << endl;
//        while(at->id != 1){
//            sum += (at->industry == 0);
//            at = at->parent;
//        }sum += (at->industry==0);
//    }

    dfs(G[0], 0);

    cout << sum << endl;
}
