/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];

ll ans[maxn];
int sub[maxn];

ll mx = 0;

void dfs(int v = 1 , int par = 0){
	sub[v] = 1;
	for(auto u : adj[v])if(u!=par)
 		dfs(u , v) , sub[v] += sub[u], ans[v] += ans[u];
 	ans[v] += sub[v];
}

void solve(int v = 1 , int par = 0){
	mx = max(mx , ans[v]);
	for(auto u : adj[v])if(u!=par){
		ans[v] -= ans[u];
		ans[v] -= sub[v];
		sub[v] -= sub[u];
		ans[v] += sub[v];
		ans[u] -= sub[u];
		sub[u] += sub[v];
		ans[u] += sub[u];
		ans[u] += ans[v];
		solve(u , v);
		ans[u] -= ans[v];
		ans[u] -= sub[u];
		sub[u] -= sub[v];
		ans[u] += sub[u];
		ans[v] -= sub[v];
		sub[v] += sub[u];
		ans[v] += sub[v];
		ans[v] += ans[u];
	} // ah yes kode
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	solve(1);
	cout << mx;
    return(0);
}
