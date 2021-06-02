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

string words[1000001];
bool vowel[1000];

struct word{
    int s_id;
    char last_vowel;
    int vowel_count;
};

vector<word> v[1000001];

struct comp{
    bool operator()(int a, int b){
        return v[a].size() < v[b].size();
    }
};

struct comp2{
    bool operator()(word& a, word& b){
        if(a.last_vowel == b.last_vowel){
            return a.vowel_count > b.vowel_count;
        }else{
            return a.last_vowel > b.last_vowel;
        }
    }
};

int main(){
    memset(vowel, 0, sizeof(vowel));
    vowel['a'] = true;
    vowel['e'] = true;
    vowel['i'] = true;
    vowel['o'] = true;
    vowel['u'] = true;
    int n;
    cin >> n;
    vector<word> dict;
    vector<pair<word, word> > complete_pairs;
    vector<pair<word, word> > incomplete_pairs;
    for(int i=0;i<n;++i){
        cin >> words[i];
        char at = '-';
        int cnt = 0;
        for(char c : words[i]){
            if(vowel[c]){
                at = c;
                ++cnt;
            }
        }
        word tmp;
        tmp.s_id = i;
        tmp.last_vowel = at;
        tmp.vowel_count = cnt;
        dict.pb(tmp);
    }
    sort(dict.begin(), dict.end(), comp2());
    int d_n = dict.size();
    for(int i=0;i<d_n;++i){
        if(i == d_n-1){
            v[dict[i].vowel_count].pb(dict[i]);
        }else if(dict[i].last_vowel == dict[i+1].last_vowel && dict[i].vowel_count == dict[i+1].vowel_count){
            complete_pairs.pb({dict[i], dict[i+1]});
            ++i;
        }else{
            v[dict[i].vowel_count].pb(dict[i]);
        }
    }
    for(int i=1;i<=1000001;++i){
        sort(v[i].begin(), v[i].end(), comp2());
        int v_n = v[i].size();
        for(int j=0;j+1<v_n;j+=2){
            incomplete_pairs.pb({v[i][j], v[i][j+1]});
        }
    }
    vector<string> ans;
    for(int i=0;i<min(incomplete_pairs.size(), complete_pairs.size());++i){
        ans.pb(words[incomplete_pairs[i].fi.s_id] + " " + words[complete_pairs[i].fi.s_id] + "\n");
        ans.pb(words[incomplete_pairs[i].se.s_id] + " " + words[complete_pairs[i].se.s_id] + "\n");
    }
    if(complete_pairs.size() > incomplete_pairs.size()){
        for(int i = incomplete_pairs.size();i+1<complete_pairs.size();i+=2){
            ans.pb(words[complete_pairs[i].fi.s_id] + " " + words[complete_pairs[i+1].fi.s_id] + "\n");
            ans.pb(words[complete_pairs[i].se.s_id] + " " + words[complete_pairs[i+1].se.s_id] + "\n");
        }
    }
    cout << ans.size()/2 << endl;
    for(string s : ans){
        cout << s;
    }
    return 0;
}
