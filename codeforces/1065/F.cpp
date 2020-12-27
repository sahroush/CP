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

const ll maxn  = 1e6 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
vector < int > ch[maxn];
vector < int > out[maxn] , in[maxn] , topo;
const int lg = 22;
int par[25][maxn];
int col[maxn];
int c = 0;
int h[maxn];

void dfs(int v = 1){
	for(auto u : ch[v])
		par[0][u] = v , h[u] = h[v] + 1, dfs(u) , out[v].pb(u) , in[u].pb(v);
}

int get(int v , int h){
	for(int i = lg ; i >= 0 ; i --)
		if((1 << i)&h)
			v = par[i][v];
	return(v);
}	

void sfd(int v){
	col[v] = c;
	for(auto u : in[v]) if(!col[u])
		sfd(u);
}
void Dfs(int v){
	col[v] = 1;
	for(auto u : out[v]) if(!col[u])
		Dfs(u);
	topo.pb(v);
}

int sz[maxn];
int p[maxn];

int getpar(int v){
	return((0 == p[v]) ? v : p[v] = getpar(p[v]));
}

void merge(int u , int v){
	if((u = getpar(u)) == (v = getpar(v)))return;
	p[u] = v;
	sz[v]+=sz[u];
}

int mx[maxn];

int ans[maxn];
 
int solve(int v){
	if(ans[getpar(v)]!=-1)return(ans[getpar(v)]);
	ans[getpar(v)] = sz[getpar(v)];
	int mx = 0;
	for(auto u : ch[v])
		if(getpar(u)!=getpar(v))
			mx = max(mx , solve(getpar(u)));
	ans[getpar(v)] += mx;
	return(ans[getpar(v)]);
}

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 2; i <= n ; i ++){
		int p;
		cin >> p;
		ch[p].pb(i);
	}
	dfs();
	for(int i = 1 ; i <=lg ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			par[i][j] = par[i - 1][par[i - 1][j]];
	for(int i = 2 ; i <= n ; i ++)
		if(ch[i].size() == 0)
			out[i].pb(get(i , min(k , h[i]))),
			in[get(i , min(k , h[i]))].pb(i),
			sz[i]++;
	for(int i = 1 ; i <= n ; i ++ ) if(!col[i]) Dfs(i);
		reverse(topo.begin() , topo.end());
		ms(col , 0);
		for(auto v : topo)
			if(!col[v])
				++c , sfd(v);
	for(int v = 2 ; v <= n ; v ++)	
		if(col[v] == col[par[0][v]])
			merge(v , par[0][v]);
	for(int i = 1 ; i <= n ; i ++)ch[i].clear();
	for(int i = 1 ; i <= n ; i ++)
		for(auto u : out[i])
			if(getpar(u) != getpar(i))
				ch[getpar(i)].pb(getpar(u));
	ms(ans , -1);
	solve(getpar(1));
	for(int i = 1 ; i <= n ; i ++)mx[i] = sz[i];
	for(int i = n-1 ; i ; i --)	
		for(auto u : ch[getpar(i)])
			mx[getpar(i)] = max(mx[getpar(i)] , sz[getpar(i)] + mx[u]);
	cout << max(mx[getpar(1)] , ans[getpar(1)]);
    return(0);
}
