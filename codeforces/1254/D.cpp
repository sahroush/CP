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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5;
const int mod = 998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int fen[maxn];

void add(int pos , int x){
	for( ; pos < maxn ; pos += pos & -pos)
		fen[pos] = (fen[pos] + x)%mod;
}

void add(int l , int r , int x){
	add(l , x) , add(r + 1 , mod-x);
}

int query(int pos){
	int ans = 0;
	for( ; pos ; pos -= pos & -pos)
		ans = (ans + fen[pos])%mod;
	return(ans);
}

int n , q;
vector < int > adj[maxn];
int sz[maxn];

int l[maxn] , r[maxn] , ti  = 0;

void dfs(int v = 1 , int par = 0){
	sz[v] = 1;
	if(par)adj[v].erase(find(adj[v].begin() , adj[v].end() , par));
	for(auto u : adj[v])
		dfs(u , v) , sz[v] += sz[u];
	sort(adj[v].begin() , adj[v].end() , [](int i , int j){return(sz[i] < sz[j]);});
}

vector < pair < int , pii > > Adj[maxn];

void pre(int v = 1){
	l[v] = ++ti;
	for(auto u : adj[v])pre(u);
	for(int i = 0 , j ;  i < (int)adj[v].size() ; i = j){
		for(j = i + 1 ; j < int(adj[v].size()) and sz[adj[v][i]] == sz[adj[v][j]] ; j++);
		Adj[v].pb({sz[adj[v][i]] , pii(l[adj[v][i]] , r[adj[v][j - 1]])});
	}
	r[v] = ti;
}

int sum[maxn];

int32_t main(){
    migmig;
	cin >> n >> q;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v) , adj[v].pb(u);
	}
	dfs();
	pre();
	const int inv = pw(n , mod - 2);
	while(q -- ){
		int t;
		cin >> t;
		if(t == 1){
			int v , d;
			cin >> v >> d;
			int p = (1LL * d * sz[v])%mod;
			add(1 , ti , p);
			add(l[v] , r[v] , mod - p);
			for(auto [f , s] : Adj[v])
				add(s.first , s.second , ((1LL * n - f) * d )%mod);
			sum[v] = (sum[v] + d)%mod;
		}
		else{
			int v;
			cin >> v;
			int ans = query(l[v]);
			ans = (1LL * ans * inv)%mod;
			ans = (ans + sum[v])%mod;
			cout << ans << endl;
		}
		
	}
    return(0);
}
