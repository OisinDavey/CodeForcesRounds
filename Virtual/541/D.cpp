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

//Node compatable with both UnionFind & Topological Sort
struct node{
    node* parent;
    vector<node*> kids;
    bool vis;
    int rate;
};

vector<node* > G;

node* findset(node* at){
    if(at->parent == at)
        return at;
    else
        return at->parent = findset(at->parent);
}

void unionset(node* a, node* b){
    findset(a)->parent = b;
}

//Topological Sorting
void dfs(node* at){
    if(at->vis)
        return;
    at->vis = 1;
    if(at->kids.size() == 0){
        at->rate = 1;
        return;
    }
    int maxx = 1;
    for(node* to : at->kids){
        dfs(to);
        maxx = max(maxx, to->rate);
    }
    at->rate = maxx+1;
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    
    for(int i=0;i<n;++i){
        node* x = new node;
        x->parent = x;
        x->vis = 0;
        G.push_back(x);
    }for(int i=0;i<m;++i){
        node* x = new node;
        x->parent = x;
        x->vis = 0;
        G.push_back(x);
    }

    char c; 
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> c;
            if(c=='='){
                if(findset(G[i]) != findset(G[n+j]))
                    unionset(G[i], G[n+j]);
                a[i][j] = 0;
            }
            else if(c=='>')
                a[i][j] = 1;
            else
                a[i][j] = -1;
        }
    }
    
    //Add directed edges while checking for disparity amongst equals
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(a[i][j] == 1)
                findset(G[i])->kids.push_back(findset(G[n+j]));
            else if(a[i][j] == -1)
                findset(G[n+j])->kids.push_back(findset(G[i]));

    //TopSort
    for(int i=0;i<G.size();++i)
        dfs(findset(G[i]));

    //Check For Contradictions
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]==0){
                if(findset(G[i])->rate != findset(G[n+j])->rate ){
                    cout << "No\n";
                    return 0;
                }
            }else if(a[i][j] == 1){
                if(findset(G[i])->rate <= findset(G[n+j])->rate ){
                    cout << "No\n";
                    return 0;
                }
            }else{
                if(findset(G[i])->rate >= findset(G[n+j])->rate ){
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }


    cout << "Yes\n";

    for(int i=0;i<n;++i)
        cout << findset(G[i])->rate << ' ';
    cout << endl;
    for(int i=0;i<m;++i)
        cout << findset(G[n+i])->rate << ' ';
    cout << endl;
}
