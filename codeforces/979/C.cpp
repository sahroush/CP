//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int s , t;
vector < int > adj[maxn];
int szx[maxn] , szy[maxn];

void dfs(int v , int *sz , int p = 0){
	sz[v] = 1;
	for(auto u : adj[v])if(u ^ p)
		dfs(u , sz , v) , sz[v] += sz[u];
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> s >> t;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans = n * 1ll * (n-1);
	dfs(t , szx);
	int a = szx[s];
	dfs(s , szy);
	int b = szy[t];
	ans = ans - 1ll * a * b;
	cout << ans;
	return(0);
}
