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

const int maxn = 5e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , t;
vector < pii > adj[maxn];

struct tr{
	int l , r , ind;
	tr(int a , int b , int c):
		l(a) , r(b) , ind(c){}
};

vector < tr > q[maxn];
ll ans[maxn];

ll seg[maxn<<2] , lazy[maxn<<2] , h[maxn];
int ft[maxn];

void init(int v = 1){
	ft[v] = v;
	for(auto [u , w] : adj[v])
		h[u] = h[v] + w , init(u) , ft[v] = ft[u];
}

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

const ll inf = 1e15;

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = h[l];
		if(adj[l].size())seg[v] = inf;
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = min(seg[lc] , seg[rc]);
}

void shift(int v , int l , int r){
	seg[v] += lazy[v];
	if(r - l > 1)
		lazy[lc] += lazy[v] , lazy[rc] += lazy[v];
	lazy[v] = 0;
}

ll get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(R <= l or r <= L)
		return(inf);
	if(L <= l and r <= R)
		return(seg[v]);
	return(min(get(L , R , lc , l , mid) , get(L , R , rc , mid , r)));
}

void add(int L , int R , int x , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(R <= l or r <= L)
		return;
	if(L <= l and r <= R){
		lazy[v] += x;
		shift(v , l , r);
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc , mid , r);
	seg[v] = min(seg[lc] , seg[rc]);
}

void add(int v , int w){
	add(1 , n + 1 , w);
	add(v , ft[v] + 1 , -2*w);
}

void solve(int v = 1){
	for(auto qu : q[v])
		ans[qu.ind] = get(qu.l , qu.r + 1);
	for(auto [u , w] : adj[v])
		add(u , w) , solve(u) , add(u , -w);
}

int32_t main(){
	migmig;
	cin >> n >> t;
	for(int i = 2 ; i <= n ; i ++){
		int p , w;
		cin >> p >> w;
		adj[p].pb({i , w});
	}
	for(int i = 1 ; i <= n ; i ++)
		sort(adj[i].begin() , adj[i].end());
	for(int i = 1 ; i <= t ; i ++){
		int l , r , v;
		cin >> v >> l >> r;
		q[v].pb({l , r , i});
	}
	init();
	build();
	solve();
	for(int i = 1 ; i <= t ; i ++)
		cout << ans[i] << endl;
	return(0);
}
