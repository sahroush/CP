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

const int maxn = 2e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q , t;
string s , f;
int l[maxn] , r[maxn];

int lazy[maxn<<2];
int sum[maxn<<2];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void build(int v = 1 , int l = 0 , int r = n){
	lazy[v] = -1;
	if(r - l == 1){
		sum[v] = (f[l] == '1');
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	sum[v] = sum[lc] + sum[rc];
}

void shift(int v , int l , int r){
	if(lazy[v] == -1)return;
	if(lazy[v] == 0)
		sum[v] = 0;
	else
		sum[v] = r - l;
	if(r - l > 1)
		lazy[lc] = lazy[rc] = lazy[v];
	lazy[v] = -1;
}

void update(int L , int R , int x , int v = 1 , int l = 0 , int r = n){
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
	sum[v] = sum[lc] + sum[rc];
}

int get(int L , int R , int v = 1 , int l = 0 , int r = n){
	shift(v , l , r);
	if(r <= L or R <= l)
		return(0);
	if(L <= l and r <= R)
		return(sum[v]);
	return(get(L , R , lc , l , mid) + get(L , R , rc , mid , r));
}

bool chk(){
	for(int i = 0 ; i < n ; i ++)
		if(get(i , i + 1) != (s[i] == '1'))
			return(0);
	return(1);
}

int32_t main(){
	migmig;
	cin >> t;
	while(t -- ){
		cin >> n >> q;
		cin >> s >> f;
		for(int i = 0 ; i < q ; i ++)
			cin >> l[i] >> r[i];
		reverse(l , l + q);
		reverse(r , r + q);
		build();
		bool ok = 1;
		for(int i = 0 ; i < q ; i ++){
			int l = ::l[i] , r = ::r[i];
			int sz = (r - l + 1);
			int res = get(l - 1 , r);
			if(res == sz - res){
				ok = 0;
				break;
			}
			if(res > sz - res)
				update(l - 1 , r , 1);
			else
				update(l - 1 , r , 0);
		}
		if(!ok){
			cout << "NO" << endl;
			continue;
		}
		cout << ((chk()) ? "YES" : "NO") << endl;
	}
	return(0);
}
