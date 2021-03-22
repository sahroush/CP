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

const int maxn = 6e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll ans = 0;
int q;
ll cnt[maxn][2];
int par[maxn];
map < pii , int > lst;
vector < pii > seg[maxn<<2];
struct tr{
	int u , cnt0 , cnt1 , par;
};
vector < tr > undo[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void add(int L , int R , pii x , int v = 1 , int l = 1 ,int r = q+1){
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		seg[v].pb(x);
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc , mid , r);
}

int getpar(int v){
	return((par[v]) ? getpar(par[v]) : v);
}

void merge(int u , int v , int id){
	if((u = getpar(u)) == (v = getpar(v)))
		return;
	if(cnt[u][0] + cnt[u][1] > cnt[v][0] + cnt[v][1])
		swap(u , v);
	undo[id].pb({u , cnt[u][0] , cnt[u][1] , par[u]});
	par[u] = v;
	ans -= cnt[v][0] * cnt[v][1];
	ans -= cnt[u][0] * cnt[u][1];
	cnt[v][0] += cnt[u][0];
	cnt[v][1] += cnt[u][1];
	ans += cnt[v][0] * cnt[v][1];
	cnt[u][0] = cnt[u][1] = 0;
}

void revert(int v){
	while(undo[v].size()){
		auto x = undo[v].back();
		undo[v].pop_back();
		ans -= cnt[par[x.u]][0] * cnt[par[x.u]][1];
		cnt[par[x.u]][0] -= x.cnt0;
		cnt[par[x.u]][1] -= x.cnt1;
		cnt[x.u][0] = x.cnt0;
		cnt[x.u][1] = x.cnt1;
		ans += cnt[par[x.u]][0] * cnt[par[x.u]][1];
		ans += cnt[x.u][0] * cnt[x.u][1];
		par[x.u] = x.par;
	}
}

void build(int v = 1 , int l = 1 , int r = q + 1){
	for(auto [x , y] : seg[v])
		merge(x , y , v);
	if(r - l == 1)
		cout << ans << ' ';
	else
		build(lc , l , mid), build(rc , mid , r);
	revert(v);
}

int32_t main(){
	migmig;
	cin >> q;
	for(int i = 0 ; i < maxn ; i ++)
		cnt[i][i%2]++;
	for(int i = 1 ; i <= q ; i ++){
		int x , y;
		cin >> x >> y;
		x = x * 2;
		y = y * 2 + 1;
		if(lst.count({x , y}))
			add(lst[{x , y}] , i , {x , y}) , lst.erase({x , y});
		else
			lst[{x , y}] = i;
	}
	for(auto [f , s] : lst)
		add(s , q + 1 , f);
	build();
	return(0);
}
