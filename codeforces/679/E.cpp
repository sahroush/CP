//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

#define mid ((l + r) >> 1)
#define lc (v << 1)
#define rc (lc | 1)

vector < int > p42;

int n , q;

int a[maxn];

int nxt(int x){return(*lower_bound(p42.begin() , p42.end() , x) - x);}

struct node{
	int a , mx , mn;
	friend node operator + (node a , node &b){
		if(b.a != a.a)a.a = 0;
		a.mn = min(a.mn , b.mn);
		a.mx = max(a.mx , b.mx);
		return(a);
	}
};

node seg[maxn*4];

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = {a[l] , nxt(a[l]) , nxt(a[l])};
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

int lazy[maxn*4];

void shift(int v , int l , int r){
	if(lazy[v] > 0){
		seg[v].a = lazy[v];
		seg[v].mn = seg[v].mx = nxt(seg[v].a);
	}
	else{
		if(seg[v].a)
			seg[v].a -= lazy[v] , seg[v].mn = seg[v].mx = nxt(seg[v].a);
		else seg[v].mn+=lazy[v] , seg[v].mx+=lazy[v];
	}
	if(r - l > 1){
		if(lazy[v] > 0)lazy[lc] = lazy[rc] = lazy[v];
		else lazy[lc] += ((lazy[lc] > 0)? -lazy[v] : lazy[v]) , lazy[rc] += ((lazy[rc] > 0)? -lazy[v] : lazy[v]);
	}
	lazy[v] = 0;
}

int get(int x , int v = 1 , int l = 1 , int r = n + 1){
	for(; r - l > 1 ; ){
		shift(v , l , r);
		if(x < mid)r = mid , v = lc;
		else l = mid , v = rc;
	}
	shift(v , l , r);
	return(seg[v].a);
}

void update(int L , int R , int x  , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] = x;
		shift(v , l , r);
		return;
	}
	update(L , R , x , lc , l , mid);
	update(L , R , x , rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

void fisht(int v , int l , int r){
	if(seg[v].a or seg[v].mn + lazy[v] >= 0){
		shift(v , l , r);
		return;
	}
	lazy[lc] += lazy[v] , lazy[rc] += lazy[v];
	fisht(lc , l , mid);
	fisht(rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
	lazy[v] = 0;
}

void add(int L , int R , int x , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] = -x;
		fisht(v , l , r);
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

int32_t main(){
    migmig;
	p42.pb(1);
	while(p42.back() < 1e16)p42.pb(p42.back()*42);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	build();
	while(q -- ){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			cout << get(x) << endl;
		}
		if(t == 2){
			int l , r , x;
			cin >> l >> r >> x;
			update(l , r+1 , x);
		}
		if(t == 3){
			int l , r , x;
			cin >> l >> r >> x;
			add(l , r+1 , x);
			while(seg[1].mn <= 0)
				add(l , r+1 , x);
		}
	}
    return(0);
}
