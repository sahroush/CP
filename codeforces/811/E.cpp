/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int a[maxn][10];
int n , m , q;
int h;
int par[18][maxn];
	
int getpar(int v , int h){
	return((v == par[h][v]) ? v : par[h][v] = getpar(par[h][v] , h));
}

vector < pair < pii , int > > undo;

int merge(int u , int v , int h){
	u = getpar(u , h) , v = getpar(v , h);
	if(u == v)return(0);
	undo.pb({{h , u} , par[h][u]});
	par[h][u] = v;
	return(1);
}

struct node{
	int l[13];
	int r[13];
	int ans = 0;
	int h;
	void init(int x){
		ans = n;
		h = ::h;
		for(int i = 0 ; i < n ; i ++)
			l[i] = r[i] = x*n + i;
		for(int i = 1 ; i < n ; i ++)
			if(a[x][i] == a[x][i - 1])
				ans -= merge(l[i] , l[i - 1] , h);
		for(int i = 1 ; i < n ; i ++)
			l[i] = getpar(l[i] , h) , r[i] = getpar(r[i] , h); 
	}
	friend node operator + (node l , node r){
		node c;
		c.ans = l.ans + r.ans;
		c.h = l.h -1;
		if(::h == 100)c.h = 17;
		for(int i = 0 ; i < n ; i ++)c.l[i] = l.l[i];
		for(int i = 0 ; i < n ; i ++)c.r[i] = r.r[i];
		for(int i = 0 ; i < n ; i ++)
			if(a[l.r[i]/n][l.r[i]%n] == a[r.l[i]/n][r.l[i]%n])
				c.ans-=merge(l.r[i] , r.l[i] , c.h);
		for(int i = 0 ; i < n ; i ++)c.l[i] = getpar(c.l[i] , c.h) , c.r[i] = getpar(c.r[i] , c.h);
		return(c);
	}
};

vector < node > seg;

#define lc (v << 1)
#define rc (lc | 1)
#define mid (l + r)/2

void build(int v = 1,  int l = 0 , int r = m , int h = 0){
	::h = h;
	if(r - l == 1){
		seg[v].init(l);
		return;
	}
	build(lc , l , mid , h + 1);
	build(rc , mid , r , h + 1);
	::h = h;
	seg[v] = seg[lc] + seg[rc];
}

node get(int L ,int R ,int v = 1 , int l = 0 , int r = m , int h = 0){
	if(L <= l and r <= R)
		return(seg[v]);
	if(R <= mid)
		return(get(L , R , lc , l , mid , h + 1));
	if(L >= mid)
		return(get(L , R , rc , mid , r , h + 1));
	if(L < mid and R >= mid)
		return(get(L , R , lc , l , mid , h + 1) + get(L , R , rc , mid, r , h + 1));
}

int32_t main(){
    migmig;
	for(int i = 0 ; i < 18 ; i ++)
		for(int j = 0 ; j < maxn ; j ++)
			par[i][j] = j;
	cin >> n >> m >> q;
	seg.reserve(m * 4 + 100);
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < m ; j ++)
			cin >> a[j][i];
	build();
	h = 100;
	while(q -- ){
		int l , r;
		cin >> l >> r;
		l--;
		undo.clear();
		cout << get(l , r).ans << endl;
		reverse(undo.begin() , undo.end());
		for(auto [f , v] : undo){
			auto [h , u] = f;
			par[h][u] = v;
		}
	}
    return(0);
}
