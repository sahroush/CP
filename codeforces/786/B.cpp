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
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 4e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q , s;
vector < pii > adj[maxn * 4];
ll dist[maxn * 4];

const ll inf = 1e18;

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void build(int v = 1, int l = 1 , int r = n+1){
	for(int i = l ; i < r ; i ++)
		adj[i + maxn*3].pb({v + maxn , 0}),
		adj[v].pb({i+maxn*3 , 0});
	if(r - l == 1){
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
}

void go(int x ,ll w, int L , int R , int v = 1 , int l = 1  , int r = n + 1){
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		adj[x+maxn*3].pb({v , w});
		return;
	}
	go(x , w , L , R , lc , l , mid);
	go(x , w , L , R , rc , mid , r);
}

void send(int x ,ll w, int L , int R , int v = 1 , int l = 1  , int r = n + 1){
	if(r <= L or R <= l)
		return;
	if(L <= l and r <= R){
		adj[v+maxn].pb({x+maxn*3 , w});
		return;
	}
	send(x , w , L , R , lc , l , mid);
	send(x , w , L , R , rc , mid , r);
}

bool mark[maxn*4];

priority_queue < pii > pq;

void djk(int s){
	dist[s] = 0;
	pq.push({-dist[s] , s});
	while(pq.size()){
		auto [d , v] = pq.top();
		pq.pop();
		if(mark[v])continue;
		mark[v] = 1;
		for(auto [u , w] : adj[v])
			if(dist[u] > dist[v] + w)
				dist[u] = dist[v] + w , pq.push({-dist[u] , u});
	}
}

int32_t main(){
    migmig;
	cin >> n >> q >> s;
	for(int i = 1 ; i < maxn*4 ; i ++) dist[i] = inf;
	build();
	while(q -- ){
		int t , v , u , l , r;
		ll w;
		cin >> t;
		if(t == 1){
			cin >> u >> v >> w;
			adj[u + maxn * 3].pb({v + maxn*3 , w});
		}
		if(t == 2){
			cin >> v >> l >> r >> w;
			go(v , w,  l , r+1);
		}
		if(t == 3){
			cin >> v >> l >> r >> w;
			send(v , w, l , r+1);
		}
	}
	djk(s + maxn*3);
	for(int i = 1 ; i <= n ; i ++)
		cout << ((dist[i + maxn * 3] == inf) ? -1 : dist[i + maxn * 3]) << ' ';
    return(0);
}

