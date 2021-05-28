//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 4e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, q;
int a[maxn];
ll pr[300];
vector < int > prime;
int seg[maxn<<2] , lazy[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

struct range{
	ll seg[maxn << 2] , lazy[maxn << 2];
	void shift(int v , int l , int r){
		seg[v] |= lazy[v];
		if(r - l > 1)
			lazy[lc] |= lazy[v] , lazy[rc] |= lazy[v];
	}
	void add(int L , int R , ll x , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)return;
		if(L <= l and r <= R){
			lazy[v] = x;
			shift(v , l , r);
			return;
		}
		add(L , R , x , lc , l , mid);
		add(L , R , x , rc , mid , r);
		seg[v] = seg[lc] | seg[rc];
	}
	ll get(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)return 0;
		if(L <= l and r <= R)
			return seg[v];
		return get(L , R , lc , l , mid) | get(L , R , rc , mid , r);
	}
}sag;

void build(int v = 1 , int l = 1 , int r = n+1){
	lazy[v] = seg[v] = 1;
	if(r - l == 1)return;
	build(lc , l , mid);
	build(rc , mid , r);
}

void shift(int v , int l , int r){
	if(lazy[v] == 1)return;
	seg[v] = (seg[v] * 1ll * pw(lazy[v] , r - l))%mod;
	if(r - l > 1)
		lazy[lc] = (lazy[lc] * 1ll * lazy[v])%mod, lazy[rc] = (lazy[rc] * 1ll * lazy[v])%mod;
	lazy[v] = 1;
}

void mul(int L , int R , ll x , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)return;
	if(L <= l and r <= R){
		lazy[v] = x;
		shift(v , l , r);
		return;
	}
	mul(L , R , x , lc , l , mid);
	mul(L , R , x , rc , mid , r);
	seg[v] = (seg[lc] * 1ll * seg[rc])%mod;
}

ll query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(r <= L or R <= l)return 1;
	if(L <= l and r <= R)
		return seg[v];
	return (query(L , R , lc , l , mid) * query(L , R , rc , mid , r))%mod;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 2 ; i < 300 ; i ++)if(!pr[i]){
		prime.pb(i);
		pr[i] = prime.size()-1;
		for(int j = i + i ; j < 300 ; j += i)pr[j] = -1;
	}
	cin >> n >> q;
	build();
	for(int i = 1 ; i <= n ; i ++)cin >> a[i];
	for(int i = 1 ; i <= n ; i ++){
		mul(i , i + 1 , a[i]);
		for(auto x : prime)if(a[i] % x == 0)
			sag.add(i , i+1 , (1LL << pr[x]));
	}
	while(q --){
		string s;
		int a , b , c;
		cin >> s;
		if(s == "TOTIENT"){
			cin >> a >> b;
			ll res = query(a , b + 1);
			ll bz = sag.get(a , b + 1);
			for(auto x : prime)if(bz & (1LL << pr[x]))
				res = (res * ((x * 1ll - 1) * pw(x , mod - 2) % mod)%mod);
			cout << res << endl;
		}
		else{
			cin >> a >> b >> c;
			mul(a , b + 1 , c);
			for(auto x : prime)if(x ^ 1 and c % x == 0){
				sag.add(a , b + 1, (1LL << pr[x]));
			}
		}
	}
	return(0);
}
