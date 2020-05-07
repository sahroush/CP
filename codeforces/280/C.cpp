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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];
ld ans;

void dfs(int v , int par = 0 , ld dist = 1){
	ans+=ld(1)/dist;
	for(auto u : adj[v])if(u!=par)dfs(u , v , dist+1);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    dfs(1);
    cout << fixed  << setprecision(10) << ans;
    return(0);
}

