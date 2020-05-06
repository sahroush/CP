#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  , int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int h[maxn];
ll mn[maxn];
int n , m;
vector < int > adj[maxn];
set < pii > st[maxn];
ll ans = 0;
vector < pii > boz;
bool oke = 1;

void dfs1(int v ,int par = 0){
	for(auto u : adj[v]){
		if(u!=par){
			h[u] = h[v] + 1;
			dfs1(u , v);
		}
	}
}

void merge(int u , int v){
	if((int)st[u].size() > (int)st[v].size()){
		st[u].swap(st[v]);
		swap(mn[v] , mn[u]);
	}
	for(auto i : st[u]){
		auto f = i;
		f.first -= mn[u];
		f.first+=mn[v];
		if(f.second < h[v])st[v].insert(f);
	}
}

void dfs2(int v , int par = 0){
	for(auto u : adj[v]){
		if(u != par){
			dfs2(u , v);
			if(oke == 0){
				return;
			}
			merge(u, v);
		}
	}
	boz.clear();
	for (auto i : st[v]){
		if(i.second < h[v])break;
		boz.pb(i);
	}
	for(auto i : boz)st[v].erase(i);
	boz.clear();
	for(auto i : boz){
		st[v].erase(i);
	}
	if(st[v].empty()){
		if(v == 1)return;
		oke = 0;
		return;
	}
	ans +=abs( (*st[v].begin()).first - mn[v] );
	mn[v] = max(mn[v] , (*st[v].begin()).first);
}


int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < n-1; i ++ ){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1);
    for(int i = 0 ; i < m ; i ++){
		ll s , e , c;
		cin >> s >> e >> c;
		st[s].insert(pii(c , h[e]));
	}
    dfs2(1);
    if(!oke)dokme(-1);
    cout << ans;
    return(0);
}

 