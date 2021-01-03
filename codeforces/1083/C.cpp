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

const ll maxn = 2e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int lg = 20;

int n , m, par[lg+5][maxn], p[maxn], pos[maxn] , h[maxn];
vector < int > adj[maxn];
int start[maxn] , finish[maxn] , tim = 0;

bool sub(int par , int ch){
	return(start[par] <= start[ch] and finish[par] >= finish[ch]);
}

int child(int v , int u){
	return (*prev(upper_bound(adj[v].begin() , adj[v].end() , u , [](int i , int j){ return (start[i] < start[j]);})));
}

bool islca(int u , int v , int root){
	return(sub(root , u) and sub(root , v) and (root == u or !sub(child(root , u) , v)));
}

bool path(int u , int v , int root){
	return((sub(root , u) != sub(root , v)) or islca(u , v , root));
}

struct node{
	int s , e;
	node ():
		s(0) , e(0){}
	node (int v):
		s(v) , e(v){}
	node (int a , int b):
		s(a) , e(b){}
	friend node operator + (node l , node r){
		if(l.s and r.s){
			int a[] = {l.s , l.e , r.s , r.e};
			for(int i = 0 ; i < 4 ; i ++)
				for(int j = 0 ; j < 4 ; j ++){
					int cnt = 0;
					for(int k = 0 ; k < 4 ; k ++)
						if(path(a[i] , a[j] , a[k]))cnt++;
					if(cnt == 4)
						return(node(a[i] , a[j]));
				}
		}
		return(node ());
	}
}seg[maxn * 4];

void dfs(int v = 1){
	start[v] = ++tim;
	for(auto u : adj[v])
		h[u] = h[v] + 1 , dfs(u);
	finish[v] = tim;
}

#define lc (v << 1)
#define rc (lc | 1)
#define mid  ((l + r) >> 1)

int lca(int u , int v){
	if(h[v] > h[u])
		swap(u, v);
	for(int i = lg ; i >= 0 ; i --)
		if(h[par[i][u]] >= h[v])	
			u = par[i][u];
	if(u == v)return(u);
	for(int i = lg ; i >= 0 ; i --)
		if(par[i][v] != par[i][u])
			v = par[i][v] , u = par[i][u];
	return(par[0][v]);
}

void build(int v = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[v] = node(pos[l]);
		return;
	}
	build(lc , l , mid);
	build(rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

void update(int x , int pos , int v = 1 , int l = 1 , int r = n + 1 ){
	if(r - l == 1){
		seg[v] = node(::pos[l]);
		return;
	}
	if(pos < mid)
		update(x , pos , lc , l , mid);
	else
		update(x , pos , rc , mid , r);
	seg[v] = seg[lc] + seg[rc];
}

int query(int v = 1 , int l = 1 , int r = n + 1 , node pref = node()){
	if(!pref.s){
		if(seg[v].s)return(r+1);
		if(seg[lc].s){
			return(max(mid , query(rc , mid , r , seg[lc])));
		}
		return(query(lc , l , mid));
	}
	if(r - l == 1)return(r);
	else{
		if((pref + seg[v]).s)return(r);
		if(((pref + seg[lc]).s)){
			return(max(mid , query(rc , mid , r , pref + seg[lc])));
		}
		return(query(lc , l , mid , pref));
	}
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> p[i] , p[i]++;
	for(int i = 2 ; i <= n ; i ++)
		cin >> par[0][i] , adj[par[0][i]].pb(i);
	for(int i = 1 ; i <= lg ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			par[i][j] = par[i - 1][par[i - 1][j]];
	dfs();
	h[0] = -1;
	for(int i = 1 ; i <= n ; i ++)
		pos[p[i]] = i;
	build();
	cin >> m;
	while(m --){
		int t;
		cin >> t;
		if(t == 1){
			int a , b;
			cin >> a >> b;
			swap(p[a] , p[b]);
			swap(pos[p[a]] , pos[p[b]]);
			update(pos[p[a]] , p[a]);
			update(pos[p[b]] , p[b]);
		}
		else
			cout << query()-2 << endl;
	}
    return(0);
}
