/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e3+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll d;
vector < int > adj[maxn];
ll inv[maxn];
ll x;
ll dp[maxn][maxn];
ll Dp[maxn];
ll fact[maxn][2];

void dfs(int v = 1){
	for(auto u : adj[v])
		dfs(u);
	for(int i = 1;  i <= x ; i ++){
		ll res = 1;
		for(auto u : adj[v])
			res = (res * dp[u][i])%mod;
		dp[v][i] = (dp[v][i - 1] + res)%mod;
	}
	if(adj[v].size() == 0)
		for(int i = 1 ; i <= x ; i ++)dp[v][i] = i;
}

ll c(ll r , ll n){
	return((fact[n][0] * ((fact[r][1] * fact[n - r][1] % mod )%mod))%mod);
}

int32_t main(){
    migmig;
	cin >> n >> d;
	fact[0][0] = fact[0][1] = 1;
	for(int i = 1 ; i < maxn ; i ++)
		fact[i][0] = (fact[i-1][0] * i )%mod , fact[i][1] = pw(fact[i][0] , mod - 2);
	for(int i = 2 ; i <= n ; i ++){
		int par;
		cin >> par;
		adj[par].pb(i);
	}
	x = min((ll)n , d);
	for(int i = 1 ; i <= x ; i ++){
		inv[i] = ((d - i + 1) * 1LL * pw(i, mod - 2))%mod;
		if(i > 1)inv[i] = (inv[i - 1] * inv[i])%mod;
	}
	dfs();
	ll ans = 0;
	for(int i = 1 ; i <= x ; i ++){
		Dp[i] = dp[1][i];
		for(int j = 1 ; j < i ; j ++)
			Dp[i] = (Dp[i] - (Dp[j] * c(j , i))%mod + mod)%mod;
		ans = (ans + (Dp[i] * inv[i])%mod)%mod;
	}
	cout << ans;
    return(0);
}
