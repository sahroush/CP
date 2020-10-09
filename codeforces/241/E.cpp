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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < int > adj[maxn] , radj[maxn];
vector < pii > e;
int n , m ;
int dist[maxn];
int mark[maxn];

void dfs(int v){
    mark[v] = 1;
    for(auto u : adj[v])if(!mark[u])dfs(u);
}

void sfd(int v){
    mark[v]|=2;
    for(auto u : radj[v])if(mark[u]<2)sfd(u);
}

bool relax(int u , int v){
    if(mark[u]!=3 or mark[v]!=3)return(0);
    if(dist[u] == dist[n+1]) return(0);
    bool ok = 0;
    if(dist[v] > dist[u] + 2) dist[v] = dist[u] + 2 , ok = 1;
    if(dist[u] > dist[v] - 1 ) dist[u] = dist[v] - 1 , ok = 1;
    return(ok);
}

int32_t main(){
    migmig
    cin >> n >> m;
    ms(dist , 63);
    dist[1] = 0;
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
        e.pb({u , v});
    }
    dfs(1);
    sfd(n);
    bool ok;
    for(int i = 0 ; i < n ; i ++){
        ok = 0;
        for(auto [u , v] : e){
            ok |= relax(u , v);
        }
    }
    if(ok) dokme("No");
    cout << "Yes" << endl;
    for(auto [u , v] : e)
        if(mark[u]!=3 or mark[v]!=3) cout << 2 << endl;
        else cout << dist[v] - dist[u] << endl;
    return(0);
}