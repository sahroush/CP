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
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int m;
vector < pii > adj[maxn];

const ll inf = 1e18;

ll dist[maxn];

priority_queue < pii > q;

bool mark[maxn];

int32_t main(){
	migmig;
	cin >> n >> m;
	for(int i = 2 ; i <= n ; i ++)
		dist[i] = inf;
	for(int i = 1 ; i <= m ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	q.push({-dist[1] , 1});
	while(q.size()){
		auto [d , v] = q.top();
		q.pop();
		d = -d;
		if(mark[v])continue;
		mark[v] = 1;
		for(auto [u1 , w1] : adj[v]){
			for(auto [u , w2] : adj[u1]){
				if(dist[u] > d + (w1 + w2)*(w1 + w2))
					dist[u] = d + (w1 + w2) * (w1 + w2) , q.push({-dist[u] , u});
			}
		}
		
	}
	for(int i = 1 ; i <= n ; i ++)
		cout << ((dist[i] == inf) ? -1 : dist[i]) << ' ';
	return(0);
}
