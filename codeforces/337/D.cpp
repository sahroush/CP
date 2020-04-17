#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , d;
vector < int > adj[maxn];
bool mark[maxn];
int sub[maxn] , dist[maxn] , pr[maxn];

void dfs(int v , int par = 0){
	sub[v] = dist[v] = pr[v] = -1e9;
	if(mark[v]) sub[v] = dist[v] = pr[v] = 0;
	for(auto u : adj[v]){
		if(u==par){
			continue;
		}
		dfs(u,v);
		if(sub[v]<=sub[u])
			dist[v] = sub[v] ,sub[v] = sub[u]+1;
		else if(dist[v] <= sub[u])
			dist[v] = sub[u]+1;
	}
}

void dfs2(int v , int par = 0){
	for(auto u : adj[v]){
		if(u == par)continue;
		if(sub[v]!=sub[u]+1)
			pr[u] = sub[v]+1;
		else 
			pr[u] = dist[v]+1;
		pr[u] = max(pr[u] , pr[v] + 1);
		dfs2(u ,v);
	}
}

int main(){
    migmig
    cin >> n >> m >> d;
    for(int i = 0 ; i < m ;  i++){
		int x;
		cin >> x;
		mark[x] = 1;
	}
	for(int i = 0 ; i < n-1 ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	dfs2(1);
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(max(pr[i] , sub[i])<=d)
			cnt++;
	cout << cnt;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
