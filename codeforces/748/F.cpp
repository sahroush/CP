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

int n , k;

vector < int > adj[maxn];
int l[maxn]  , r[maxn] , t = 0;

vector < int > red;

void dfs(int v = 1 , int pr = 0){
	l[v] = r[v] = ++t;
	for(int u : adj[v])if(u!=pr)
		dfs(u , v) , r[v] = r[u];
}

bool cmp(int v , int u){
	return(l[v] < l[u]);
}

bool mark[maxn];

int root = 0;

int sz[maxn];

void dfass(int v = 1 , int pr = 0){
	l[v] = r[v] = ++t;
	for(int u : adj[v])if(u!=pr)
		dfass(u , v) , r[v] = r[u] , sz[v] += sz[u];
}

int find_root(){
	dfass();
	int n = sz[1];
	int v = 1;
	bool found = 0;
	int par = 0;
	while(!found){
		found = 1;
		for(int u : adj[v])if(u!=par and sz[u] * 2 > n){
			found = 0 , par = v , v = u;
			break;
		}
	}
	return(v);
}

int32_t main(){
    migmig;
	cin >> n >> k;
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	red.resize(2*k);
	for(int i = 0 ; i < 2*k ; i ++)
		cin >> red[i] , sz[red[i]]++;
	root = find_root();
	t = 0;
	dfs(root);
	sort(red.begin() , red.end() , cmp);
	cout << 1 << endl;
	cout << root << endl;
	for(int i = 0 ; i < k ; i ++)
		cout << red[i] << ' ' << red[i + k] << ' ' << root << endl;
    return(0);
}
