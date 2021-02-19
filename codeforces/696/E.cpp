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
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , t;
vector < int > adj[maxn];
queue < int > q[maxn];
const ll inf = 1e18; 
ll mn[maxn];

int h[maxn] , head[maxn] , sz[maxn] , par[maxn] , mx[maxn] , ord[maxn];
int st[maxn] , ft[maxn] , tim = 0;

void szdfs(int v){
	sz[v] = 1;
	for(auto u : adj[v])if(u^par[v]){
		par[u] = v , h[u] = h[v] + 1 , szdfs(u);
		sz[v] += sz[u];
		if(sz[u] > sz[mx[v]])mx[v] = u;
	}
}

void hldfs(int v){
	st[v] = ++tim, ord[tim] = v;
	if(mx[v])head[mx[v]] = head[v] , hldfs(mx[v]);
	for(auto u : adj[v])
		if(!head[u])
			head[u] = u , hldfs(u);
	ft[v] = tim;
}

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r)>>1)

pii seg[maxn<<2];
ll lazy[maxn<<2];

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = {mn[ord[l]] , ord[l]};
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = min(seg[lc] , seg[rc]);
}

void shift(int v , int l , int r){
	seg[v].first += lazy[v];
	if(r - l > 1)
		lazy[lc] += lazy[v] , lazy[rc] += lazy[v];
	lazy[v] = 0;
}

pii get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)	
		return(pii(inf , inf));
	if(L <= l and r <= R)
		return(seg[v]);
	return(min(get(L , R , lc , l , mid) , get(L , R , rc , mid , r)));
}

void add(int L , int R , int x , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] = x;
		shift(v , l , r);
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc , mid , r);
	seg[v] = min(seg[lc] , seg[rc]);
}

void nxt(int pos , int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		ll delta = seg[v].first - mn[ord[l]];
		q[ord[l]].pop();
		mn[ord[l]] = ((q[ord[l]].size()) ? q[ord[l]].front() : inf);
		seg[v] = {mn[ord[l]] + delta , ord[l]};
		return;
	}
	shift(lc , l , mid);
	shift(rc , mid , r);
	if(pos < mid)
		nxt(pos , lc , l , mid);
	else
		nxt(pos , rc , mid , r);
	seg[v] = min(seg[lc] , seg[rc]);
}

pii solve(int u , int v){
	pii ans = {inf , inf};
	while(head[u] != head[v]){
		if(h[head[v]] > h[head[u]]) swap(u , v);
		ans = min(ans , get(st[head[u]]  , st[u] + 1));
		u = par[head[u]];
	}
	if(st[v] > st[u])swap(u , v);
	ans = min(ans , get(st[v] , st[u] + 1));
	return(ans);
}

int32_t main(){
	migmig;
	cin >> n >> m >> t;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[v].pb(u) , adj[u].pb(v);
	}
	for(int i = 1 ; i <= m ; i ++){
		int x;
		cin >> x;
		q[x].push(i);
	}
	for(int i = 1 ; i <= n ; i ++){
		mn[i] = ((q[i].size()) ? q[i].front() : inf);
	}
	head[1] = 1 , szdfs(1) , hldfs(1);
	build();
	while(t -- ){
		int tp;
		cin >> tp;
		if(tp == 1){
			int u , v , k;
			cin >> u >> v >> k;
			vector < int > ans;
			while(k --){
				pii res = solve(u , v);
				if(res.first >= inf)break;
				ans.pb(q[res.second].front());
				nxt(st[res.second]);
			}
			cout << ans.size() << ' ';
			for(int x : ans)
				cout << x << ' ';
			cout << endl;
		}
		if(tp == 2){
			int v , k;
			cin >> v >> k;
			add(st[v] , ft[v] + 1 , k);
		}
	}
	return(0);
}
