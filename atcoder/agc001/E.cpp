/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
const int maxm = 4100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int dp[maxm][maxm];
int x[maxn] , y[maxn];
int n;
int ans = 0;
int fact[maxn] , inv[maxn];

int C(int r , int n){
	return ((fact[n] * 1LL * inv[r])%mod) * inv[n-r] % mod;
}

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> x[i] >> y[i];
		dp[-x[i]+2010][-y[i]+2010]++;
	}
	for(int i = 1 ; i < maxm ; i ++)
		for(int j = 1 ; j < maxm ; j ++)
			dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1])%mod;
	fact[0] = inv[0] = 1;
	for(int i = 1 ; i < maxn ; i ++)fact[i] = (fact[i-1] * 1LL * i)%mod , inv[i] = pw(fact[i] , mod - 2);
	for(int i = 1 ; i <= n ; i ++)
		ans = (ans + dp[x[i]+2010][y[i]+2010])%mod;
	for(int i = 1 ; i <= n ; i ++)
		ans = (ans - C(2 * x[i] , 2 * (x[i] + y[i])) + mod)%mod;
	ans = (ans * pw(2 , mod-2))%mod;
	cout << ans;
	return(0);
}
