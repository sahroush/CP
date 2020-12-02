//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+10;
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

int h[maxn];

int dist[maxn];

int p[maxn];

int l[maxn] , r[maxn] , t;
int ord[maxn];

void dia(int v = 1, int par = 0){
	p[v] = par;
	r[v] = l[v] = ++t;
	ord[t] = v;
	for(auto u : adj[v]) if(u != par)
		dist[u] = dist[v] + 1 , dia(u , v) , r[v] = r[u];
}

int val[maxn];

void dfs(int v , int par = 0){
	for(auto u : adj[v])if(u!=par)
		h[u] = h[v] + val[u] , dfs(u , v);
}

pii seg[maxn*4];

void build(int v = 1 , int l = 1, int r = n + 1){
	if(r - l == 1){
		seg[v] = {h[ord[l]] , ord[l]};
		return;
	}
	int mid = (l + r)/2;
	build(2*v , l , mid);
	build(2*v + 1,  mid , r);
	seg[v] = max(seg[2*v] , seg[2*v+1]);
}

int lazy[maxn*4];

void shift(int v , int l , int r){
	seg[v].first += lazy[v];
	seg[v].first = max(seg[v].first , 0);
	if(r - l > 1)
		lazy[2*v] += lazy[v] , lazy[2*v + 1] += lazy[v];
	lazy[v] = 0;
}

void update(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] -- ;
		shift(v , l , r);
		return;
	}
	int mid = (l + r)/2;
	update(L , R , 2*v , l , mid);
	update(L , R , 2*v+1 , mid , r);
	seg[v] = max(seg[2*v] , seg[2*v + 1]);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dia();
	int d = 0;
	for(int i = 1 ; i <= n ; i ++)if(dist[i] > dist[d])d = i;
	t = 0;
	dia(d);
	for(int i = 1 ; i <= n ; i ++)val[i] = 1;
	dfs(d);
	int ans = 1;
	val[d] = 0;
	cout << ans << ' ';
	build();
	for(int i = 2 ; i <= n ; i ++){
		auto [h , mx] = seg[1];
		ans += h;
		while(val[mx])
			val[mx] = 0, update(l[mx] , r[mx]+1) , mx = p[mx];
		cout << ans << ' ';
	}
    return(0);
}
