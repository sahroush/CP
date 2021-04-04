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

const int maxn = 2e5 + 10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , cnt = 0 , lst = 0 , cur;
map < pii , int > mp;
int par[maxn] , sz[maxn];
vector < int > occ[maxn<<1];
pii ed[maxn << 1] , opt[maxn];
vector < int > seg[maxn<<2] , undo[maxn<<2];
bool on[maxn<<1];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

int nxt(int v , int x){
	return *upper_bound(occ[v].begin() , occ[v].end() , x);
}

struct query{
	int t , u , v;
}q[maxn];

void ins(int u , int v , int ind){
	if(mp.count({u , v}) == 0)
		mp[{u , v}] = mp[{v , u}] = ++cnt , ed[cnt] = {u , v};
	occ[mp[{u , v}]].pb(ind);
}

int getpar(int v){
	return((v == par[v]) ? v : getpar(par[v]));
}

void merge(int u , int v){
	if((u = getpar(u)) == (v = getpar(v)))
		return;
	if(sz[u] > sz[v])swap(u , v);
	undo[cur].pb(u);
	par[u] = v;
	sz[v] += sz[u];
}

void add(int L , int R , int e , int v = 1 , int l = 1 , int r = m + 1){
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		seg[v].pb(e);
		return;
	}
	add(L , R , e , lc , l , mid);
	add(L , R , e , rc , mid , r);
}

void build(int v = 1 , int l = 1 , int r = m + 1){
	cur = v;
	for(auto x : seg[v])
		merge(ed[x].first , ed[x].second);
	if(r - l == 1){
		if(q[l].t == 1){
			if(ed[opt[l].first] == pii((q[l].u + lst - 1)% n + 1, (q[l].v + lst - 1)% n + 1) or
			   ed[opt[l].first] == pii((q[l].v + lst - 1)% n + 1, (q[l].u + lst - 1)% n + 1))on[opt[l].first]^=1;
			else on[opt[l].second]^=1;
			if(on[opt[l].first])add(l + 1 , nxt(opt[l].first , l) , opt[l].first);
			if(on[opt[l].second])add(l + 1 , nxt(opt[l].second , l) , opt[l].second);
		}
		else
			cout << (lst = (getpar((q[l].u + lst - 1)% n + 1) == getpar((q[l].v + lst - 1)% n + 1)));
	}
	else
		build(lc , l , mid) , build(rc , mid , r);
	reverse(undo[v].begin() , undo[v].end());
	for(auto u : undo[v])
		sz[par[u]] -= sz[u], par[u] = u;
}

int32_t main(){
	migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		par[i] = i , sz[i] = 1;
	for(int i = 1 ; i <= m ; i ++){
		cin >> q[i].t >> q[i].u >> q[i].v;
		if(q[i].t == 1)
			ins((q[i].u + 0 - 1)% n + 1 , (q[i].v + 0 - 1)% n + 1 , i),
			ins((q[i].u + 1 - 1)% n + 1 , (q[i].v + 1 - 1)% n + 1 , i),
			opt[i] = {mp[{(q[i].u + 1 - 1)% n + 1 , (q[i].v + 1 - 1)% n + 1}] , mp[{(q[i].u + 0 - 1)% n + 1 , (q[i].v + 0 - 1)% n + 1}]};
	}
	for(int i = 1 ; i <= cnt ; i ++) occ[i].pb(m + 1);
	build();
	return(0);
}
