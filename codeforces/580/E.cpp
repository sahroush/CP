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
const ll mod = 177013;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k;
int q;
string s;

struct segment{
	int ch;
	int maxn;
	vector < int > seg;
	vector < int > lazy;
	int base;
	vector < int > pw;
	vector < int > sum;
	segment(int v , int sz):
		ch(v) , maxn(sz + 100) , seg(maxn*4 , 0) , lazy(maxn*4 , -1),
		base(rng()%500 + 300) , pw(maxn) ,sum(maxn){}
	void build(int v = 1 , int l = 1 , int r = n + 1){
		if(r - l == 1){
			if(s[l] - '0' == ch)seg[v] = 1;
			return;
		}
		int mid = (l + r)/2;
		build(2*v , l , mid);
		build(2*v + 1 , mid , r);
		seg[v] = ((ll(seg[2*v]) * pw[r - mid])%mod + (ll)seg[2*v + 1])%mod;
	} 
	void calc(){
		sum[0] = pw[0] = 1;
		for(int i = 1; i < maxn ; i ++)
			pw[i] = (pw[i - 1] * base)%mod, sum[i] = (pw[i] + sum[i-1])%mod;
	}
	void shift(int v , int l , int r){
		if(lazy[v] == -1)return;
		if(lazy[v] == 1)seg[v] = sum[r - l - 1];
		else seg[v] = 0;
		if(r - l > 1)
			lazy[2*v] = lazy[2*v + 1] = lazy[v];
		lazy[v] = -1;
	}
	void update(int L , int R , int x, int v = 1, int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)
			return;
		if(L <= l and r <= R){
			lazy[v] = x;
			shift(v , l , r);
			return;
		}
		int mid = (l + r) / 2;
		update(L , R , x, 2*v , l , mid);
		update(L , R , x, 2*v + 1, mid , r);
		seg[v] = ((ll(seg[2*v]) * pw[r - mid])%mod + (ll)seg[2*v + 1])%mod;
	}
	ll query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)
			return(0);
		if(L <= l and r <= R)
			return(seg[v]);
		int mid = (l + r)/2;
		int sz = max(0 , min(R , r) - mid);
		return((ll(query(L , R , 2*v , l , mid)))%mod * pw[sz] + query(L , R , 2*v + 1 , mid , r))%mod;	
	}
};

vector < segment > seg;

int32_t main(){
    migmig;
	cin >> n >> m >> k;
	cin >> s;
	q = m + k;
	s = "a" + s;
	for(int i = 0 ; i < 10 ; i ++)
		seg.pb(segment(i , n));
	for(int i = 0 ; i < 10 ; i ++)
		seg[i].calc(), seg[i].build();
	while(q -- ){
		int t;
		cin >> t;
		if(t == 1){
			int l , r ;
			char c;
			cin >> l >> r >> c;
			int ch = c - '0';
			for(int i = 0 ; i < 10 ; i ++)	
				seg[i].update(l , r + 1 , 0);
			seg[ch].update(l , r + 1 , 1);
		}
		else{
			int l , r , d;
			cin >> l >> r >> d;
			bool ok = 1;
			for(int i = 0 ; i < 10 ; i ++)
				ok&= (seg[i].query(l+d , r + 1) == seg[i].query(l , r-d + 1));
			cout << ((ok)?"YES":"NO") << endl;
		}
	}
    return(0);
}
