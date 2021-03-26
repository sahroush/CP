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

const int maxn = 5e5 + 10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int lg = 20;
vector < int > adj[maxn];
int n , root;
ll a[maxn];
int par[lg+1][maxn];
ll ans = 0;

void dfs(int v){
	for(auto u : adj[v])if(u ^ par[0][v])
		par[0][u] = v , dfs(u);
}

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	root = min_element(a + 1 , a + n + 1) - a;
	a[0] = a[root];
	dfs(root);
	for(int i = 1 ; i <= lg ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			par[i][j] = par[i - 1][par[i - 1][j]];
	for(int i = 1 ; i <= n ; i ++)if(i^root){
		ll mn = a[par[0][i]] + a[i];
		for(int j = 1 ; j <= lg ; j ++)
			mn = min(mn , a[i] + a[par[j][i]] + a[par[j][i]] * (j));
		ans += mn;
	}
	cout << ans;
	return(0);
}
