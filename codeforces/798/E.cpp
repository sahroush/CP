//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , sz;
vector < int > adj[19000000];
bool mark[19000000];
int num[maxn<<2] , ord[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define mid ((l + r) >> 1)

void build(int v = 1 , int l = 1 , int r = n + 1){
	num[v] = ++sz;
	if(r - l == 1){
		adj[num[v]].pb(l);
		adj[num[v]].shrink_to_fit();
		return;
	}
	build(lc , l , mid) , build(rc , mid , r);
	adj[num[v]].pb(num[lc]);
	adj[num[v]].pb(num[rc]);
	adj[num[v]].shrink_to_fit();
}

void connect(int L, int R , int x , int v = 1 , int l = 1 , int r = n + 1){
	if(r <= L or R <= l)return;
	if(L <= l and r <= R){
		adj[x].pb(num[v]);
		return;
	}
	connect(L , R , x , lc , l , mid) , connect(L , R , x , rc , mid , r);
}

void topo(int v){
	mark[v] = 1;
	for(auto u : adj[v])if(!mark[u])
		topo(u);
	if(v <= n)ord[v] = ++sz;
}

int pre[maxn<<2];

void hide(int pos , int v = 1 , int l = 1 , int r = n + 1){
	pre[v] = num[v];
	num[v] = ++sz;
	adj[num[v]].shrink_to_fit();
	if(r - l == 1)return;
	if(pos < mid)
		hide(pos, lc , l , mid);
	else
		hide(pos , rc , mid , r);
	adj[num[v]].pb(num[lc]);
	adj[num[v]].pb(num[rc]);
	adj[num[v]].shrink_to_fit();
}

void unhide(int pos , int v = 1 , int l = 1 , int r = n + 1){
	num[v] = pre[v];
	if(r - l == 1){
		return;
	}
	if(pos < mid)
		unhide(pos, lc , l , mid);
	else
		unhide(pos , rc , mid , r);
}

bool hidden[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n , sz = n;
	build();
	for(int i = 1 ; i <= n ; i ++){
		int a;
		cin >> a;
		if(a == -1){
			//if(!hidden[i])hide(i);
			//connect(1 , n+1 , i);
			//if(!hidden[i])unhide(i);
			connect(1 , i , i) , connect(i+1 , n + 1 , i);
		}
		else{
			/*
			if(!hidden[i])hide(i);
			connect(1 , a , i);
			if(!hidden[i])unhide(i);
			*/
			connect(1 , min(a , i) , i) , connect(i+1 , a , i);
			adj[a].pb(i);
			hide(a);
			hidden[a] = 1;
		}
	}
	sz = 0;
	for(int i = 1 ; i <= n ; i ++)if(!mark[i])topo(i);
	for(int i = 1 ; i <= n ; i ++)cout << ord[i] << ' ';
	return(0);
}
