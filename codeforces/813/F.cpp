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

int n, q , cur;
int par[maxn] , bip[maxn] , sz[maxn];
bool ok = 1;
map < pii , int > lst;
vector < pii > seg[maxn<<2];
vector < int > undo[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void add(int L , int R , pii e , int v = 1 , int l = 1 , int r = q + 1){
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		seg[v].pb(e);
		return;
	}
	add(L , R , e , lc , l , mid);
	add(L , R , e , rc , mid , r);
}

pii getpar(int v){
	if(v == par[v])
		return {v , 0};
	auto res = getpar(par[v]);
	res.second ^= bip[v];
	return res;
}

void merge(int u , int v){
	pii pu = getpar(u) , pv = getpar(v);
	if(pu.first == pv.first){
		ok &= (pu.second != pv.second);
		return;
	}
	if(sz[pu.first] > sz[pv.first])swap(pu , pv);
	undo[cur].pb(pu.first);
	bip[pu.first] = pu.second ^ pv.second ^ 1;
	par[pu.first] = pv.first;
	sz[pv.first] += sz[pu.first];
}

void build(int v = 1 , int l = 1 , int r = q + 1){
	cur = v;
	bool state = ok;
	for(auto [u , v] : seg[cur])
		merge(u , v);
	if(r - l == 1)
		cout << ((ok) ? "YES" : "NO") << endl;
	else
		build(lc , l , mid) , build(rc , mid , r);
	ok = state;
	reverse(undo[v].begin() , undo[v].end());
	for(auto u : undo[v])
		sz[par[u]] -= sz[u] , par[u] = u , bip[u] = 0;
}

int32_t main(){
	migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		par[i] = i , sz[i] = 1;
	for(int i = 1 ; i <= q ; i ++){
		int u , v;
		cin >> u >> v;
		if(u > v)swap(u, v);
		if(lst.count({u , v}))
			add(lst[{u , v}] , i , {u , v}) , lst.erase({u , v});
		else
			lst[{u , v}] = i;
	}
	for(auto [f , s] : lst)
		add(s , q + 1 , f);
	build();
	return(0);
}
