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

const ll maxn  = 5e4 + 10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct sat{
	int n, c;
	vector < vector < int > > in , out;
	vector < int > col , topo;
	sat(int N):
		n(N) , c(0) , in(2*n + 5) , out(2*n + 5) , col(2*n + 5){}
	bool operator [] (int x) { return(col[2*x] > col[2*x + 1]); }
	void add_e(int v , int u){in[u].pb(v) , out[v].pb(u);}
	void add(int v , int u){add_e(u^1 , v) , add_e(v^1 , u);}
	void sfd(int v){
		col[v] = c;
		for(auto u : in[v]) if(!col[u])
			sfd(u);
	}
	void dfs(int v){
		col[v] = 1;
		for(auto u : out[v]) if(!col[u])
			dfs(u);
		topo.pb(v);
	}
	bool validate(){
		for(int i = 1 ; i <= 2*n+1 ; i ++ ) if(!col[i]) dfs(i);
		reverse(topo.begin() , topo.end());
		fill(col.begin() , col.end() , 0 );
		for(auto v : topo)
			if(!col[v])
				++c , sfd(v);
		for(int i = 1 ; i <= n ; i ++) if(col[i * 2] == col[i * 2 + 1])return(0);
	return(1);
	}
};
int n , m;

struct ed{
	int u , v , c , t , id;
};

vector < ed > e;

bool cmp(ed a  , ed  b){
	return(a.t < b.t);
}	

int dup[maxn];
map < int , int > mp[maxn];
vector < pii > adj[maxn];

bool chk(int x){
	sat g(3 * m);
	int cur = m;
	for(int i = 1 ; i <= n ; i ++){
		int k = 1;
		vector < int > vec;
		for(auto [u , j] : adj[i]){
			++ cur;
			if(k > 1)
				g.add((cur - 1) * 2 + 1 , cur * 2),
				g.add((j + 1)*2 + 1 , (cur - 1) * 2 + 1);
			if(e[j].c == dup[i] and j < x)vec.pb(j+1);
			g.add((j + 1) * 2 + 1 , cur * 2);
			k++;
		}
		if(vec.size() == 0)continue;
		if(vec.size() == 1){
			int x = vec[0];
			g.add(x*2 , x*2);
		}
		if(vec.size() == 2){
			int x = vec[0];
			int X = vec[1];
			g.add(X*2 , x*2);
			g.add(X*2 + 1 , x*2 + 1);
		}
	}
	for(int i = x+1 ; i <= m ; i ++)
		g.add(i*2 + 1 , i*2 + 1);
	if(!g.validate())return(0);
	for(int i = 1 ; i <= n ; i ++){
		if(!dup[i])continue;
		bool ok = 0;
		for(auto[u , j] : adj[i])
			if(e[j].c == dup[i] and g[j+1])ok = 1;
		if(!ok)return(0);
	}
	return(1);
}

void solve(int x){
	if(x == 0)
		dokme("0 0");
	sat g(3 * m);
	int cur = m;
	for(int i = 1 ; i <= n ; i ++){
		int k = 1;
		vector < int > vec;
		for(auto [u , j] : adj[i]){
			++ cur;
			if(k > 1)
				g.add((cur - 1) * 2 + 1 , cur * 2),
				g.add((j + 1)*2 + 1 , (cur - 1) * 2 + 1);
			if(e[j].c == dup[i] and j < x)vec.pb(j+1);
			g.add((j + 1) * 2 + 1 , cur * 2);
			k++;
		}
		if(vec.size() == 0)continue;
		if(vec.size() == 1){
			int x = vec[0];
			g.add(x*2 , x*2);
		}
		if(vec.size() == 2){
			int x = vec[0];
			int X = vec[1];
			g.add(X*2 , x*2);
			g.add(X*2 + 1 , x*2 + 1);
		}
	}
	for(int i = x+1 ; i <= m ; i ++)
		g.add(i*2 + 1 , i*2 + 1);
	g.validate();
	vector < int > ans;
	for(int i = 1 ; i <= m ; i ++)
		if(g[i])ans.pb(e[i-1].id);
	cout << e[x-1].t << ' ' << ans.size() << endl;
	for(int x : ans)
		cout << x << ' ';
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++)
		e.pb({0 , 0,  0, 0 , 0}) , cin >> e[i].u >> e[i].v >> e[i].c >> e[i].t , e[i].id = i + 1;
	sort(e.begin() , e.end() , cmp);
	int i = 0;
	for(auto[u , v , c , t , boz] : e){
		mp[u][c] ++ , mp[v][c] ++ ;
		if(mp[v][c] >= 2){
			if(dup[v]) dokme("No");
			dup[v] = c;
		}
		if(mp[u][c] >= 2){
			if(dup[u]) dokme("No");
			dup[u] = c;
		}
		adj[v].pb({u , i});
		adj[u].pb({v , i});
		i++;
	}
	if(!chk(m))dokme("No");
	int ans = m;
	for(int i = 20 ; i >= 0 ; i --){
		if(ans - (1 << i) < 0)continue;
		ans -= (1 << i);
		if(!chk(ans))ans += (1 << i);
	}
	cout << "Yes" << endl;
	solve(ans);
    return(0);
}