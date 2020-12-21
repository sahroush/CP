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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < pair < pii , int > > e;
vector < int > adj[maxn] , ans;
int mark[maxn];
int h[maxn] , par[maxn];
int a[maxn] , prt[maxn];
int sum[maxn];
vector < int > ord;

void dfs(int v){
	ord.pb(v) , mark[v] = 1;
	for(auto u : adj[v])if(!mark[u])
		par[u] = v , h[u] = h[v] + 1 , dfs(u);
}

void calc(int v){
	mark[v] = 2;
	prt[v] = a[v];
	for(auto u : adj[v])if(mark[u]!=2)
		calc(u) , prt[v] += prt[u];
}

void hentai(int v){
	mark[v] = 3;
	for(auto u : adj[v])if(mark[u]!=3)
		sum[u] = prt[u] + sum[v] , hentai(u);
}

bool can[maxn];

int ed(int u , int v){
	if(u > v)swap(u , v);
	if(u == 0)return(0);
	return((*lower_bound(e.begin() , e.end() , pair < pii , int  > (pii(u , v) , 0))).second);
}

void solve(int v){
	ord.clear();
	dfs(v);
	for(auto v : ord){
		for(auto u : adj[v]){
			if(h[u] < h[v] and u!=par[v])
				a[v] ++ , a[u] -- ;
		}
	}
	calc(v);
	hentai(v);
	for(auto v : ord){
		for(auto u : adj[v]){
			if(h[u] < h[v] and u!=par[v]){
				if(sum[v] - sum[u] > h[v] - h[u])
					a[v] -= 1e6 , a[u] += 1e6 , can[ed(u , v)] = 0;
			}
		}
	}
	calc(v);
	for(auto v : ord)
		if(prt[v]!= 1)can[ed(v , par[v])] = 0;
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++){
		int u , v;
		cin >> u >> v;
		if(u > v)swap(u , v);
		adj[u].pb(v);
		adj[v].pb(u);
		e.pb({{u , v} , i});
	}
	for(int i = 1; i <= m ; i ++)can[i] = 1;
	sort(e.begin() , e.end());
	for(int i = 1 ; i <= n ; i ++) if(!mark[i])solve(i);
	for(int i = 1 ; i <= m ; i ++) if(can[i])ans.pb(i);
	cout << ans.size() << endl;
	for(int i : ans)
		cout << i << ' ';
    return(0);
}
