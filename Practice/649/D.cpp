//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            200000 
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

struct node{
    node* parent;

    vector<node*> edges;

    int depth;

    bool visited;

    int id;
};

node* root;
node* G[MX_N];

vector<pair<node*, node*> > cycles;

void find_cycles(node* at){
    //cout << "Find cycles at " << at->id + 1 << endl;
    at->visited = true;
    at->depth = at->parent->depth + 1;
    for(node* edge : at->edges){
        if(edge == at->parent){
            continue;
        }
        if(edge->visited){
            if(edge->depth > at->depth){
                continue;
            }
            cycles.pb(mp(at, edge));
            //cout << "Cycle found from " << at->id + 1 << " to " << edge->id + 1 << endl;
        }else{
            edge->parent = at;
            find_cycles(edge);
        }
    }
    return;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0;i<n;++i){
        G[i] = new node;
        G[i]->visited = false;
        G[i]->id = i;
    }
    root = G[0];
    root->parent = root;
    root->depth = 0;
    for(int i=0;i<m;++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u]->edges.pb(G[v]);
        G[v]->edges.pb(G[u]);
    }
    find_cycles(root);
    if(cycles.size() == 0){
        puts("1");
        vector<node* > odds, evens;
        for(int i=0;i<n;++i){
            if(G[i]->depth % 2 == 0){
                evens.pb(G[i]);
            }else{
                odds.pb(G[i]);
            }
        }
        vector<node* > ans;
        if(odds.size() > evens.size()){
            ans = odds;
        }else{
            ans = evens;
        }
        for(int i=0;i<(k + 1)/2;++i){
            cout << ans[i]->id + 1 << ' ';
        }
        cout << endl;
    }else{
        pair<node*, node*> best_cycle = cycles[0];
        int best_length = (best_cycle.fi->depth - best_cycle.se->depth) + 1;
        for(auto cycle : cycles){
            int length = (cycle.fi->depth - cycle.se->depth) + 1;
            if(length < best_length){
                best_length = length;
                best_cycle = cycle;
            }
        }
        if(best_length <= k){
            puts("2");
            cout << best_length << endl;
            node* cur = best_cycle.fi;
            while(cur != best_cycle.se){
                cout << cur->id + 1 << ' ';
                cur = cur->parent;
            }
            cout << cur->id + 1 << ' ';
            cout << endl;
        }else{
            puts("1");
            bool parity = false;
            node* cur = best_cycle.fi;
            vector<node* > odds, evens;
            vector<node* > ans;
            while(cur != best_cycle.se){
                if(parity){
                    odds.pb(cur);
                }else{
                    evens.pb(cur);
                }
                parity = !parity;
                cur = cur->parent;
            }
            if(odds.size() > evens.size()){
                ans= odds;
            }else{
                ans = evens;
            }
            for(int i=0;i<(k + 1)/2;++i){
                cout << ans[i]->id + 1 << ' ';
            }
            cout << endl;
        }
    }
}
