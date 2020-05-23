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

int n;
vector < int > adj[maxn];
int col[maxn];
ll dp[maxn][2];

void dfs(int v , int par = 0){
	for(auto u : adj[v])
		if(u!=par)dfs(u , v);
	dp[v][0] = 1;
	dp[v][1] = 0;
	for(auto u : adj[v])
		if(u!=par)
			dp[v][1] = (dp[v][1] * dp[u][0]%mod + dp[v][0]*dp[u][1]%mod)%mod , dp[v][0]=(dp[v][0]*dp[u][0])%mod;
	if(col[v])dp[v][1]=dp[v][0];
	else dp[v][0]+=dp[v][1];
}

int main(){
    migmig
    cin >> n;
    for(int i = 2 ; i <= n ; i ++ ){
		int x;
		cin >> x;
		x++;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	int s;
	for(int i = 1 ; i <= n ; i ++)
		cin >> col[i];
	for(int i = 1 ; i <= n ; i ++)
		if(col[i])s = i;
	dfs(s);
    cout << dp[s][1];
    return(0);
}