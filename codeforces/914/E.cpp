//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e6 + 1e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];
ll ans[maxn];
int a[maxn];
ll sum[maxn];
int cnt[maxn];
int sz[maxn] , hide[maxn];

void plant(int v , int par = 0){
	sz[v] = 1;
	for(auto u : adj[v]) if(u != par and !hide[u])
		plant(u , v) , sz[v] += sz[u];
}

int cen(int v , int n , int par = 0 , bool found = 0){
	while(!found){
		found = 1;
		for(auto u : adj[v]) if(u!=par and !hide[u] and sz[u] * 2 > n){
			par = v , v = u , found = 0;
			break;
		}
	}
	return(v);
}

void calc(int v , int par , int c = 0){
	if(hide[v])return;
	c^=a[v];
	for(int i = 0 ; i < 20 ; i ++)
		sum[v] += cnt[c^(1 << i)];
	sum[v] += cnt[c];
	for(auto u : adj[v])if(u!=par)
		calc(u , v , c);
	ans[v] += sum[v];
	sum[par]+=sum[v];
	sum[v] = 0;
}

void add(int v , int par ,  int c){
	if(hide[v])return;
	c^=a[v] , cnt[c]++;
	for(auto u : adj[v])
		if(u!=par)
			add(u , v , c);
}

void rem(int v , int par ,  int c){
	if(hide[v])return;
	c^=a[v] , cnt[c]--;
	for(auto u : adj[v])
		if(u!=par)
			rem(u , v , c);
}

void calc(int v){
	for(auto u : adj[v])
		add(u , v , a[v]);
	for(auto u : adj[v])
		rem(u , v , a[v]) , calc(u , v) , add(u , v , a[v]);
	for(auto u : adj[v])
		rem(u , v , a[v]);
	ans[v] += sum[v]/2;
	sum[v] = 0;
	cnt[a[v]]++;
	for(auto u : adj[v])
		calc(u , v);
	ans[v] += sum[v];
	cnt[a[v]]--;
}

void solve(int v){
	plant(v);
	v = cen(v , sz[v]);
	hide[v] = 1;
	calc(v);
	for(auto u : adj[v])
		if(!hide[u])
			solve(u);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	string s;
	cin >> s;
	for(int i = 1 ; i <= n ; i ++){
		a[i] = s[i - 1] - 'a';
		a[i] = (1 << a[i]);
	}
	solve(1);	
	for(int i = 1 ; i <= n ; i ++)
		cout << ans[i] + 1 << ' ';
    return(0);
}
