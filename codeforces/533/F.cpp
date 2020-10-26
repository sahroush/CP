/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
string s , t;

ll val = 0;
ll lst[30];
ll base = 69;
vector < int > ans;
ll a[maxn];
ll p[maxn];

string kire = "";
string khar = "";

deque < int > pos[30];

void shift(){
    string boz = "";
    for(int i = 1 ; i < (int)khar.size() ; i ++)
        boz = khar[i] + boz;
    boz += khar[0];
    khar = boz;
}

set < pii > st; 

void add(){
    st.clear();
    for(int i = 0 ; i < 26 ; i ++){
        if(pos[i].size()){
            st.insert({pos[i].front() , i });
        }
        
    }
    khar = "";
    for(auto [a , b] : st){
        khar += char(b + 'a');
    }
}

void del(){
    string boz = "";
    for(int i = 1 ; i < (int)khar.size() ; i ++)
        boz = khar[i] + boz;
    khar = boz;
}

int mat[30];
vector < int > adj[30];

bool chk(){
    ms(mat , 0);
    int n = kire.size();
    //cout << khar << ' ';
    //assert(n == khar.size());
    for(int i = 0 ; i < 30 ; i  ++)
        adj[i].clear();
    for(int i = 0 ; i < n ; i ++){
        adj[kire[i] - 'a'].pb(khar[i] - 'a');
        adj[khar[i] - 'a'].pb(kire[i] - 'a');
    }
    for(int i = 0 ; i < 30 ; i ++){
        sort(adj[i].begin() , adj[i].end());
        adj[i].resize(unique(adj[i].begin() , adj[i].end()) - adj[i].begin());
    }
    int mx = 0;
    for(int i = 0 ; i < 30 ; i ++)
        mx = max ( mx , (int)adj[i].size());
    return(mx <= 1);
}

int32_t main(){
    migmig;
    cin >> n >> m;
    cin >> s >> t;
    t = "d" + t;
    s = "s" + s;
    for(int i = 1 ; i <= m ; i ++){
        int ch = t[i] - 'a';
        val = (val * base)%mod;
        if(lst[ch] == 0)
            lst[ch] = i,
            val = (val +  85)%mod , kire += t[i];
        else
            val = (val + i - lst[ch])%mod;
        lst[ch] = i;
    }
    ms(lst , 0);
    for(int i = 1 ; i <= n ; i ++){
        int ch = s[i] - 'a';
        if(lst[ch] == 0)
            a[i] = 85;
        else if(lst[ch] <= i - m)
            a[i] = 85;
        else
            a[i] = i - lst[ch];
        lst[ch] = i;
    }
    ll h = 0;
    p[0] = 1;
    for(int i = 1 ; i < maxn ; i ++)
        p[i] = (p[i - 1] * base)%mod;
    for(int i = 1 ; i <= n ; i ++){
        bool tof = 0;
        h = (h * base)%mod;
        h = (h + a[i])%mod;
        if(i > m){
            h = (h - (a[i - m] * p[m])%mod)%mod;
            h += mod;
            h %= mod;
            int ch = s[i - m] - 'a';
            pos[ch].pop_front();
            if(pos[ch].size()){
                tof = 1;
                int x = pos[ch].front();
                h = (h - (a[x] * p[i - x])%mod)%mod;
                h = (h + mod)%mod;
                a[x] = 85;
                h = (h + (a[x] * p[i - x])%mod)%mod;
            }
           
        }
        if(a[i] == 85 and !tof)
            khar += s[i];
        int ch = s[i] - 'a';
        pos[ch].pb(i);
        add();
        if(h == val){
            if(chk())ans.pb(i - m + 1);
        }
        
    }
    cout << ans.size() << endl;
    for(int i : ans)
        cout << i << ' ';
    return(0);
}