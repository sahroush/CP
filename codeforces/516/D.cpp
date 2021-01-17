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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 1e5 + 10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
vector < pii > adj[maxn];

pii find(int v = 1 , int par = 0){
	pii ans = {0 , v};
	for(auto [u , w] : adj[v])if(u != par){
		auto res = find(u , v);
		res.first += w;
		ans = max(ans , res);
	}
	return(ans);
}

int dist[maxn];

void solve(int v , int par = 0 , int d = 0){
	dist[v] = max(dist[v] , d);
	for(auto [u , w] : adj[v])if(u^par)
		solve(u , v , d + w);
}

pii srt[maxn];

int par[maxn] , sz[maxn] , cnt[maxn];

int getpar(int v){
	return((par[v]) ? par[v] = getpar(par[v]) : v);
}

int merge(int v , int u){
	u = getpar(u) , v = getpar(v);
	if(cnt[u] < cnt[v])swap(u , v);
	par[u] = v, cnt[v] += (cnt[v] == cnt[u]);
	sz[v] += sz[u];
	return(sz[v]);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[v].pb({u , w});
		adj[u].pb({v , w});
	}
	int r1 = find().second;
	int r2 = find(r1).second;
	solve(r1) , solve(r2);
	for(int i = 1 ; i <= n ; i ++)
		srt[i] = {-dist[i] , i};
	sort(srt + 1 , srt + n + 1);
	cin >> q;
	while(q --){
		int l;
		cin >> l;
		ms(par , 0) , ms(cnt , 0) , ms(sz , 0);
		int ans = 1;
		int p = 1;
		for(int i = 1 ; i <= n ; i ++){
			auto [d , v] = srt[i];
			sz[v] = 1;
			while(p <= n and d-srt[p].first > l)
				sz[getpar(srt[p].second)] -- , p ++;
			for(auto [u , w] : adj[v])
				if(sz[u])ans = max(ans ,merge(u , v));
		}
		cout << ans << endl;
	}
    return(0);
}
