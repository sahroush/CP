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

const int maxn = 2e5;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , n;
vector < int > vec[maxn];
ll ans;
ll mx[maxn<<2];
ll kir[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void build(int v = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		kir[l] = ((vec[l].size()) ? vec[l].back() : 0);
		mx[v] = l;
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	if(kir[mx[lc]] >= kir[mx[rc]])mx[v] = mx[lc];
	else mx[v] = mx[rc];
}

ll get(int L , int R , int v = 1 , int l = 0 , int r = n){
	if(r <= L or R <= l)return(0);
	if(L <= l and r <= R)
		return(mx[v]);
	int gl = get(L , R , lc , l , mid);
	int gr = get(L , R , rc , mid , r);
	if(kir[gl] >= kir[gr])return(gl);
	return(gr);
}

void pop(int pos , int v = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		if(vec[l].size())vec[l].pop_back();
		kir[l] = ((vec[l].size()) ? vec[l].back() : 0);
		mx[v] = l;
		return;
	}
	if(pos < mid)
		pop(pos , lc , l , mid);
	else
		pop(pos , rc , mid , r);
	if(kir[mx[lc]] >= kir[mx[rc]])mx[v] = mx[lc];
	else mx[v] = mx[rc];
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n;
		ans = 0;
		for(int i = 0 ; i < n ; i ++)vec[i].clear();
		for(int i = 0 ; i < n ; i ++){
			int a , b;
			cin >> a >> b;
			vec[a].pb(b);
			ans += b;
		}
		for(int i = 0 ; i < n ; i ++)sort(vec[i].begin() , vec[i].end());
		build();
		for(int i = 0 ; i < n ; i ++){
			ans -= kir[get(0 , i+1)];
			pop(get(0 , i+1));
		}
		cout << ans << endl;
	}
	return(0);
}
