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

const int maxn = 3e4 + 10;
const ll mod = 1e9+7;
const ll p = 1e7+19;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q , k;
struct chiz{
	int w , v;
}s[maxn];
vector < chiz > seg[maxn<<2];
int fst[maxn];
bool ask[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void add(int L , int R , chiz  x ,  int v = 1 , int l = 0 , int r = maxn){
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		seg[v].pb(x);
		return;
	}
	add(L , R , x , lc , l , mid);
	add(L , R , x , rc , mid , r);
}

vector < int > ks[maxn<<2];
vector < int > knap(1100) , sack;
int power[maxn];

void build(int v = 1 , int l = 0 , int r = maxn){
	sack = ks[v] = knap;
	for(auto x : seg[v]){
		for(int i = x.w ; i <= k ; i ++){
			knap[i] = max(knap[i] , sack[i-x.w] + x.v);
		}
		sack = knap;
	}
	if(r - l == 1 and ask[l]){
		ll res = 0;
		for(int i = 1 ; i <= k ; i ++){
			res = (res + (knap[i] * 1LL * power[i])%mod)%mod;
		}	
		cout << res << endl;
	}else if (r - l > 1){
		build(lc , l , mid);
		build(rc , mid , r);
	}
	knap = ks[v];
	ks[v].clear();
	ks[v].shrink_to_fit();
}

int32_t main(){
	migmig;
	cin >> n >> k;
	for(int i = 1 ; i <= k ; i ++)
		power[i] = pw(p , i - 1 , mod);
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i].v >> s[i].w;
	cin >> q;
	for(int i = 1 ; i <= q ; i ++){
		int t;
		cin >> t;
		if(t == 1){
			n++;
			cin >> s[n].v >> s[n].w;
			fst[n] = i;
		}
		if(t == 2){
			int x;
			cin >> x;
			add(fst[x] , i , s[x]);
			fst[x] = -1;
		}
		if(t == 3){
			ask[i] = 1;
		}
	}
	for(int i = 1 ; i <= n ; i ++)if(fst[i] ^ -1)add(fst[i] , maxn , s[i]);
	build();
	return(0);
}
