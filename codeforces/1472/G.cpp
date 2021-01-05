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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , m;
vector < int > adj[maxn];
int h[maxn];
int mn[maxn];
bool mark[maxn];

void dfs(int v){
	mn[v] = h[v];
	mark[v] = 1;
	for(auto u : adj[v]){
		if(h[u] > h[v]){
			if(!mark[u])dfs(u);
			mn[v] = min(mn[v] , mn[u]);
		}
		else{
			mn[v] = min(mn[v] , h[u]);
		}
	}
}	

queue < int > t;

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			mn[i] = 1e9;
		for(int i = 1 ; i <= n ; i ++)
			adj[i].clear() , mark[i] = 0;
		for(int i = 1 ; i <= m ; i ++){
			int u , v;
			cin >> u >> v;
			adj[u].pb(v);
		}
		t.push(1);
		mark[1] = 1;
		while(!t.empty()){
			int v = t.front();
			t.pop();
			for(auto u : adj[v]){
				if(!mark[u])
					mark[u] = 1, t.push(u) , h[u] = h[v] + 1;
			}
		}
		for(int i = 1 ; i <= n ; i ++)
			mark[i] = 0;
		dfs(1);
		for(int i = 1 ; i <= n ; i ++)
			cout << mn[i] << ' ';
		cout << endl;
	}




    return(0);
}