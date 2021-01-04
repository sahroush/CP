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

const ll maxn = 2e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k , q;

struct node{
	vector < int > a;
	vector < int > data;
	node():
		a(k , -1), data((1 << k) , -1e7){}
	void inp(){
		a.clear();
		data.clear();
		a.resize(k);
		for(int i = 0 ; i < k ; i ++)
			cin >> a[i];
		data.resize((1 << k));
		for(int i = 0 ; i < (1 << k) ; i ++)
			for(int j = 0 ; j < k ; j ++)
				if((1 << j)&i)
					data[i] += a[j];
				else
					data[i] -= a[j];
	}
	friend node operator + (node l , node r){
		assert(l.data.size());
		assert(r.data.size());
		for(int i = 0 ; i < (1 << k) ; i ++)
			l.data[i] = max(l.data[i] , r.data[i]);
		return(l);
	}
}seg[maxn*4];

#define lc (v * 2)
#define rc (v * 2 + 1)
#define mid ((l + r)/2)

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v].inp();
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

void update(int pos , int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v].inp();
		return;
	}
	if(pos < mid)
		update(pos , lc , l , mid);
	else
		update(pos , rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

node query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){	
	if(r <= L or R <= l)
		return(node());
	if(L <= l and r <= R)
		return(seg[v]);
	return(query(L , R , lc , l , mid) + query(L , R , rc , mid , r));
}

int solve(node x){
	int ans = 0;
	int bz = (1 << k)-1;
	for(int i = 0 ; i < (1 << k) ; i ++)
		ans = max(ans , x.data[i] + x.data[i^bz]);
	return(ans);
}

int32_t main(){
    migmig;
	cin >> n >> k;
	build();
	cin >> q;
	while(q -- ){
		int t;
		cin >> t;
		if(t == 1){
			int i;
			cin >> i;
			update(i);
		}
		else{
			int l , r;
			cin >> l >> r;
			cout << solve(query(l , r + 1)) << endl;
		}
	}
    return(0);
}
