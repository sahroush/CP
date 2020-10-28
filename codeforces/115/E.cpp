/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
ll a[maxn];
vector < pii > r[maxn];

struct segment{
	int n;
	vector < ll > seg;
	vector < ll > lazy;
	segment(int N):
		n(N+1),
		seg(4*n), lazy(4 * n){}
	void shift(int v ,int  l ,int r){
		seg[v] += lazy[v];
		if(r - l > 1)
			lazy[2*v]+= lazy[v],
			lazy[2*v + 1]+= lazy[v];
		lazy[v] = 0;
	}
	void update(int L , int R , ll x , int v = 1, int l = 1, int r = 0){
		if(!r)r=n;
		shift(v , l , r);
		if(r <= L or R <= l)
			return;
		if(L <= l and r <= R){
			lazy[v] = x;
			shift(v, l , r);
			return;
		}
		int mid = (l + r)/2;
		update(L , R , x , 2*v , l , mid);
		update(L , R , x , 2*v + 1 , mid , r);
		seg[v] = max(seg[2*v] , seg[2*v + 1]);
	}
	ll mx(){
		shift(1 , 1 , n+1);
		return(seg[1]);
	}
};

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i ++){
		int l , r;
		ll p;
		cin >> l >> r >> p;
		::r[r].pb({l , p});
	}
	segment seg(n + 1);
	for(int i = 1 ; i <= n ; i ++){
		seg.update(i + 1 , i + 2 , seg.mx());
		for(auto [l , p] : r[i])
			seg.update(1 , l + 1 , p);
		seg.update(1 , i + 1 , -a[i]);
	}
	cout << seg.mx();
    return(0);
}
