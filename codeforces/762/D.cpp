/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 1e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll a[5][maxn];
ll dp[5][maxn];

int32_t main(){
    migmig;
	cin >> n;
	for(int j = 1 ; j <= 3 ; j ++)
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[j][i];
	dp[1][1] = a[1][1] , dp[2][1] = dp[1][1] + a[2][1] , dp[3][1] = dp[2][1] + a[3][1];
	for(int j = 2 ; j <= n ; j ++){
		dp[1][j] = a[1][j] + max({dp[1][j-1] , dp[2][j-1] + a[2][j] , dp[3][j - 1] + a[2][j] + a[3][j],
			dp[3][j-2]+a[3][j-1]+a[2][j-1]+a[1][j-1]+a[2][j]+a[3][j]});
		dp[2][j] = a[2][j] + max({dp[1][j-1] + a[1][j] , dp[2][j-1] , dp[3][j-1]+a[3][j]});
		dp[3][j] = a[3][j] + max({dp[3][j-1] , dp[2][j-1] + a[2][j] , dp[1][j-1]+a[2][j] + a[1][j],
			dp[1][j-2]+a[3][j-1]+a[2][j-1]+a[1][j-1]+a[2][j]+a[1][j]});
	}
	cout << dp[3][n];
    return(0);
}
