//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define INF             100000000
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

using namespace std;

struct node{
    int L;
    int R;

    bool leaf;

    node* left;
    node* rite;

    ll val;
};

node* build(int L, int R){
    node* x = new node;
    x->val = 0;
    x->L = L;
    x->R = R;
    if(L == R){
        x->leaf = 1;
        x->left = NULL;
        x->rite = NULL;
    }else{
        int M = L + (R - L)/2;
        x->leaf = 0;
        x->left = build(L, M);
        x->rite = build(M+1, R);
    }
    return x;
}

void increment(int pos, node* at){
    if(at->leaf){
        ++at->val;
    }else{
        int M = at->L + (at->R - at->L)/2;
        if(pos <= M)
            increment(pos, at->left);
        else
            increment(pos, at->rite);
        at->val = at->left->val + at->rite->val;
    }
}

void deleteK(int k, node* at){
    if(at->leaf){
        --at->val;
    }else{
        int M = at->left->val;
        if(k <= M)
            deleteK(k, at->left);
        else
            deleteK(k-M, at->rite);
        at->val = at->left->val + at->rite->val;
    }
}

int findnum(node* at){
    if(at->leaf){
        return at->L;
    }else{
        if(at->left->val > 0)
            return findnum(at->left);
        else
            return findnum(at->rite);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    node* root = build(1, n);
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
        increment(a[i], root);
    }
    for(int i=0;i<q;++i){
        int k;
        cin >> k;
        if(k < 0){
            deleteK(abs(k), root);
        }else{
            increment(k, root);
        }
    }
    if(root->val == 0){
        cout << 0 << endl;
    }else{
        cout << findnum(root) << endl;
    }
}
