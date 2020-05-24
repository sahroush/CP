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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int par[maxn];
int sz[maxn];
int col[maxn];
int mark[maxn];
int n;
vector < pii > vec;
vector < int > adj[maxn];
int dist[maxn];
queue < int > q;

int getpar(int v){
	return((v == par[v])?v:par[v] = getpar(par[v]));
}

void merge(int u , int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)return;
	if(sz[u] > sz[v])swap(u , v);
	sz[v]+=sz[u];
	par[u] = v;
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> col[i];
	for(int i = 1; i  <= n ; i ++)
		par[i] = i , sz[i] = 1;
	int boz = n-1;
	while(boz--){
		int u , v;
		cin >> u >> v;
		if(col[u] == col[v])
			merge(u , v);
		else
			vec.pb({u , v});
	}
	for(int i = 0 ; i < vec.size() ; i ++)
		vec[i].first = getpar(vec[i].first), vec[i].second = getpar(vec[i].second);
	for(auto [u , v] : vec)
		adj[u].pb(v) , adj[v].pb(u);
	q.push(getpar(1));
	int mx = getpar(1);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto u : adj[v]){
			if(dist[u]==0 and u!=getpar(1)){
				dist[u]=dist[v]+1 , q.push(u);
				if(dist[u] > dist[mx])mx = u;
			}
		}
	}
	int src = mx;
	ms(dist , 0);
	q.push(src);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto u : adj[v]){
			if(dist[u]==0 and u!=src){
				dist[u]=dist[v]+1 , q.push(u);
				if(dist[u] > dist[mx])mx = u;
			}
		}
	}
	cout << (dist[mx]+1)/2;
    return(0);
}