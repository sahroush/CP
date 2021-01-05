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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
vector < int > adj[maxn];

bool mark[maxn];
bool in[maxn];

void dfs(int v = 1){
	mark[v] = 1;
	bool ok = 1;
	for(auto u : adj[v]){
		if(in[u])ok = 0;
	}
	if(ok)in[v] = 1;
	for(auto u : adj[v])
		if(!mark[u])
			dfs(u);
}

int par[maxn] , sz[maxn];

int getpar(int v){
	return((v == par[v]) ? v : par[v] = getpar(par[v]));
}

void merge(int v , int u){
	if((u = getpar(u)) == (v = getpar(v)))return;
	par[u] = v;
	sz[v] += sz[u];
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			in[i] = 0 , mark[i] = 0 , adj[i].clear();
		for(int i = 0 ; i < m ; i ++){
			int u , v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		for(int i = 1 ; i <= n ; i ++)
			par[i] = i , sz[i] = 1;
		for(int i = 1 ; i <= n ; i ++){
			for(int u : adj[i]){
				if(in[u]!=in[i])
					merge(i , u);
			}
		}
		if(sz[getpar(1)] != n){
			cout << "NO" << endl;
			continue;
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++)
			if(in[i])cnt++;
		cout << "YES" << endl;
		cout << cnt << endl;
		for(int i = 1 ; i <= n ; i ++)
			if(in[i])cout << i << ' ';
		cout << endl;
	}
    return(0);
}
