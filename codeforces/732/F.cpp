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

const ll maxn  = 4e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < int > adj[maxn] , cadj[maxn];
int par[maxn] , sz[maxn];
vector < pii > edge;
set < pii > st , cst;
int h[maxn];
int sub[maxn];

int getpar(int v){
    return((v == par[v])?v:par[v]=getpar(par[v]));
}

void merge(int u ,int v){
    u = getpar(u) , v = getpar(v);
    if(u == v)return;
    if(sz[u] > sz[v])swap(u , v);
    par[u]=v,sz[v]+=sz[u];  
}

void init(){
    for(int i = 0 ; i < maxn ; i ++)
        par[i] = i , sz[i] = 1;
}

void dfs(int v = 1 , int t = 1 , int par = 1){
    h[v] = t;
    sub[v] = t;
    for(auto u : adj[v])if(!h[u] or h[u] > h[v]){
        if(!h[u])
            dfs(u , t+1 , v);
        sub[v] = min(sub[v] , sub[u]);
    }
    for(int u : adj[v])
        if(u!=par)
            sub[v] = min(sub[v] , h[u]);
    if(sub[v] < h[v])
        merge(v , par);
    sub[v] = min(sub[v] , h[par]);
}

void solve(int v , int t = 1){
    h[v]=t;
    for(auto u : adj[v])
        if(getpar(u)!=getpar(v))
            cadj[getpar(u)].pb(getpar(v)),
            cadj[getpar(v)].pb(getpar(u));
        else
            if(!h[u])
                solve(u , t + 1),
                st.insert({v , u});
            else if (h[u] > h[v])
                st.insert({u , v});
}

void direct(int v){
    h[v] = 1;
    for(auto u : cadj[v])
        if(!h[u])
            direct(u),
            cst.insert({u , v});
}

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edge.pb({u , v});
    }
    init();
    dfs();
    ms(h , 0);
    for(int i = 1; i <= n ; i ++)
        if(!h[i])solve(i);
    int mx = getpar(1);
    for(int i = 2; i <= n ; i ++)
        if(sz[mx] < sz[getpar(i)])
            mx = getpar(i);
    cout << sz[mx] << endl;
    ms(h , 0);
    direct(mx);
    for(auto [u , v] : edge)
        if(getpar(u) == getpar(v))
            if(st.count({u , v}))
                cout << u << ' ' << v << endl;
            else
                cout << v << ' ' << u << endl;
        else
            if(cst.count({getpar(u) , getpar(v)}))
                cout << u << ' ' << v << endl;
            else
                cout << v << ' ' << u << endl;
    

    return(0);
}