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

const int maxn = 5e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int p , q , r;

struct card{
	int a , b , c;
}c[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

int mn[maxn << 2] , mx[maxn << 2] , lazy[maxn << 2];
ll sum[maxn << 2];

void shift(int v , int l , int r){
	if(lazy[v] == -1)return;
	mn[v] = mx[v] = lazy[v];
	sum[v] = lazy[v] * 1LL * (r - l);
	if(r - l > 1)
		lazy[lc] = lazy[v] , lazy[rc] = lazy[v];
	lazy[v] = -1;
}

void update(int L , int R , int x , int v = 1 ,  int l = 1 , int r = p + 1){
	shift(v , l , r);
	if(r <= L or R <= l or mn[v] >= x)
		return;
	if(L <= l and r <= R and mx[v] <= x){
		lazy[v] = x;
		shift(v , l , r);
		return;
	}
	update(L , R , x , lc , l , mid), update(L , R , x , rc , mid , r);
	sum[v] = sum[lc] + sum[rc];
	mn[v] = min(mn[lc] , mn[rc]);
	mx[v] = max(mx[lc] , mx[rc]);
}

int32_t main(){
	migmig;
	cin >> n;
	cin >> p >> q >> r;
	for(int i = 1 ; i <= n ; i ++)
		cin >> c[i].a >> c[i].b >> c[i].c;
	sort(c + 1 , c + n + 1 , [](card a , card b){return a.c > b.c;});
	ms(lazy , -1);
	for(int i = 1 ; i <= n ; i ++)
		update(1 , c[i].a + 1 , c[i].b);
	ll ans = 0;
	int pos = 1;
	for(int i = r ; i >= 1 ; i --){
		while(pos <= n and c[pos].c == i){
			update(1 , c[pos].a + 1 , q);
			update(c[pos].a + 1 , p + 1, c[pos].b);
			pos++;
		}
		ans += 1LL * p * q - sum[1];
	}
	cout << ans;
	return(0);
}
