/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5010;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < pii > adj[maxn];

int par[maxn];

void hentai(int v = 1){
	for(auto [u , w] : adj[v])if(u!=par[v])
		par[u] = v , hentai(u);
}	

int sz[maxn];
bool mark[maxn];
int p[maxn];

void dfs(int v){
	sz[v] = 1;
	for(auto [u , w] : adj[v])	
		if(!sz[u])
			p[u] = v , dfs(u) , sz[v] += sz[u];
}	

int sum(int v , int n){
	int ans = 0;
	mark[v] = 1;
	for(auto [u , w] : adj[v])if(!mark[u])
		ans+= w * sz[u] * (n - sz[u]) , ans += sum(u , n);
	return(ans);
}

int cen(int v, int n , bool found = 0){
	while(!found){
		found = 1;
		for(auto [u , w] : adj[v])if(found and !mark[u] and sz[u] * 2 > n)
			mark[v] = 1 , v = u , found = 0;
	}
	return(v);
}

int s[maxn];

int dist(int v , int block , int n , int p = 0){
	int ans = 0;
	s[v] = 1;
	for(auto [u , w] : adj[v])if(u!=block and u!=p)
		ans += dist(u , block , n , v) , s[v] += s[u] , ans += w * s[u];
	return(ans);
}

int solve(int u , int v){
	ms(sz, 0);
	ms(p , 0);
	ms(s , 0);
	sz[u] = sz[v] = 1;
	dfs(u) , dfs(v);
	ms(mark , 0);
	mark[u] = mark[v] = 1;
	int ans = sum(u , sz[u]) + sum(v , sz[v]);
	int w;
	for(auto [U , W] : adj[v])if(U == u)w = W;
	ans += w * sz[u] * sz[v];
	ms(mark , 0);
	mark[u] = mark[v] = 1;
	ans+=dist(cen(v , sz[v]) , u , sz[v]) * sz[u];
	ans+=dist(cen(u , sz[u]) , v , sz[u]) * sz[v];
	return(ans);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	hentai();
	int ans = 1e18;
	for(int i = 2 ; i <= n ; i ++)
		ans = min(ans , solve(i , par[i]));
	cout << ans;
    return(0);
}
