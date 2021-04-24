//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , d[maxn] , par[maxn];
vector < pii > adj[maxn];
vector < int > src , nxt;
queue < int > q;
bool mark[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	ms(d , 63);
	d[0] = 0;
	q.push(0);
	while(q.size()){
		int v = q.front();
		q.pop();
		for(auto [u, w] : adj[v])
			if(d[u] == d[n])
				q.push(u) , d[u] = d[v]+1;
	}
	q.push(n-1);
	int mn = d[n-1];
	mark[n-1] = 1;
	while(q.size()){
		int v = q.front();
		q.pop();
		src.pb(v);
		for(auto [u, w] : adj[v])if(!mark[u] and !w)
			mark[u] = 1 , q.push(u) , mn = min(mn , d[u]) , par[u] = v;
	}
	bool zr = 1;
	for(; mn ; mn --){
		int e = 10;
		nxt.clear();
		for(auto v : src)
			for(auto [u , w] : adj[v])if(d[u] == mn - 1)
				e = min(e , w);
		if(e or mn == 1)zr = 0;
		if(!zr)cout << e;
		for(auto v : src)
			for(auto [u , w] : adj[v])if(d[u] == mn - 1 and w == e and !mark[u])
				mark[u] = 1 , nxt.pb(u) , par[u] = v;
		swap(nxt , src);
	}
	if(zr)cout << 0;
	cout << endl;
	nxt.clear();
	int cur = 0;
	while(cur != n-1){
		nxt.pb(cur);
		cur = par[cur];
	}
	nxt.pb(n-1);
	cout << (int)nxt.size() << endl;
	for(auto x : nxt)cout << x << ' ';
	return(0);
}
