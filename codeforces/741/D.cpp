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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 5e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int ans[maxn];
vector < pii > adj[maxn];

int sz[maxn] , h[maxn] , mask[maxn] , mx[maxn];

void dfs(int v = 1){
	sz[v] = 1;
	for(auto [u , w] : adj[v])
		h[u] = h[v] + 1 , mask[u] = mask[v] ^ (1 << w) ,
		 dfs(u) , sz[v] += sz[u],
		 mx[v] = ((sz[u] > sz[mx[v]]) ? u : mx[v]);
}

vector < int > sub;

int a[maxn];

void add(int v , bool f = 0){
	sub.pb(v);
	if(f)a[mask[v]] = -1e9;
	for(auto [u , w] : adj[v])
		add(u , f);
}

void update(int v , int par){
	int res = 0;
	res = max(res , a[mask[v]] + h[v]);
	for(int i = 0 ; i < 22 ; i ++){
		res = max(res , a[mask[v] ^ (1 << i)] + h[v]);
	}
	ans[par] = max(ans[par] , res - 2 * h[par]);
}

void solve(int v = 1){
	for(auto [u , w] : adj[v]){
		if(u == mx[v])continue;
		solve(u);
		ans[v] = max(ans[v] , ans[u]);
		sub.clear();
		add(u , 1);
	}
	if(mx[v])
		solve(mx[v]);
	ans[v] = max(ans[v] , ans[mx[v]]);
	for(auto [u , w] : adj[v]){
		if(u == mx[v])continue;
		sub.clear();
		add(u);
		for(auto x : sub)
			update(x , v);
		for(auto x : sub)
			a[mask[x]] = max(a[mask[x]] , h[x]);
	}
	update(v , v);
	a[mask[v]] = max(a[mask[v]] , h[v]);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < maxn ; i ++)a[i] = -1e9;
	for(int i = 2 ; i <= n ; i ++){
		int p ;
		char c;
		cin >> p >> c;
		adj[p].pb({i , c-'a'});
	}
	dfs();
	solve();
	for(int i = 1 ; i <= n ; i ++)
		cout << ans[i] << ' ';
    return(0);
}
