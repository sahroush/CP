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

vector < int > adj[maxn];
ll cnt = 0;
int d[maxn];

ll n , x , y;

void dfs(int v = 1, int par = 0){
    d[v]=2;
    for(auto u : adj[v])if(u!=par){
        dfs(u , v);
        if(d[u] and d[v])
            cnt ++ , d[v] -- ;
    }
}

int32_t main(){
    migmig
    cin >> n >> x >> y;
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        d[u] ++ , d[v] ++;
    }
    if(x == y) dokme(y * (n - 1));
    if(x > y and *max_element(d+1 , d + 1 + n) < n-1) dokme(y * (n - 1));
    if(x > y) dokme(y * (n - 2) + x);
    ms(d , 0);
    dfs();
    dokme(x*cnt + y * (n - 1 - cnt));
    return(0);
}