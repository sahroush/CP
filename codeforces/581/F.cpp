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

const ll maxn  = 5100;
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
int sz[maxn];
int dp[maxn][maxn];

void dfs(int v , int par = 0){
	if(adj[v].size() == 1)
		sz[v] = 1;
	for(auto u : adj[v])if(u!=par)
		dfs(u , v) , sz[v] += sz[u];
	for(auto u : adj[v])if(u!=par)
		for(int i = sz[v] ; i ; i --)
			for(int j = 0 ; j <= min(i , sz[u]) ; j++)
				dp[v][i] = min(dp[v][i] , dp[u][j] + dp[v][i - j]);
	for(int i = 0 ; i <= sz[v] ; i ++)
		dp[v][sz[v] - i] = min(dp[v][i] + 1, dp[v][sz[v] - i]);
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
	for(int i = 0 ; i < maxn ; i ++)for(int j = 1 ; j < maxn ; j ++)dp[i][j] = 1e9;
	int v = 0 , cnt = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(adj[i].size() == 1)cnt++;
		else v = i;
	}
	dfs(v);
	cout << dp[v][cnt/2];
    return(0);
}
