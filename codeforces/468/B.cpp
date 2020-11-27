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

int n;
int a[maxn];
int x , y;

struct sat{ //~x = 2*x+1 , x = 2*x --> ~x = x^1
	int n;
	vector < vector < int > > in , out;
	vector < int >  mark , col , topo;
	int c = 0;
	sat(int N):
		n(N) , in(n*2+5) , out(n*2+5) , mark(n*2+5 , 0) , col(n*2+5, 0){}
	bool operator [] (int x){ return(col[2*x] > col[2*x + 1]);};
	void add_edge(int v , int u){in[u].pb(v) , out[v].pb(u);}
	void add(int u , int v){add_edge(u^1 , v) , add_edge(v^1 , u);}
	void sfd(int v){
		mark[v] = 1;
		col[v] = c;
		for(int u : in[v]) if(!mark[u])
			sfd(u);
	}
	void dfs(int v){
		mark[v] = 1;
		for(int u : out[v]) if(!mark[u])
			dfs(u);
		topo.pb(v);
	}
	inline bool validate(){
		for(int i = 1 ; i <= 2*n + 1 ; i ++)if(!mark[i])dfs(i);
		reverse(topo.begin() , topo.end());
		memset(&mark[0] , 0 , sizeof(mark[0]) * mark.size());
		for(auto v : topo)
			if(!mark[v])
				c++ , sfd(v);
		for(int i = 1 ; i <= n ; i ++)if(col[2*i] == col[2*i+1])return(0);
		return(1);
	}
};

map < int , int > pos;

int32_t main(){
    migmig;
	cin >> n >> x >> y;
	for(int i = 1 ; i <= n ; i ++ )
		cin >> a[i] , pos[a[i]] = i;
	sat g(n);
	for(int i = 1 ; i <= n ; i ++){
		if(!pos.count(x - a[i])){
			if(!pos.count(y - a[i]))dokme("NO");
			g.add(i*2 , i*2);
			g.add(pos[y - a[i]] * 2 , pos[y - a[i]] * 2);
		}
		else if(!pos.count(y - a[i]))
			g.add(i*2 + 1 , i*2 + 1),
			g.add(pos[x - a[i]] * 2 + 1, pos[x - a[i]] * 2 + 1);
		else{
			int x = pos[::x - a[i]];
			int y = pos[::y - a[i]];
			g.add(x*2 + 1 , y*2);
			g.add(x*2 + 1 , i*2);
			g.add(y*2 , i*2 + 1);
		}
	}
	if(!g.validate())dokme("NO");
	cout << "YES" << endl;
	for(int i = 1 ; i <= n ; i ++)
		cout << g[i] << ' ';
    return(0);
}
