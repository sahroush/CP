/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5+100;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;

int h[maxn];

vector < int > adj[maxn];
int a[maxn];
int b[maxn];
int dp[maxn][2];
vector < int > col[maxn];

int par[maxn];

void dfass(int v = 1){
	dp[v][1] = 1;
	for(auto u : adj[v]) if(u!=par[v])
		dfass(u) , dp[v][1] = (dp[v][1] * 1LL * (dp[u][0] + dp[u][1])%mod)%mod;
	if(b[v]){swap(dp[v][0], dp[v][1]);return;}
	for(auto u : adj[v]) if(u!=par[v])
		dp[v][0] = (dp[v][0] + (((dp[v][1] * 1LL * pw(dp[u][0] + dp[u][1] , mod - 2))%mod) * dp[u][0])% mod)%mod;
}

void dfs(int v = 1){
	for(auto u : adj[v])if(u!=par[v])
		par[u] = v , h[u] = h[v] + 1, dfs(u);
}

int up[maxn];

void color(int v , int c){
	if(b[v] and b[v]!=c)dokme(0);
	b[v] = c;
}	

void solve(int v , int c){
	int &u = up[c];
	if(u == 0){u = v , color(v , c);return;}
	while(h[v] > h[u]){
		if(b[v] == c){v = u ; break;}
		color(v , c) , v = par[v];
	}
	while(u!=v){
		color(v , c) , color(u , c);
		u = par[u] , v = par[v];
	}
	color(u , c);
}

bool cmp(int a , int b){return(h[a] < h[b]);}

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , col[a[i]].pb(i);
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v) , adj[v].pb(u);
	}
	dfs();
	for(int i = 1 ; i <= k ; i ++){
		sort(col[i].begin() , col[i].end() , cmp);
		for(auto v : col[i])
			solve(v , i);
	}
	dfass();
	cout << dp[1][0];
    return(0);
}
