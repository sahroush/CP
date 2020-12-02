//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , t;
int l[maxn];
vector < int > r[maxn];

vector < pii > q[maxn];

int ans[maxn];

int mx[maxn*4];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l+r)>>1)

void build(int v = 1 , int l = 1 , int r = n + 1){
	mx[v] = 1e9;
	if(r - l == 1)
		return;
	build(lc , l , mid);
	build(rc , mid , r);
}

void shift(int v , int l , int r){
	if(r - l == 1)return;
	mx[lc] = min(mx[lc] , mx[v]);
	mx[rc] = min(mx[rc] , mx[v]);
}

//literally TOF
int query(int L , int R , int x, int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(mx[v] <= x or r <= L or R <= l)
		return(1e9);
	if(L <= l){
		for(; r - l > 1 ; ){
			if(mx[lc] > x) v = lc , r = mid;
			else v = rc , l = mid;
		}
		return(l);
	}
	int res = query(L , R , x , lc , l , mid);
	if(res < 1e9)return(res);
	return(query(L , R , x , rc , mid , r));
}

/* hamun balayi bedune TOF
int query(int L , int R , int x, int v = 1 , int l = 1 , int r = n + 1){
	shift(v , l , r);
	if(mx[v] <= x or r <= L or R <= l)
		return(1e9);
	if(r - l == 1){
		return(l);
	}
	return(min(query(L , R , x , lc , l , mid), query(L , R , x , rc , mid , r)));
}
*/

void update(int L , int R , int x , int v = 1 , int l = 1 , int r = n+1){
	shift(v , l, r);
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		mx[v] = min(mx[v] , x);
		shift(v , l, r);
		return;
	}
	update(L , R , x , lc , l , mid);
	update(L , R , x , rc , mid , r);
	mx[v] = max(mx[lc] , mx[rc]);
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++){
		int a , b;
		cin >> a >> b;
		if(a == b)continue;
		l[b] = a;
		r[a].pb(b);
	}
	cin >> t;
	for(int i = 1 ; i <= t ; i ++){
		int a, b;
		cin >> a >> b;
		q[a].pb({b , i});
	}
	build();
	for(int i = n ; i ; i --){
		for(auto R : r[i])
			update(i , R , R);
		for(auto [R , ind] : q[i])
			ans[ind] = query(i , R + 1 , R);
	}
	for(int i = 1 ; i <= t ; i ++)
		cout << ans[i] << endl;
    return(0);
}
