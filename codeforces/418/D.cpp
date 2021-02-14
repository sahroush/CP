/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int lg = 20;

int n , q;
vector < int > adj[maxn];

int seg[maxn * 4];
int h[maxn] , st[maxn] , ft[maxn] , ord[maxn] , timee;
int par[lg + 1][maxn];

void dfs(int v = 1 , int p = 0){
	st[v] = ++timee , ord[timee] = v , par[0][v] = p;
	for(auto u : adj[v])if(u^p)
		h[u] = h[v] + 1, dfs(u , v);
	ft[v] = timee;
}

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

int lazy[maxn * 4];

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = h[ord[l]];
		return;
	}
	build(lc , l , mid),
	build(rc , mid , r);
	seg[v] = max(seg[lc] , seg[rc]);
}

int lca(int u , int v){
	if(h[u] < h[v])
		swap(u , v);
	for(int i = lg ; i >= 0 ; i --)
		if(h[par[i][u]] >= h[v])
			u = par[i][u];
	if(u == v)
		return(v);
	for(int i = lg ; i >= 0 ; i --)
		if(par[i][u] ^ par[i][v])
			u = par[i][u] , v = par[i][v];
	return(par[0][v]);
}

int dist(int u , int v){
	return(h[v] + h[u] - 2*h[lca(u , v)]);
}

int getpar(int v , int x){
	for(int i = lg ; i >= 0 ; i --)
		if((1 << i) & x)
			v = par[i][v];
	return(v);
}

int ans[maxn];

struct tr{
	int l , r , ind;
	tr(int a , int b , int c):
		l(a) , r(b) , ind(c){}
};

vector < tr > qu[maxn];

void shift(int v , int l , int r){
	seg[v] += lazy[v];
	if(r - l > 1)
		lazy[lc] += lazy[v] , lazy[rc] += lazy[v];
	lazy[v] = 0;
}

int get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return(0);
	if(L <= l and r <= R)
		return(seg[v]);
	return(max(get(L , R , lc , l , mid) , get(L , R , rc , mid , r)));
}

void add(int L , int R , int x , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if (r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] += x;
		shift(v , l , r);
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc,  mid , r);
	seg[v] = max(seg[lc] , seg[rc]);
}

void add(int v , int d = 1){
	add(1 , n + 1 , 1 * d);
	add(st[v] , ft[v] + 1 , -2 * d);
}

void solve(int v,  int p = 0){
	for(auto q : qu[v])
		ans[q.ind] = max(ans[q.ind] , get(q.l , q.r + 1));
	for(auto u : adj[v])if(u ^ p)
		add(u) , solve(u , v) , add(u , -1);
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
	build();
	for(int j = 1 ; j <= lg ; j ++)
		for(int i = 1 ; i <= n ; i ++)
			par[j][i] = par[j - 1][par[j - 1][i]];
	cin >> q;
	for(int i = 1 ; i <= q ; i ++){
		int a , b , med;
		cin >> a >> b;
		int Lca = lca(a , b);
		if(dist(a , Lca) > dist(b , Lca)){
			med = getpar(a , (dist(a , b)-1) / 2);
			qu[a].pb({st[med] , ft[med] , i});
			qu[b].pb({1 , st[med]-1 , i});
			qu[b].pb({ft[med] + 1 , n , i});
		}
		else{
			med = getpar(b , (dist(a , b)-1) / 2);
			qu[b].pb({st[med] , ft[med] , i});
			qu[a].pb({1 , st[med]-1 , i});
			qu[a].pb({ft[med] + 1 , n , i});
		}
	}
	solve(1);
	for(int i = 1 ; i <= q ; i ++)
		cout << ans[i] << endl;
	return(0);
}
