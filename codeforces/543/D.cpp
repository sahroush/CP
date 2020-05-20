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

int n , par[maxn];
vector < int > adj[maxn];
ll dp[maxn];
ll pd[maxn];

void dfs(int v = 1){
	dp[v]=1;
	for(auto u : adj[v]){
		dfs(u);
		dp[v] = (dp[v] * dp[u]+dp[v])%mod;}
}

void rrt(int v = 1){
	ll boz = pd[v];
	for(auto u : adj[v]){
		pd[u] = boz;
		boz = (boz*dp[u]+boz)%mod;
	}
	boz = 1;
	reverse(adj[v].begin() , adj[v].end());
	for(auto u : adj[v]){
		pd[u] = (pd[u] * boz + 1)%mod;
		boz = (boz*dp[u]+boz)%mod;
	}
	reverse(adj[v].begin() , adj[v].end());
	for(auto u : adj[v]){
		rrt(u);
	}
}

int main(){
    migmig
    cin >> n;
    for(int i = 2 ; i <= n ; i ++){
		cin >> par[i];
		adj[par[i]].pb(i);
	}
    dfs();
    pd[1] = 1;
    rrt();
    for(int i = 1 ; i<= n ; i ++)
		cout << (dp[i]*pd[i])%mod << ' ';
    return(0);
}