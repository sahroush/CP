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

int n;
vector < int > adj[maxn];

int ans[maxn] , sz[maxn];
int hide[maxn];

void plant(int v, int par = 0){
	sz[v] = 1;
	for(auto u : adj[v]) if(u!=par and !hide[u])
		plant(u , v) , sz[v] += sz[u];
}

int cen(int v , int n , int par = 0){
	bool found = 0;
	while(!found){
		found = 1;
		for(auto u : adj[v])
			if(!hide[u] and u != par and sz[u] * 2 > n){
				par = v;
				v = u;
				found = 0;
				break;
			}
	}
	return(v);
}	

void solve(int v = 1 ,int h = 0){
	plant(v);
	v = cen(v , sz[v]);
	hide[v] = 1;
	ans[v] = h;
	for(auto u : adj[v])
		if(!hide[u])
			solve(u , h + 1);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	solve();
	for(int i = 1 ; i <= n ; i ++)
		cout << char('A' + ans[i]) << ' ';
    return(0);
}