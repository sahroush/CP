/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 100;
const ll mod = 998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < int > in[maxn][2];
int dp[2][maxn];
vector < int > adj[maxn<<2][2];
deque < int > dq;

#define f(x , y) (y + maxn*x)
pii uf(int x){if(x >= maxn)return pii(1 , x - maxn);return pii(0 , x);}

struct tr{
	int a , b , c;
};

deque < tr > dick;

int dist[maxn][2][20];

pii mn(pii a , pii b){
	if(a < b)swap(a , b);
	if(a.first > 20 or a.first == b.first)
		return b;
	return (((1 << a.first) + a.second < (1 << b.first) + b.second) ? a : b);
}

int32_t main(){
	migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++){
		int u , v;
		cin >> u >> v;
		in[u][0].pb(v);
		in[v][1].pb(u);
		adj[f(0 , u)][0].pb(f(0 , v));
		adj[f(1 , v)][0].pb(f(1 , u));
	}
	for(int i = 1 ; i <= n ; i ++)adj[f(0 , i)][1].pb(f(1 , i)) , adj[f(1 , i)][1].pb(f(0 , i));
	ms(dp , 63);
	dp[0][1] = 0;
	dq.pb(f(0 , 1));
	while(!dq.empty()){
		auto [p , v] = uf(dq.front());
		dq.pop_front();
		for(auto nei : adj[f(p , v)][0]){
			auto [np, u] = uf(nei);
			if(dp[np][u] <= dp[p][v])continue;
			dp[np][u] = dp[p][v];
			dq.push_front(f(np , u));
		}
		for(auto nei : adj[f(p , v)][1]){
			auto [np, u] = uf(nei);
			if(dp[np][u] <= dp[p][v] + 1)continue;
			dp[np][u] = dp[p][v] + 1;
			dq.pb(f(np , u));
		}
	}
	dick.pb({1 , 0 , 0});
	ms(dist , 63);
	dist[1][0][0] = 0;
	while(dick.size()){
		auto v = dick.front();dick.pop_front();
		int x = 1-v.b , y =  v.c + dp[v.b][v.a] - dp[x][v.a]+1;
		if(y < 20 and y >= 0 and dist[v.a][x][y] > dist[v.a][v.b][v.c])
			dist[v.a][x][y] = dist[v.a][v.b][v.c],
			dick.push_front({v.a , x , y});
		for(auto u : in[v.a][v.b])
			if((y = v.c + dp[v.b][v.a] - dp[v.b][u]) < 20 and y >= 0 and dist[u][v.b][y] > dist[v.a][v.b][v.c] + 1)
				dist[u][v.b][y] = dist[v.a][v.b][v.c] + 1 , dick.pb({u , v.b , y});
	}
	pii ans = {1e10 , 1e10};
	for(int i = 0 ; i < 2 ; i ++)
		for(int j = 0 ; j < 20 ; j ++)if(dist[n][i][j]^-1)
			ans = mn(ans , pii(dp[i][n] + j, dist[n][i][j]));
	cout << (pw(2 , ans.first) + ans.second-1)%mod;
	return(0);
}
