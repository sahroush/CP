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

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
vector < pii > adj[maxn];

int par[20][maxn];
int h[maxn] , H[maxn];
int srt[maxn] , t = 0;

void dfs(int v = 1 ,int p = 0){
	srt[v] = ++t , par[0][v] = p;
	for(auto [u , w] : adj[v])
		if(u!=p)
			H[u] = H[v] + w , h[u] = h[v] + 1 , dfs(u , v);
}

int lca(int u , int v){
	if(h[v] < h[u])
		swap(u , v);
	for(int i = 19 ; i >= 0 ; i --)
		if(par[i][v] and h[par[i][v]] >= h[u])
			v = par[i][v];
	if(u == v)return(v);
	for(int i = 19 ; i >= 0 ; i --)
		if(par[i][v] != par[i][u])
			u = par[i][u] , v = par[i][v];
	return(par[0][v]);
}

int dist (int u , int v){
	return(H[v] + H[u] - 2*H[lca(u , v)]);
}


struct ant{
	int v;
	ant(int x):
		v(x){}
	friend bool operator < (ant a , ant b){
		return(srt[a.v] < srt[b.v]);
	}
};

set < ant > st;

int ans = 0;

void add(int v){
	if(st.empty()){st.insert(v);return;}
	int res = 0;
	auto it = st.lower_bound(v);
	int r = ((it == st.end()) ? (st.begin())->v : it->v);
	int l = ((it == st.begin()) ? (st.rbegin())->v : (--it)->v);
	res = dist(v , l) + dist(v , r) - dist(l , r);
	ans += res/2;
	st.insert(v);
} 

void rem(int v){
	st.erase(v);
	if(st.empty())return;
	int res = 0;
	auto it = st.lower_bound(v);
	int r = ((it == st.end()) ? (st.begin())->v : it->v);
	int l = ((it == st.begin()) ? (st.rbegin())->v : (--it)->v);
	res = dist(v , l) + dist(v , r) - dist(l , r);
	ans -= res/2;
}

int q;


int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	dfs();
	for(int i = 1 ; i < 20 ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			par[i][j] = par[i-1][par[i-1][j]];
	cin >> q;
	while(q -- ){
		char t;
		int v;
		cin >> t;
		if(t == '?'){
			cout << ans << endl;
			continue;
		}
		cin >> v;
		if(t == '+')add(v);
		else rem(v);
	}	
    return(0);
}
