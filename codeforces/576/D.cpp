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

const ll maxn = 155;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;

vector < pii > g[maxn];

struct edg{
	int u , v , d;
	void inp(){
		cin >> u >> v >> d;
		g[u].pb({v , d});
	}
	friend bool operator < (edg a , edg b){
		return(a.d < b.d);
	}
};
vector < edg > e(maxn);

struct matrix{
	bitset < maxn > m[maxn];
	friend matrix operator * (matrix a , matrix b){
		matrix c;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = a.m[i]._Find_first() ; j < maxn ; j = a.m[i]._Find_next(j))
				if(a.m[i][j])
					c.m[i] |= b.m[j];
		return(c);
	}
	friend matrix operator ^ (matrix a , int x){
		matrix res;
		for(int i = 1 ; i <= n ; i ++)res.m[i][i] = 1;
		while(x){
			if(x&1)
				res = res * a;
			a = a * a;
			x = x>>1;
		}
		return(res);
	}
};

matrix adj , cur;

const int inf = 2e9;

queue < int > q;

int dist[maxn];

int solve(int x){
	ms(dist , 0);
	for(int i = 1 ; i <= n ; i ++)
		if(cur.m[1][i])
			dist[i] = 1, q.push(i);
	while(q.size()){
		int v = q.front();
		q.pop();
		for(auto [u , w] : g[v]){
			if(w > x or dist[u])continue;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	return((dist[n] == 0) ? inf : dist[n] + x - 1);
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++)
		e[i].inp();
	sort(e.begin() , e.begin() + m);
	for(int i = 1 ; i <= n ; i ++)cur.m[i][i] = 1;
	int ans = inf;
	int lst = 0;
	for(int i = 0 ; i < m ; i ++){
		cur = cur * (adj ^ (e[i].d - lst));
		lst = e[i].d;
		ans = min(ans , solve(e[i].d));
		adj.m[e[i].u][e[i].v] = 1;
	}
	if(ans == inf)dokme("Impossible");
	cout << ans;
    return(0);
}
