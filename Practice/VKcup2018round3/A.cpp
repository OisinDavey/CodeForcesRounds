//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
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

int main(){
    int n, m;
    cin >> n >> m;
    int S, L, v;
    cin >> S >> L >> v;
    int s[S], l[L];
    for(int i=0;i<S;++i){
        cin >> s[i];
    }
    for(int i=0;i<L;++i){
        cin >> l[i];
    }
    int Q;
    cin >> Q;
    while(Q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        swap(x1, y1);
        swap(x2, y2);
        if(y1 == y2){
            cout << abs(x1 - x2) << endl;
            continue;
        }
        int NLL, NLR, NSL, NSR;
        int tmp;
        //Lifts
        tmp = (upper_bound(l, l+L, x1) - l);
        if(tmp == L){
            NLL = l[tmp-1];
            NLR = -1;
        }else if(l[tmp] == x1){
            NLL = NLR = x1;
        }else if(tmp == 0){
            NLL = -1;
            NLR = l[0];
        }else{
            NLL = l[tmp-1];
            NLR = l[tmp];
        }
        //Stairs
        tmp = (upper_bound(s, s+S, x1) - s);
        if(tmp == S){
            NSL = s[tmp-1];
            NSR = -1;
        }else if(s[tmp] == x1){
            NSL = NSR = x1;
        }else if(tmp == 0){
            NSL = -1;
            NSR = s[0];
        }else{
            NSL = s[tmp-1];
            NSR = s[tmp];
        }
        //NLL
        int _nll = 0;
        if(NLL != -1){
            _nll += abs(x1-NLL);
            _nll += abs(NLL-x2);
            _nll += (abs(y1-y2)+v-1)/v;
        }else{
            _nll = 1000000009;
        }
        //NLR
        int _nlr = 0;
        if(NLR != -1){
            _nlr += abs(x1-NLR);
            _nlr += abs(NLR-x2);
            _nlr += (abs(y1-y2)+v-1)/v;
        }else{
            _nlr = 1000000009;
        }
        //NSL
        int _nsl = 0;
        if(NSL != -1){
            _nsl += abs(x1-NSL);
            _nsl += abs(NSL-x2);
            _nsl += abs(y1-y2);
        }else{
            _nsl = 1000000009;
        }
        //NSR
        int _nsr = 0;
        if(NSR != -1){
            _nsr += abs(x1-NSR);
            _nsr += abs(NSR-x2);
            _nsr += abs(y1-y2);
        }else{
            _nsr = 1000000009;
        }
        int ans = 1000000009;
//        cout << "{NLL, NLR, NSL, NSR} = {" << NLL << ", " << NLR << ", " << NSL << ", " << NSR << "}\n";
        ans = min(_nll, ans);
        ans = min(_nlr, ans);
        ans = min(_nsl, ans);
        ans = min(_nsr, ans);
        cout << ans << endl;
    }
}
