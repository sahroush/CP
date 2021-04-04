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

const int maxn = 5e5 + 10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, m , q , k , cur;
vector < int > occ[maxn];
pii ed[maxn];
int ask[maxn] , col[maxn];
vector < pii > seg[maxn<<2], undo[maxn<<2];
int par[52][maxn] , bip[52][maxn] , sz[52][maxn];
int color[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

int nxt(int v , int x){
	return *upper_bound(occ[v].begin() , occ[v].end() , x);
}

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

pii getpar(int v , int c){
	if(v == par[c][v])
		return {v , 0};
	auto res = getpar(par[c][v] , c);
	res.second ^= bip[c][v];
	return res;
}

bool merge(int u , int v , int c){
	pii pu = getpar(u , c) , pv = getpar(v , c);
	if(pu.first == pv.first)
		return (pu.second != pv.second);
	if(sz[c][pu.first] > sz[c][pv.first])swap(pu , pv);
	undo[cur].pb({pu.first , c});
	bip[c][pu.first] = pu.second ^ pv.second ^ 1;
	par[c][pu.first] = pv.first;
	sz[c][pv.first] += sz[c][pu.first];
	return 1;
}

void build(int v = 1 , int l = 1 , int r = q + 1){
	cur = v;
	for(auto [u , v] : seg[cur])
		merge(ed[u].first , ed[u].second , v);
	if(r - l == 1){
		int res = merge(ed[ask[l]].first , ed[ask[l]].second , col[l]);
		cout << ((res) ? "YES" : "NO") << endl;
		if(res)color[ask[l]] = col[l];
		add(l + 1 , nxt(ask[l] , l) , {ask[l] , color[ask[l]]});
	}
	else
		build(lc , l , mid) , build(rc , mid , r);
	reverse(undo[v].begin() , undo[v].end());
	for(auto [u , c] : undo[v])
		sz[c][par[c][u]] -= sz[c][u] , par[c][u] = u , bip[c][u] = 0;
}

int32_t main(){
	migmig;
	cin >> n >> m >> k >> q;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= k ; j ++)
			par[j][i] = i , sz[j][i] = 1;
	for(int i = 1 ; i <= m ; i ++)
		cin >> ed[i].first >> ed[i].second;
	for(int i = 1 ; i <= q ; i ++)
		cin >> ask[i] >> col[i] , occ[ask[i]].pb(i);
	for(int i = 1 ; i <= m ; i ++)occ[i].pb(q + 1);
	build();
	return(0);
}
