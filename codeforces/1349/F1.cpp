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

const int maxn = 3e6;
const ll mod = 998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , dp[5100][5100] , ans;

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		dp[i][0] = 1;
		for(int j = 1 ; j < i ; j ++){
			dp[i][j] = (dp[i-1][j-1] * (i-j) + dp[i-1][j]*(j+1))%mod;
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		ans = 1;
		for(int j = i + 1 ; j <= n ; j ++)
			ans = (ans * j + dp[j][i-1])%mod;
		cout << ans << ' ';
	}
	return(0);
}
