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

const ll maxn = 1e6 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
string s;

struct node{
	int one , zero  , inc , dec ;
	node():
		one(0) , zero(0) , inc(0) , dec(0){}
	node(char a):
		one((a == '7')) , zero((a == '4')) , inc(1) , dec(1){}
	void flip(){
		swap(one , zero);
		swap(inc , dec);
	}
	friend node operator + (node l , node r){
		node c = node();
		c.one = l.one + r.one;
		c.zero = l.zero + r.zero;
		c.inc = max(l.inc + r.one , l.zero + r.inc );
		c.dec = max(l.dec + r.zero , l.one + r.dec );
		return(c);
	}
}seg[maxn*4];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void build(int v = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		seg[v] = node(s[l]);
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}
bool lazy[maxn * 4];

void shift(int v , int l , int r){
	if(!lazy[v])return;
	seg[v].flip();
	if(r - l > 1)
		lazy[lc]^=1 , lazy[rc]^=1;
	lazy[v] = 0;
}

void flip(int L , int R , int v = 1 , int l = 0 , int r = n){
	shift(v , l , r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		lazy[v] = 1;
		shift(v , l , r);
		return;
	}
	flip(L , R , lc , l , mid);
	flip(L , R , rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

int32_t main(){
    migmig;
	cin >> n >> q;
	cin >> s;
	build();
	while(q --){
		string s;
		cin >> s;
		if(s == "count")
			cout << seg[1].inc << endl;
		else{
			int l , r;
			cin >> l >> r;
			flip(l - 1 , r);
		}	
	}
    return(0);
}
