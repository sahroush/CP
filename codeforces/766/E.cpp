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
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5 + 10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int lg = 21;

int n;
int a[maxn];
vector < int > adj[maxn];
ll cnt[2][lg+2];
ll ans;

int sz[maxn] , hide[maxn];

void plant(int v , int par = 0){
	sz[v] = 1;
	for(auto u : adj[v])
		if(u!=par and !hide[u])
			plant(u , v) , sz[v] += sz[u];
}


int cen(int v , int n , int par = 0){
	bool found = 0;
	while(!found){
		found = 1;
		for(auto u : adj[v])
			if(u != par and !hide[u] and sz[u] * 2 > n){
				par = v;
				v = u;
				found = 0;
				break;
			}
	}
	return(v);
}

ll cn[2][lg + 2];

void calc(int v , int par  , ll c ){
	for(int i = 0 ; i < lg ; i ++)
		if(c & (1 << i))
			cn[1][i]++;
		else
			cn[0][i]++;
	for(auto u : adj[v])
		if(u!=par and !hide[u])
			calc(u , v , c ^ a[u]);
}

void solve(int v = 1){
	plant(v);
	v = cen(v,  sz[v]);
	hide[v] = 1;
	ms(cnt , 0);
	for(auto u : adj[v])if(!hide[u]){
		ms(cn , 0);
		calc(u , v , a[u]);
		for(int i = 0 ; i < lg ; i ++){
			if(a[v] & (1 << i))
				swap(cn[0][i] , cn[1][i]);
			ans += cn[1][i] * (1 << i);
			ans += cn[1][i] * cnt[0][i] * (1 << i);
			ans += cn[0][i] * cnt[1][i] * (1 << i);
			if(a[v] & (1 << i))
				swap(cn[0][i] , cn[1][i]);
			cnt[0][i] += cn[0][i];
			cnt[1][i] += cn[1][i];
		}
	}
	for(auto u : adj[v])
		if(!hide[u])
			solve(u);
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , ans += a[i];
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	solve();
	cout << ans;
    return(0);
}