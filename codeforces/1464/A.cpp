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

int n , m;
int t;

int x[maxn] , y[maxn];

int r[maxn] , c[maxn];

int X[maxn] , Y[maxn];

queue < int > q;

vector < int > adj[maxn];

int nm[maxn];

bool mark[maxn];

void dfs(int v){
	mark[v] =1 ;
	for(auto u : adj[v])
		if(!mark[u])
			dfs(u);
}

int32_t main(){
    migmig;
	cin >> t;
	while(t -- ){
		cin >> n >> m;
		int cnt = 0;
		for(int i = 0 ; i <= n ; i ++)X[i] = Y[i] = r[i] = c[i] = 0;
		for(int i = 0 ; i < m ; i ++)
			cin >> x[i] >> y[i] , r[x[i]] = 1 , c[y[i]] = 1, cnt += (x[i]!=y[i]) , X[x[i]] = y[i], Y[y[i]] = x[i];
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(!r[i] and !c[i])continue;
			if(r[i])continue;
			q.push(i);
		}
		while(!q.empty()){
			int v = q.front();
			q.pop();
			if(r[v])continue;
			if(!c[v])continue;
			ans ++;
			cnt --;
			r[Y[v]] = 0;
			q.push(Y[v]);
			X[Y[v]] = 0;
			X[v] = v , Y[v] = v;
			r[v] = 1;
		}
		ans += cnt;
		cnt = 0;
		bool f = 0;
		for(int i = 0 ; i <= n ; i ++)adj[i].clear();
		int cur = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(X[i] == i or !X[i])continue;
			nm[i] = ++cur;
		}
		for(int i = 1 ; i <= n ; i ++){
			if(X[i] == i or !X[i])continue;
			adj[nm[i]].pb(nm[Y[i]]);
			adj[nm[Y[i]]].pb(nm[i]);
		}
		for(int i = 1 ; i <= cur ; i ++)mark[i] = 0;
		for(int i = 1 ; i <= cur ; i ++)if(!mark[i])cnt ++ , dfs(i);
		cout << ans + cnt << endl;
	}
    return(0);
}
