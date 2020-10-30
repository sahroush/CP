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

const ll maxn  = 69000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;

struct segment{
	int seg[maxn*4];
	int lazy[maxn*4];
	void shift(int v , int l , int r){
		seg[v] += lazy[v];
		if(r - l > 1)
			lazy[2*v] += lazy[v] , lazy[2*v + 1] += lazy[v];
		lazy[v] = 0;
	}
	void update(int L , int R , int x, int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)
			return;
		if(L <= l and r <= R){
			lazy[v] += x;
			shift(v , l , r);
			return;
		}
		int mid = (l + r) / 2;
		update(L , R  , x , 2*v , l , mid);
		update(L , R , x , 2*v + 1 , mid , r);
		seg[v] = max(seg[2*v] , seg[2*v + 1]);
	}
	int query(int L , int R , int v = 1 , int l = 1 , int r = n + 1){
		shift(v , l , r);
		if(r <= L or R <= l)
			return(0);
		if(L <= l and r <= R)
			return(seg[v]);
		int mid = (l + r)/2;
		return(max(query(L , R , 2*v , l , mid) , query(L , R , 2*v + 1, mid , r)));
	}
};

segment seg[53];
int a;
int lst[maxn];

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 1; i <= n ; i ++){
		cin >> a;
		for(int j = k ; j ; j --)
			seg[j].update(lst[a]+1 , i , 1),
			seg[j].update(i , i + 1 , seg[j-1].query(1 , i) + 1);
		lst[a] = i;
	}
	cout << seg[k].query(1 , n + 1);
    return(0);
}