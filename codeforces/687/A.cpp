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

int n ,m ;
vector < int > adj[maxn];
int mark[maxn];

void dfs(int v){
	if(!mark[v])mark[v] = 1;
	for(auto u : adj[v]){
		if(!mark[u])
			mark[u] = ((mark[v] == 1) ? 2 : 1) , dfs(u);
		if(mark[u] == mark[v])dokme(-1);
	}
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0; i  < m ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1 ; i <= n ; i ++)if(!mark[i])dfs(i);
	int cnt = 0 ;
	for(int i = 1 ;i <= n ; i ++ )	
		cnt += mark[i] == 1;
	cout << cnt << endl;
	for(int i = 1 ; i <= n ; i ++)
		if(mark[i] == 1)
			cout << i << ' ';
	cout << endl;
	cout << n - cnt << endl;
	for(int i = 1 ; i <= n ; i ++)
		if(mark[i] != 1)
			cout << i << ' ';


    return(0);
}
