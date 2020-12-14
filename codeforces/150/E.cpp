///*
//#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

const int maxn  = 1e5 + 10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n , l , r;
vector < int > adj[maxn];

bool brr;

struct node{
	int x;
	int id;
	friend bool operator < (node a , node b){
		return(a.x < b.x);
	}
}val[maxn];

int pos[maxn];

struct edg{
	int u , v , w;
	void inp(){cin >> u >> v >> w;adj[u].push_back(v) , adj[v].push_back(u);};
	friend bool operator < (edg &a , edg &b){
		return((min(pos[a.u] , pos[a.v])) < (min(pos[b.u] , pos[b.v])));
	}
};

struct segment{
	node seg[maxn*4];
	void build(int v = 1 , int l = 0 , int r = n){
		if(seg[v].x == -1e9)return;
		seg[v] = val[0];
		if(r - l == 1)
			return;
		build((v<<1) , l , ((l+r)>>1));
		build(((v<<1)|1),  ((l+r)>>1) , r);
	}
	void update(int pos , int x, int v = 1 , int l = 0 , int r = n){
		while(r - l > 1 ){
			seg[v] = max(seg[v] , val[x]);
			if(pos < ((l+r)>>1))v = (v<<1) , r = ((l+r)>>1);
			else v = ((v<<1)|1) , l = ((l+r)>>1);
		}
		seg[v] = max(seg[v] , val[x]);
	}
	node get(int L , int R , int v = 1,  int l = 0 , int r = n){
		if(r <= L || R <= l )	
			return(val[0]);
		if(L <= l && r <= R)
			return(seg[v]);
		return(max(get(L , R , (v<<1) , l , ((l+r)>>1)) , get(L , R , ((v<<1)|1) , ((l+r)>>1) , r)));
	}
};

segment mx;

edg e[maxn];

vector < int > ord;

int sz[maxn];
bool hide[maxn];

void plant(int v , int par = 0){
	sz[v] = 1;
	for(auto u : adj[v])
		if(!hide[u] && u!=par)
			plant(u , v) , sz[v] += sz[u];
}

int cen(int v , int n , int par = 0 , bool found = 0){
	while(!found){
		found = 1;
		for(auto u : adj[v])
			if(u != par && !hide[u] && sz[u] * 2 > n){
				par = v , v = u , found = 0;
				break;
			}
	}
	return(v);
}

void decomp(int v){
	plant(v);
	v = cen(v , sz[v]);
	ord.push_back(v);
	hide[v] = 1;
	for(auto &u : adj[v])
		if(!hide[u])
			decomp(u);
}	

int d;

void add(int v , int par , int h , int w){
	if(h > r)return;
	val[v].x = w;
	mx.update(h , v , 1 , 0 , d);
	for(auto &u : adj[v])if(!hide[(u >> 1)] && (u >> 1) != par)
		add(u >> 1 , v , h + 1 , w + ((u&1) ? -1 : 1));
}

bool mxp(int v , int par , int h , int w){
	if(h > r)return(0);
	int L = max(0 , l - h);
	int R = min(d , r - h) + 1;
	int res = mx.get(L , R , 1 , 0 , d).x + w;
	if(res >= 0){
		if(brr){
			cout << v << ' ' << mx.get(L , R , 1 , 0 , d).id;
			exit(0);
		}
		return(1);
	}
	for(auto u : adj[v])if(!hide[(u >> 1)] && (u >> 1) != par)
		if(mxp(u >> 1 , v , h + 1 , w + ((u&1) ? -1 : 1)))return(1);
	return(0);
}

vector < int > comp;

bool ok(int v){
	val[v].x = 0;
	mx.update(0 , v , 1 , 0 , d);
	for(auto &u : adj[v])if(!hide[(u >> 1)]){
		if(mxp(u>>1 , v , 1 , ((u&1) ? -1 : 1)))return(1);
		add(u>>1 , v , 1 , ((u&1) ? -1 : 1));
	}
	mx.build(1 , 0 , d);
	return(0);
}

int cur = 0;
int cur2 = 1;
 
bool chk(int x){
	for(int i = cur ; i < n ; i ++)adj[ord[i]].clear() , hide[ord[i]] = 0 , adj[ord[i]].reserve(8);
	mx.build();
	int Cur = cur2;
	cur2 = n;
	for(int i = Cur ; i < n ; i ++)
		if(e[i].w >= comp[x] and min(pos[e[i].u] , pos[e[i].v]) >= cur)	
			adj[e[i].u].push_back((e[i].v << 1)),
			adj[e[i].v].push_back((e[i].u << 1)) , cur2 = min(cur2 , i);
		else if(min(pos[e[i].u] , pos[e[i].v]) >= cur)
			adj[e[i].u].push_back((e[i].v << 1)|1),
			adj[e[i].v].push_back((e[i].u << 1)|1) , cur2 = min(cur2 , i);
	for(int i = cur ; i < n ; i ++){
		int &cen = ord[i];
		d = sz[cen];
		hide[cen] = 1;
		if(ok(cen)){cur = i ; return(1);}
	}
	return(0);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	val[0].x = -1e9;
	for(int i = 0 ; i < maxn ; i ++)
		val[i].id = i;
	cin >> n >> l >> r;
	for(int i = 1 ; i < n ; i ++)
		e[i].inp() , comp.push_back(i[e].w);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin() , comp.end()) - comp.begin());
	sort(e + 1, e + n);
	decomp(1);
	for(int i = 0 ; i < n ; i ++)
		pos[ord[i]] = i;
	int l = 0 , r = comp.size();
	while(r - l > 1)
		if(chk(((l+r)>>1)))l = ((l+r)>>1);
		else r = ((l+r)>>1);
	brr = 1;
	chk(l);
    return(0);
}
