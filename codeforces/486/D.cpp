#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e3;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll d , n;
ll a[maxn];
vector < ll > adj[maxn];
ll mn , mx;
ll dp[maxn];
int src;
int mark[maxn][maxn];

void dfs(int v , int par = 0){
	dp[v] = 1;
	for(auto u : adj[v]){
		if(u == par)continue;
		if(a[u] < mn or a[u] > mx)continue;
		if(a[u] == mn and mark[src][u])continue;
		if(a[u] == mn)mark[u][src]=1;
		dfs(u , v);
		dp[v] = (dp[v] * dp[u] + dp[v])%mod;
	}
}

int main(){
    migmig
    cin >> d >> n;
    for(int i = 1 ; i <= n; i ++)
		cin >> a[i];
	for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans = 0;
	for(int i = 1 ; i <= n;  i ++){
		src = i;
		mx = a[i]+d , mn = a[i];
		dfs(i);
		ans+=dp[i];
		ans%=mod;
	}
    cout << ans;
    return(0);
}