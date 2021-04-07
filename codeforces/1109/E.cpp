#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
const int k = 9;

typedef int64_t ll;

#define sz(x) (int)x.size()
#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

int n,  mod , fen[k][maxn] , phi, pw[k][maxn * 25] , a[maxn], q;
vector < int > f;

void add (int pos , int x , int *fen){	
	for(pos += 5 ; pos < maxn ; pos += pos & -pos)	fen[pos] += x;
}

int get(int pos , int *fen){
	int res = 0;
	for(pos += 5 ; pos ; pos -= pos & -pos)	res += fen[pos];
	return res;
}

void add(int l , int r , int x , int *fen){
	add(l , x , fen),	add(r + 1 , -x , fen);
}

void calc(int x){
	phi = x;
	for(int i = 2 ; i * i <= x ; i ++)if(x % i == 0){
		while(x % i == 0)x /= i;
		phi -= phi/i,		f.push_back(i);
	}
	if(x > 1)phi -= phi/x , f.push_back(x);
}

struct segment{
	ll sum[maxn<<2] , lazy[maxn<<2];
	void build(){
		fill(lazy , lazy + (maxn << 2) , 1);
	}
	void shift(int v, int l , int r){
		if(lazy[v] == 1)return;
		sum[v] = (sum[v] * lazy[v])%mod;
		if(r - l > 1)
			lazy[lc] = (lazy[lc] * lazy[v])%mod , lazy[rc] = (lazy[rc] * lazy[v])%mod;
		lazy[v] = 1;
	}
	void calc(int v , int l , int r){
		if(r - l == 1)return;
		shift(lc , l , mid) , shift(rc , mid , r);
		sum[v] = (sum[lc] + sum[rc])%mod;
	}
	void set(int pos , ll x , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r - l == 1){
			sum[v] = x;
			return;
		}
		if(pos < mid)
			set(pos , x , lc , l , mid);
		else
			set(pos , x , rc , mid , r);
		calc(v , l , r);
	}
	void mul(int L , int R , ll x , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)return;
		if(L <= l and r <= R){
			lazy[v] = x;
			shift(v , l , r);
			return;
		}
		mul(L , R , x , lc , l , mid) , mul(L , R , x , rc , mid , r);
		calc(v , l , r);
	}
	ll get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)
			return 0;
		if(L <= l and r <= R)
			return sum[v];
		return (get(L , R , lc , l , mid) + get(L , R , rc , mid , r))%mod;
	}
}cop , all;

int inv(ll a , ll b){ll res=1;while(b){if(b&1)res=(res*a)%mod;b>>=1;a=(a*a)%mod;}return res;}

int32_t main(){
	cin.tie(0) , cout.tie(0) , ios::sync_with_stdio(0);
	cin >> n >> mod, calc(mod);
	for(int j = 0 ; j < sz(f) ; j ++){
		pw[j][0] = 1;
		for(int i = 1 ; i < maxn * 25 ; i ++)
			pw[j][i] = (pw[j][i-1] * 1LL * f[j])%mod;
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		all.set(i , a[i]%mod);
		for(int j = 0 ; j < sz(f) ; j ++)
			while(a[i] % f[j] == 0)	a[i] /= f[j], add(i , i , 1 , fen[j]);
		cop.set(i , a[i]%mod);
	}
	cin >> q;
	while(q --){
		int t;
		cin >> t;
		if(t == 1){
			int l ,  r , x , y;
			cin >> l >> r >> x;
			y = x;
			for(auto p : f)	while(x % p == 0)x /= p;
			all.mul(l , r + 1 , y);
			cop.mul(l , r + 1 , x);
			y /= x;
			for(int i = 0 ; i < sz(f) ; i ++){
				int cnt = 0;
				while(y % f[i] == 0)
					cnt++ , y /= f[i];
				add(l , r , cnt , fen[i]);	
			}
		}	
		if(t == 2){
			int pos , x;
			cin >> pos >> x;
			int y = x;
			for(auto p : f)while(x % p == 0)x /= p;
			y /= x;
			ll prv = (cop.get(pos , pos + 1) * inv(x , phi-1))%mod , ans = prv;
			for(int i = 0 ; i < sz(f) ; i ++){
				int cnt = 0;
				while(y % f[i] == 0)cnt++ , y /= f[i];
				add(pos , pos , -cnt , fen[i]);
				ans = (ans * pw[i][get(pos , fen[i])])%mod;
			}
			all.set(pos , ans);
			cop.set(pos , prv);
		}
		if(t == 3){
			int l , r;
			cin >> l >> r;
			cout << all.get(l , r + 1) << endl;
		}
	}
	return 0;
}
