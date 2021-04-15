//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e5 +10;
const ll mod = 998244353;//Bruh

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];
int dp[maxn][3] , mrg[3];

void dfs(int v = 1 , int par = 0){
	dp[v][0] = 1;
	for(auto u : adj[v])if(u ^ par){
		dfs(u , v);
		mrg[0] = 1LL * dp[v][0] * ((dp[u][0] + dp[u][2]) % mod) % mod;
		mrg[1] = (1LL * dp[v][0] * dp[u][2] % mod + 1LL * dp[v][1] * ((dp[u][0] + 2LL * dp[u][2] % mod) % mod) % mod) % mod;
		mrg[2] = (1LL * dp[v][0] * (dp[u][0] + dp[u][1]) % mod + 1LL * dp[v][1] * (dp[u][0] + dp[u][1]) % mod + 1LL * dp[v][2] * ((dp[u][0] + 2LL * dp[u][2] % mod) % mod) % mod) % mod;
		swap(dp[v] , mrg);
	}
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs();
	cout << ((dp[1][0] + dp[1][2])%mod);
	return(0);
}
