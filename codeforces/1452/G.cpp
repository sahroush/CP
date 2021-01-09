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

int n , k;
int a[maxn];
vector < int > adj[maxn];
int ans[maxn];
vector < pii > vec;
int d[maxn];
queue < int > q;

int dist[maxn];

void solve(int v , int D , int lim , int par = 0){
	if(dist[v] >= lim)
		return;
	dist[v] = max(dist[v] , lim);
	ans[v] = max(ans[v] , D);
	for(auto u : adj[v])if(u^par)
		solve(u , D , lim - 1 , v);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i < n ; i ++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cin >> k;
	for(int i = 1 ; i <= n ; i ++)
		d[i] = 1e9;
	for(int i = 1 ; i <= k ; i ++)
		cin >> a[i], d[a[i]] = 0, q.push(a[i]);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto u : adj[v])
			if(d[u] > d[v] + 1)
				d[u] = d[v] + 1, q.push(u);
	}
	for(int i = 1 ; i <= n ; i ++)
		vec.pb({d[i] , i});
	sort(vec.begin() , vec.end());
	reverse(vec.begin() , vec.end());
	for(auto [D , v] : vec)
		solve(v , D , D);
	for(int i = 1 ; i <= n ; i ++)
		cout << ans[i] << ' ';
    return(0);
}
