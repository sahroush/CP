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

int cnt[maxn];
int cur = 0;
int h[maxn] , ans[maxn];
int sz[maxn];
vector < int > adj[maxn] , Adj[maxn];
int ord[maxn] , t = 0;

bool mark[maxn];
bool vis[maxn];
vector < int > vec;

void dfs(int v = 1 , int par = 0){
	sz[v] = 1 , ord[++t] = v;
	for(int u : Adj[v])if(u!=par)adj[v].pb(u) , h[u]=h[v]+1 , dfs(u , v) , sz[v] += sz[u];
}

bool cmp(int a , int b){
	return(sz[a] > sz[b]);
}

void ins(int v){
	cnt[h[v]]++;
	if(cnt[h[v]] > cnt[cur])cur = h[v];
	if(cnt[h[v]] == cnt[cur] and cur > h[v])cur = h[v];
	if(!vis[h[v]])vis[h[v]] = 1 , vec.pb(h[v]);
}

void add(int v){
	ins(v);
	for(auto u : adj[v])
		add(u);
}

void solve(int v){
	if(mark[v])return;
	mark[v] = 1;
	auto &adj = ::adj[v];
	int d = adj.size();
	if(d == 0){ins(v) , ans[v] = cur;return;}
	solve(adj[0]);
	for(int i = 1 ; i < d ; i ++)
		add(adj[i]);
	ins(v);
	ans[v] = cur;
}

void clean(){
	for(int x : vec)
		cnt[x] = 0 , vis[x] = 0;
	vec.clear();
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++ ){
		int u , v; cin >> u >> v;
		Adj[u].pb(v) , Adj[v].pb(u);
	}
	dfs();
	for(int i = 1 ; i <= n ; i ++)sort(adj[i].begin() , adj[i].end() , cmp);
	for(int i = 1 ; i <= n ; i ++)solve(ord[i]) , clean();
	for(int i = 1 ; i <= n ; i ++) cout << ans[i] - h[i] << endl;
    return(0);
}
