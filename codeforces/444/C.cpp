/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
vector < int > seg;
vector < ll > ans , lazy;

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = l;
		return;
	}
	int mid = (l + r)/2;
	build(2*v , l , mid);
	build(2*v + 1 , mid , r);
}

void shift(int v , int l , int r){
	if(!lazy[v])return;
	ans[v] += lazy[v] * 1LL * (r - l);
	if(r - l > 1)
		lazy[2*v]+=lazy[v] , seg[2*v] = seg[v] , seg[2*v + 1] = seg[v], lazy[2*v + 1] += lazy[v];
	lazy[v] = 0;
}

void update(int  L , int R , int x , int v = 1 , int l = 1, int r = n + 1){
	shift(v , l , r);
	if(R <= l or r <= L)
		return;
	if(L <= l and r <= R and seg[v]){
		lazy[v] += abs(x - seg[v]);
		seg[v] = x;
		shift(v , l, r);
		return;
	}

	int mid = (l + r)/2;
	update(L , R , x , 2*v , l , mid);
	update(L , R , x , 2*v + 1 , mid , r);
	seg[v] = ((seg[2*v] == seg[2*v + 1]) ? seg[2*v] : 0);
	ans[v] = ans[2*v] + ans[2*v + 1];
}

ll query(int L , int R , int v = 1 , int l = 1 , int  r = n + 1){
	shift(v , l , r);
	if(R <= l or r <= L)
		return(0);
	if(L <= l and r <= R)
		return(ans[v]);
	int mid = (l + r)/2;
	return(query(L , R , 2*v , l , mid) + query(L , R , 2*v + 1 ,mid , r));
}	

int32_t main(){
    migmig;
	cin >> n >> q;
	seg.resize(n*4);
	lazy.resize(n*4);
	ans.resize(n*4);
	build();
	while(q -- ){
		int t , l , r , x;
		cin >> t >> l >> r;
		if(t == 1)
			cin >> x ,update(l , ++r , x);
		else
			cout << query(l , ++r) << endl;
	}
    return(0);
}
