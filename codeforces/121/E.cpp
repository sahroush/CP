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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < int > luc;
int n , q;
int a[maxn];
int nxt(int x){return(*lower_bound(luc.begin() , luc.end() , x) - x);}

bool lucky(int x){
	while(x){
		if(x%10 != 4 and x%10 != 7)return(0);
		x/=10;
	}
	return(1);
}

struct node{
	int mn , mx , val , cnt;
	node ():
		mn(1e9) , mx(-1e9) , val(1e9) , cnt(0){}
	node (int x):
		mn(nxt(x)) , mx(nxt(x)) , val(x) , cnt(1){}
	friend node operator + (node a , node b){
		if(a.mn == b.mn)a.cnt += b.cnt;
		a.mx = max(a.mx , b.mx);
		if(b.mn < a.mn)a.cnt = b.cnt;
		a.mn = min(a.mn , b.mn);
		if(a.val != b.val) a.val = 1e9;
		return(a);
	}
}seg[maxn * 4];

#define mid ((l + r) >> 1)
#define lc (v << 1)
#define rc (lc | 1)

int lazy[maxn * 4];

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = node(a[l]);
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

void shift(int v , int l , int r){
	if(!lazy[v])return;
	if(seg[v].val != 1e9)
		seg[v].val -= lazy[v] , seg[v].mn = seg[v].mx = nxt(seg[v].val);
	else 
		seg[v].mn+=lazy[v] , seg[v].mx+=lazy[v];
	if(r - l > 1){
		lazy[lc] += lazy[v] , lazy[rc] += lazy[v];
	}
	lazy[v] = 0;
}

int get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)
		return(0);
	if(seg[v].mn > 0)
		return(0);
	if(L <= l and r <= R)
		return(seg[v].cnt);
	return(get(L , R , lc , l , mid) + get(L , R , rc , mid , r));
}

void fisht(int v , int l , int r){
	if(!lazy[v])return;
	if(seg[v].val < 1e9 or seg[v].mn + lazy[v] >= 0){
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
		lazy[v] -= x;
		fisht(v , l , r);
		return;
	}
	add(L , R , x , lc ,l , mid);
	add(L , R , x , rc , mid, r);
	seg[v] = seg[lc] + seg[rc];
}

int32_t main(){
    migmig;
	for(int i = 1 ; i < 100000 ; i++)
		if(lucky(i))
			luc.pb(i);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	build();
	while(q -- ){
		string t;
		cin >> t;
		if(t == "add"){
			int l , r , x;
			cin >> l >> r >> x;
			add(l , r + 1, x);
		}
		else{
			int l , r;
			cin >> l >> r;
			cout << get(l , r + 1) << endl;
		}
	}
    return(0);
}
