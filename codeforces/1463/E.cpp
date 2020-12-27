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

const ll maxn  = 3e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
vector < int > out[maxn];
int in[maxn];

int par[maxn] , root;
int l[maxn] , t = 0 , r[maxn];

vector < int > adj[maxn] , radj[maxn];
int cnt[maxn];

int getpar(int v){
	return((v == par[v]) ? v : par[v] = getpar(par[v]));
}

int sz[maxn];

void merge(int v , int u){
	if((v = getpar(v)) == (u = getpar(u)))return;
	par[u] = v;
	sz[v] += sz[u];
}

void dfs(int v){
	l[v] = ++t;
	for(auto u : out[v])
		dfs(u);
	r[v] = t;
}

int nxt[maxn] , prv[maxn];

queue < int > q;

bool mark[maxn];

vector < int > ans;

int pos[maxn];

int32_t main(){
    migmig;
    for(int i = 0 ; i < maxn ; i ++)par[i] = i , sz[i] = 1;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		int p;
		cin >> p;
		if(!p)root = i;
		else
			out[p].pb(i),
			in[i] = p;
	}
	dfs(root);
	for(int i = 0 ; i < k ; i ++){
		int a , b;
		cin >> a >> b;
		if(l[a] >= l[b] and l[a] <= r[b])dokme(0);
		if(nxt[a] or prv[b])dokme(0);
		nxt[a] = b;
		prv[b] = a;
		merge(a , b);
	}
	for(int i = 1 ; i <= n ; i ++){
		if(getpar(i) == getpar(in[i]) or i == root)
			cnt[getpar(i)] ++;
	}
	if(sz[getpar(root)]!=cnt[getpar(root)])dokme(0);
	q.push(root);
	while(q.size()){
		int v = q.front();
		q.pop();
		if(mark[v])continue;
		mark[v] = 1;
		while(v){
			ans.pb(v);
			for(auto u : out[v]){
				if(getpar(u)==getpar(v))continue;
				cnt[getpar(u)]++;
				if(cnt[getpar(u)] == sz[getpar(u)])
					q.push(getpar(u));
			}
			v = nxt[v];
			if(ans.size() > n)dokme(0);
		}
	}
	if((int)ans.size()!=n)dokme(0);
	for(int i = 0 ; i < n ; i ++)
		pos[ans[i]] = i;
	for(int i = 1 ; i <= n ; i ++){
		if(pos[in[i]] > pos[i])dokme(0);
	}
	for(int  i : ans)
		cout << i << ' ';
    return(0);
}
