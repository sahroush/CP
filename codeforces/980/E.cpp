#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+20;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
vector < int > adj[maxn];
int par[maxn][40];
bool used[maxn];
int h[maxn];

void dfs(int v , int p = 0){
	par[v][0] = p;
	h[v] = h[p]+1;
	for(auto u : adj[v])
		if(u!=p)
			dfs(u , v);
}

void solve(int v){
	if(used[v])return;
	used[v] = 1;
	solve(par[v][0]);
}


int dist(int v){
	if (used[v])return(0);
	int u=v;
	for(int i = 23 ; i >= 0 ; i --)
		if(par[u][i] != 0 and !used[par[u][i]])
			u = par[u][i];
	u = par[u][0];
	return(h[v] - h[u]);
}

int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n - 1 ; i ++){
		int u , v;
		cin >> u >> v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	used[n] = 1;
	//pick n , n-1 if possible , ...
	//we should pick a subtree with n-k vertices
	dfs(n);
	for(int i = 1 ; i < 25 ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			par[j][i] = par[par[j][i - 1]][i - 1];
	k = n - k - 1;
	for(int i = n - 1 ; i >= 1 ; i --){
		int d = dist(i);
		if(d <= k){
			k-=d;
			solve(i);
		}
	}
    for(int i = 1 ; i <= n ; i ++)
		if(!used[i])
			cout << i << ' ';
    return(0);
}

