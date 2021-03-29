//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2100;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll a[maxn];
ll dp[maxn][maxn];

ll Dp(int l , int r){
	if(l < 0)return 1e17;
	if(r > n+1)return 1e17;
	if(r <= l)return 1e17;
	if(dp[l][r] != -1)return dp[l][r];
	dp[l][r] = 1e17;
	
	dp[l][r] = min(dp[l][r] , Dp(l-1 , r) + a[r-1] - a[l]);
	dp[l][r] = min(dp[l][r] , Dp(l , r+1) + a[r] - a[l+1]);
	
	return dp[l][r];
}

ll solve(){
	ms(dp , -1);
	dp[0][n+1] = 0;
	ll ans = 1e18;
	for(int i = 0 ; i <= n ; i ++)
		ans = min(ans , Dp(i , i+1));
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)cin >> a[i];
	sort(a+1 , a + n + 1);
	cout << solve();
	return(0);
}