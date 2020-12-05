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

int n , m;
vector < int > adj[maxn];

int up[maxn];
int h[maxn];
int par[maxn];
int root;

void dfs(int v){
	root = v;
	h[v] = h[par[v]] + 1;
	for(auto u : adj[v]){
		if(!h[u])	
			par[u] = v , dfs(u) , up[v] = min(up[v] , up[u]);
		if(u!=par[v])up[v] = min(up[v] , h[u]);
	}
}

int p[maxn];

int getpar(int v){
	return((p[v] == v)? v : p[v] = getpar(p[v]));
}

int cnt = 0;

void merge(int v , int u){
	v = getpar(v) , u = getpar(u);
	if(u == v)return;
	p[v] = u;
}

vector < int > dick;

void Dfs(int v , int par = 0){
	int d = 0;
	for(auto u : adj[v]){
		if(u!=par)
			Dfs(u , v) , d++;
	}
	if(par)d++;
	if(d <= 1){
		cnt++;
		dick.pb(v);
	}
}

int32_t main(){
    migmig;
	cin >> n >> m;
	if(n==2)dokme(-1);
	for(int i = 1 ; i <= m ; i ++ ){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v) , adj[v].pb(u);
	}
	for(int i = 1 ; i <= n ; i ++) up[i] = 1e9;
	dfs(1);
	for(int i = 1 ; i <= n ; i ++)adj[i].clear() , p[i] = i;
	for(int i = 2 ; i <= n ; i ++){
		if(up[i] > h[par[i]])
			continue;
		else
			merge(i , par[i]);
	}
	for(int i = 2; i <= n ; i ++)
		if(getpar(i)!=getpar(par[i]))
			adj[getpar(i)].pb(getpar(par[i])),
			adj[getpar(par[i])].pb(getpar(i));
	Dfs(getpar(root));
	if(cnt == 1)cnt = 0;
	cout << (cnt+1)/2 << endl;
	if(dick.size() <= 1)return(0);
	int kir = 0;
	if(cnt%2){
		int u = dick[0];
		kir++;
		u = getpar(u);
		int v = dick[1];
		if(v == par[u]){
			for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(v) and i!=par[u]) v = i;
			if(v == par[u]){
				for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(u) and v!=par[i]) u = i;
			}
		}
		if(u == par[v]){
			for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(u) and i!=par[v]) u = i;
			if(u == par[v]){
				for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(v) and u!=par[i]) v = i;
			}
		}
		cout << u << ' ' << v << endl;
		//dick.pop_back();
		cnt--;
	}
	//return(0);
	for(int i = 0 ; i < cnt/2 ; i ++){
		int u = dick[kir+i];
		//u = getpar(u);
		int v = dick[kir+i+cnt/2];
		if(v == par[u]){
			for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(v) and i!=par[u]) v = i;
			if(v == par[u]){
				for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(u) and v!=par[i]) u = i;
			}
		}
		if(u == par[v]){
			for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(u) and i!=par[v]) u = i;
			if(u == par[v]){
				for(int i = 1 ; i <= n ; i ++)
				if(getpar(i) == getpar(v) and u!=par[i]) v = i;
			}
		}
		cout << u << ' ' << v << endl;
	}
    return(0);
}
