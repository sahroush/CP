/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
vector < int > adj[maxn];
int sz[maxn];

int dfs(int v , int par = 0){
	int sub = 1;
	sz[v] = 0;
	for(auto u : adj[v]){
		if(u == par)continue;
		int res = dfs(u , v);
		sub += res;
		sz[v] = max(sz[v] , res);
	}
	sz[v] = max(sz[v] , n - sub);
	return(sub);
}

int32_t main(){
    migmig
	cin >> q;
	while(q --){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			adj[i].clear() , sz[i] = 0;
		for(int i = 1 ; i < n ; i ++){
			int u , v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		int mn = *min_element(sz + 1 , sz + n + 1);
		vector < int > vec;
		vec.clear();
		for(int i = 1 ; i <= n ; i ++){
			if(sz[i] == mn)
				vec.pb(i);
		}
		if(vec.size() == 1){
			cout << 1 << ' ' << adj[1][0] << endl;
			cout << 1 << ' ' << adj[1][0] << endl;
			continue;
		}
		int u = vec[0] , v = vec[1];
		int bz = u;
		for(auto x : adj[v])
			if(x!=u){
				u = x;
				break;
			}
		cout << v << ' ' << u << endl;
		cout << u << ' ' << bz << endl; 
	}
    return(0);
}