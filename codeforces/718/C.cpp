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

const int maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;

struct matrix{
	int a[2][2] = {{0 , 1} , {1 , 1}};
	friend matrix operator * (matrix a , matrix b){
		matrix c;
		ms(c.a , 0);
		for(int i = 0 ; i < 2 ; i ++)
		for(int k = 0 ; k < 2 ; k ++)
		for(int j = 0 ; j < 2 ; j ++)
		c.a[i][k] = (c.a[i][k] + a.a[i][j] * 1LL * b.a[j][k])%mod;
		return c;
	}
	friend matrix operator ^ (matrix a , int x){
		matrix b = a;
		while(x){
			if(x&1) b = b * a;
			x >>= 1 , a = a * a;
		}
		return b;
	}
}seg[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r)>>1)

matrix lazy[maxn<<2];

void build(int v = 1 , int l = 1 , int r = n + 1){
	ms(lazy[v].a , 0), lazy[v].a[0][0] = 1 , lazy[v].a[1][1] = 1;
	if(r - l == 1){
		int x;
		cin >> x;
		matrix c , u;
		c.a[0][0] = 1 , c.a[0][1] = 0 , c.a[1][0] = 0 , c.a[1][1] = 1;
		c = c * (u^(x-1));
		seg[v] = c;
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	for(int i = 0 ; i < 2 ; i ++)
	for(int j = 0 ; j < 2 ; j ++)
		seg[v].a[i][j] = (seg[lc].a[i][j] + seg[rc].a[i][j])%mod;
}

void shift(int v , int l , int r){
	seg[v] = seg[v] * lazy[v];
	if(r - l > 1)
		lazy[lc] = lazy[lc] * lazy[v],lazy[rc] = lazy[rc] * lazy[v];
	ms(lazy[v].a , 0), lazy[v].a[0][0] = 1 , lazy[v].a[1][1] = 1;
}

void mul(int L , int R , matrix x,  int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] = x;
		shift(v , l , r);
		return;
	}
	mul(L , R , x , lc , l , mid);
	mul(L , R , x , rc , mid , r);
	for(int i = 0 ; i < 2 ; i ++)
	for(int j = 0 ; j < 2 ; j ++)
		seg[v].a[i][j] = (seg[lc].a[i][j] + seg[rc].a[i][j])%mod;
}

int get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return 0;
	if(L <= l and r <= R)
		return seg[v].a[0][1];
	return (get(L , R , lc , l , mid) + get(L , R , rc , mid , r))%mod;
}

int32_t main(){
	migmig;
	cin >> n >> q;
	build();
	while(q --){
		int t, l , r;
		cin >> t >> l >> r;
		if(t == 1){
			int x;
			cin >> x;
			matrix u;
			u = u ^ (x - 1);
			mul(l , r + 1 , u);
		}
		else
			cout << get(l , r + 1) << endl;
	}
	return(0);
}
