/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int lim;
vector < int > a;
vector < int > H;

struct node{
	int mn = 1e9 , mx[2] = {(ll)-1e18 , (ll)-1e18} , pref[2] = {(ll)-1e18 , (ll)-1e18} , suff[2] = {(ll)-1e18 , (ll)-1e18} , ans = -1e18;
	node operator+ (const node &r) const{
		node Ans;
		Ans.mn = min(mn , r.mn);
		Ans.mx[0] = max(mx[0] , r.mx[0]);
		Ans.mx[1] = max(mx[1] , r.mx[1]);
		Ans.pref[0] = max({pref[0] , r.pref[0] , mx[0] - 2*r.mn});
		Ans.pref[1] = max({pref[1] , r.pref[1] , mx[1] - 2*r.mn});
		Ans.suff[0] = max({suff[0] , r.suff[0] ,-2*mn + r.mx[0]});
		Ans.suff[1] = max({suff[1 ], r.suff[1] ,-2*mn + r.mx[1]});
		Ans.ans = max({ans , r.ans , pref[0] + r.mx[0] , mx[0] + r.suff[0] , pref[1] + r.mx[1] , mx[1] + r.suff[1]});
		return(Ans);
	}
};

vector < node > seg(maxn*4); //dicaprio
int lazy[maxn*4];

void build(int v = 1 , int l = 1 , int r = 2*n){
	if(r - l == 1){
		seg[v].mn = H[l];
		seg[v].mx[a[l]%2] = H[l];
		seg[v].suff[a[l]%2] = seg[v].pref[a[l]%2] = -H[l];
		seg[v].ans = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(2*v , l , mid);
	build(2*v + 1 , mid , r);
	seg[v] = seg[2*v] + seg[2*v + 1];
}

void shift(int v , int l , int r){
	if(!lazy[v])return;
	swap(seg[v].mx[0] , seg[v].mx[1]);
	swap(seg[v].suff[0] , seg[v].suff[1]);
	swap(seg[v].pref[0] , seg[v].pref[1]);
	if(r - l > 1)
		lazy[2*v] ^= lazy[v] , lazy[2*v + 1] ^= lazy[v];
	lazy[v] = 0;
}	

void update(int L ,int R , int v = 1 , int l = 1,  int r = 2*n){
	shift(v , l , r);
	if(R <= l or r <= L)
		return;
	if(L <= l and r <= R){
		lazy[v] ^= 1;
		shift(v , l , r);
		return;
	}
	int mid = (l + r)/2;
	update(L , R  , 2*v , l , mid);
	update(L , R  , 2*v + 1 , mid , r);
	seg[v] = seg[2*v] + seg[2*v + 1];
}


vector < pii > adj[maxn*2];

vector < pair < int , pii > > e;

int P[maxn*2];

int l [maxn*2] , r[maxn*2] , t = 1;



void dfs(int v = 1 , int par = 0 , int h = 0 , int d = 0){
	H[0] = -1;
	P[v] = par;
	a.pb(h);
	H.pb(d);
	r[v] = l[v] = t++;
	for(auto [u , w] : adj[v])	
		if(u!=par){
			dfs(u , v , h+w , d + 1);
			a.pb(h);
			H.pb(d);
			r[v] = t++;
		}
}

int32_t main(){
    migmig;
	cin >> n ;
	//seg.resize(maxn*4+1000);
	for(int i = 1 ; i < n ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
		e.pb({w , {u , v}});
	}
	a.pb(177013);
	H.pb(-1);
	dfs();
	build();
	cin >> q;
	while(q -- ){
		int p;
		cin >> p;
		auto &ed = e[--p];
		int par = ed.second.second;
		if(P[par]!=ed.second.first)par = ed.second.first;
		update(l[par] , r[par]+1);
		cout << seg[1].ans << endl;
	}
    return(0);
}
