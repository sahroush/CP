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

const ll maxn  = 1e6+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;

map < int , int > mp[maxn];
int h[maxn] , ans[maxn];

vector < int > adj[maxn];

void dfs(int v = 1 , int par = 0){
	for(int u : adj[v])if(u!=par)h[u]=h[v]+1 , dfs(u , v);
}

void merge(int u , int v){
	if(mp[u].size() > mp[v].size())swap(mp[u] , mp[v]) , ans[v] = ans[u];
	for(auto [f , s] : mp[u]){
		mp[v][f] += s;
		if(mp[v][f] > mp[v][ans[v]])ans[v] = f;
		if(mp[v][f] == mp[v][ans[v]])ans[v] = min(ans[v] , f);
	}
}

void solve(int v = 1 , int par = 0){
	mp[v][h[v]] = 1 , ans[v] = h[v];
	for(auto u : adj[v])if(u!=par)solve(u , v) , merge(u , v);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++ ){
		int u , v; cin >> u >> v;
		adj[u].pb(v) , adj[v].pb(u);
	}
	dfs();
	solve();
	for(int i = 1 ; i <= n ; i ++) cout << ans[i] - h[i] << endl;
    return(0);
}
