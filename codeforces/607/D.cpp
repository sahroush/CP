/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

//#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct segment{
	int n;
	vector < ll > seg;
	vector < ll > lazy;
	segment(int N):
		n(N),
		seg((n+100)*4), lazy((n+100)*4 , 1){}
	void shift(int v , int l , int r){
		seg[v] = (seg[v] * lazy[v])%mod;
		if(r - l > 1)
			lazy[2*v] = (lazy[2*v] * lazy[v])%mod,
			lazy[2*v + 1] = (lazy[2*v + 1] * lazy[v]) % mod;
		lazy[v] = 1;
	}
	void update(int L , int R , ll x , int v = 1 , int l = 1 , int r = 0){
		if(!r)r=n+1;
		shift(v , l , r);
		if(r <= L or R <= l)
			return;
		if(L <= l and r <= R){
			lazy[v] = x;
			shift(v , l , r);
			return;
		}
		int mid = (l + r)/2;
		update(L , R , x , 2*v , l , mid);
		update(L , R , x , 2*v + 1, mid , r);
		seg[v] = (seg[2*v] + seg[2*v + 1])%mod;
	}
	void add(int pos ,  ll x , int v = 1 , int l = 1 , int r = 0){
		if(!r)r=n+1;
		shift(v , l , r);
		if(r - l == 1){
			seg[v] = x;
			return;
		}
		int mid = (l + r)/2;
		if(pos < mid)add(pos , x , 2*v , l , mid);
		else add(pos , x , 2*v + 1, mid , r);
		seg[v] = (seg[2*v] + seg[2*v + 1])%mod;
	}
	ll query(int L , int R , int v = 1 , int l = 1 , int r = 0){
		if(!r)r=n+1;
		shift(v , l , r);
		if(r <= L or R <= l)
			return(0);
		if(L <= l and r <= R)
			return(seg[v]);
		int mid = (l + r)/2;
		return((query(L , R , 2*v , l , mid) + query(L , R , 2*v + 1, mid , r))%mod);
	}
};

vector < int > adj[maxn];
ll d[maxn];
int l[maxn] , r[maxn] , t = 1;
ll v[maxn];
int q , n;
int par[maxn];

vector < int > vec;

void dfs(int v = 1){
	r[v] = l[v] = t++;
	for(auto u : adj[v])
		dfs(u) ,r[v] = r[u];
}

int32_t main(){
    migmig;
	cin >> v[1] >> q;
	n = 1;
	for(int i = 0 ; i < q ; i ++){
		int t;
		cin >> t;
		if(t == 1){
			int par , v;
			cin >> par >> v;
			n ++ ;
			::v[n] = v;
			adj[par].pb(n);
			vec.pb(n);
			::par[n] = par;
		}
		else{
			int v;
			cin >> v;
			vec.pb(v);
		}
	}
	segment seg(n);
	dfs();
	int cnt = 1;
	seg.add(1 , v[1]);
	for(auto v : vec){
		if(cnt < v){
			cnt ++ ;
			d[par[v]] ++;
			seg.add(l[v] , ::v[v]);
			seg.update(l[v] , r[v]+1 , (seg.query(l[par[v]] , l[par[v]] + 1) * pw(::v[par[v]] , mod - 2))%mod);
			seg.update(l[par[v]] , r[par[v]] + 1 , ((d[par[v]] + 1) * pw(d[par[v]] , mod - 2))%mod);
		}
		else{
			ll ans = seg.query(l[v] , r[v] + 1);
			ans = (ans * (d[v] + 1))%mod;
			ans = ans * ((::v[v] * pw(seg.query(l[v] , l[v] + 1) , mod - 2))%mod);
			cout << ans%mod << endl;
		}
	}
    return(0);
}
