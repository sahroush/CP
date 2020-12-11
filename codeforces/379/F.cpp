//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+100000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int qu[maxn];
vector < int > a;

struct node{
	int mn = 1e9 , mx = -1e9 , pref = -1e9 , suff = -1e9 , ans = -1e9;
	node operator+ (const node &r) const{
		node Ans;
		Ans.mn = min(mn , r.mn);
		Ans.mx = max(mx , r.mx);
		Ans.pref = max({pref , r.pref , mx - 2*r.mn});
		Ans.suff = max({suff , r.suff ,-2*mn + r.mx});
		Ans.ans = max({ans , r.ans , pref + r.mx , mx + r.suff});
		return(Ans);
	}
};

vector < node > seg; //dicaprio
int lazy[maxn*4];

void build(int v = 1 , int l = 1 , int r = n*2){
	if(r - l == 1){
		seg[v].mx  = seg[v].mn = a[l];
		seg[v].suff = seg[v].pref = -seg[v].mx;
		seg[v].ans = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(2*v , l , mid);
	build(2*v + 1 , mid , r);
	seg[v] = seg[2*v] + seg[2*v + 1];
}

void shift(int v , int l , int r){
	seg[v].mn += lazy[v] , seg[v].mx += lazy[v];
	seg[v].pref-=lazy[v] , seg[v].suff-=lazy[v];
	if(r - l > 1)
		lazy[2*v] += lazy[v] , lazy[2*v + 1] += lazy[v];
	lazy[v] = 0;
}	

void update(int L ,int R , int val , int v = 1 , int l = 1,  int r = n*2){
	shift(v , l , r);
	if(R <= l or r <= L)
		return;
	if(L <= l and r <= R){
		lazy[v] += val;
		shift(v , l , r);
		return;
	}
	int mid = (l + r)/2;
	update(L , R , val , 2*v , l , mid);
	update(L , R , val , 2*v + 1 , mid , r);
	seg[v] = seg[2*v] + seg[2*v + 1];
}


vector < pii > adj[maxn];

vector < pair < int , pii > > e;

int P[maxn];

int l [maxn] , r[maxn] , t = 1;

void dfs(int v = 1 , int par = 0 , int h = 0){
	P[v] = par;
	a.pb(h);
	r[v] = l[v] = t++;
	for(auto [u , w] : adj[v])	
		if(u!=par){
			dfs(u , v , h+w);
			a.pb(h);
			r[v] = t++;
		}
}

int32_t main(){
    migmig;
	cin >> q;
	seg.reserve(maxn*4);
	n = 4;
	adj[1].pb({2 , 1});
	adj[2].pb({1 , 1});
	adj[1].pb({3 , 1});
	adj[3].pb({1 , 1});
	adj[1].pb({4 , 1});
	adj[4].pb({1 , 1});
	for(int i = 1 ; i <= q ; i ++){
		int v;
		cin >> v;
		adj[v].pb({n + 1 , 0});
		adj[n + 1].pb({v , 0});
		adj[v].pb({n + 2 , 0});
		adj[n + 2].pb({v , 0});
		n = n + 2;
	}
	a.pb(177013);
	dfs();
	build();
	//dokme(seg[1].ans);
	int cur = 4;
	for(int i = 1 ; i <= q ; i ++){
		int par;
		par = cur+1;
		update(l[par] , r[par]+1 , 1);
		par = cur + 2;
		update(l[par] , r[par]+1 , 1);
		cur = cur + 2;
		cout << (seg[1].ans) << endl;	
	}
    return(0);
}
