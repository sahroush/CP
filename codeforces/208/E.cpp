/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn] , layer[maxn];
int par[maxn][30];
int l[maxn] , r[maxn] , t = 1;
int h[maxn];
int q;

int gpar(int u , int x){
    for(int i = 20 ; i >= 0 ; i --)
        if(x&(1 << i))
            u = par[u][i];
    return(u);
}

void dfs(int v){
    l[v] = r[v] = t ++;
    layer[h[v]].pb(l[v]);
    for(auto u : adj[v])
        h[u] = h[v] + 1 , dfs(u) , r[v] = r[u];
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1; i <= n ; i ++)
        cin >> par[i][0] , adj[par[i][0]].pb(i);
    for(int i = 1 ; i < 20 ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            par[j][i] = par[par[j][i - 1]][i - 1];
    for(int i = 1 ;  i <= n ; i ++)
        if(!l[i])
            dfs(i);
    cin >> q;
    while(q -- ){
        int v , p;
        cin >> v >> p;
        v = gpar(v , p);
        if(v == 0){cout << 0 << ' ';continue;}
        auto &cur = layer[h[v] + p];
        cout << (upper_bound(cur.begin() , cur.end() , r[v]) - 1 - lower_bound(cur.begin() , cur.end() , l[v]))<< ' ' ; 
    }
    return(0);
}