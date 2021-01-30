/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
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

int q;
int n , a[maxn] , b[maxn] , c[maxn];

int lazy[maxn<<2];
int mx[maxn<<2];

const int inf = 1e11;

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void build(int v = 1 , int l = 1 , int r = n + 1){
	mx[v] = -inf;
	lazy[v] = 0;
	if(r - l == 1)
		return;
	build(lc , l , mid);
	build(rc , mid , r);
}

void shift(int v , int l , int r){
	mx[v] += lazy[v];
	if(r - l > 1)
		lazy[lc] += lazy[v] , lazy[rc] += lazy[v];
	lazy[v] = 0;
}

void add(int x){
	lazy[1] += x;
	shift(1 , 1 , n + 1);
}

void st(int pos , int x , int v = 1 , int l = 1 , int r = n + 1){ // bale bale baa std::set khali ham mishe ama codesho zadam :P
	shift(v , l , r);
	if(r - l == 1){
		mx[v] = x;
		return;
	}
	if(pos < mid)
		st(pos , x , lc , l , mid);
	else
		st(pos , x , rc , mid , r);
	shift(lc , l , mid);
	shift(rc , mid , r);
	mx[v] = max(mx[lc] , mx[rc]);
}

int32_t main(){
	migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> c[i];
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		for(int i = 1 ; i <= n ; i ++)
			cin >> b[i];
		int ans = 3;
		build();
		for(int i = 2 ; i <= n ; i ++){
			if(a[i] == b[i])add(-inf);
			st(i - 1 , abs(a[i] - b[i]));
			add(2);
			ans = max(ans , c[i] + mx[1] - 1);
			if(i != n){
				if(a[i + 1] < b[i + 1]){
					add(a[i + 1] - 1 + c[i] - b[i + 1]);
				}
				else{
					add(b[i + 1] - 1 + c[i] - a[i + 1]);
				}
			}
		}
		cout << ans << endl;
	}
	return(0);
}
