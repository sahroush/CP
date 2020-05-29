#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
int c[maxn];
vector < int > adj[maxn];
ll ans[maxn];
map < ll , ll >  mp[maxn];
int mx[maxn];

void merge(map < ll , ll >& mu , map < ll , ll >& mv , int u , int v){
	if(mu.size() > mv.size()){
		swap(mu , mv);
		mx[v] = mx[u];
		ans[v] = ans[u];
	}
	for(auto [f , s] : mu){
		mv[f]+=s;
		if(mv[f] > mx[v]){
			mx[v] = mv[f];
			ans[v] = f;
		}
		else if(mv[f] == mx[v]){
			ans[v]+=f;
		}
	}
}

void dfs(int v , int par = 0){
	mp[v][c[v]]=1;
	mx[v] = 1;
	ans[v] = c[v];
	for(auto u : adj[v]){
		if(u!=par){
			dfs(u , v);
			merge(mp[u] , mp[v] , u , v);
		}
	}
}
int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> c[i];
	for(int i = 1; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    dfs(1);
    for(int i = 1 ; i <= n ; i ++){
		cout << ans[i] << ' ';
	}
    return(0);
}