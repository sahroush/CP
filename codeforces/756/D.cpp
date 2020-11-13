//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5001;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string s;
int stk[maxn] , stkpos;
int c[maxn][maxn];
int dp[maxn][30];

void calc(){
	c[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= i ; j ++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
}

int32_t main(){
    migmig;
	cin >> n >> s;
	for(int i = 0 ; i < n ; i ++)
		if(s[i]-'a'+1 != stk[stkpos])stk[++stkpos] = s[i] - 'a' + 1;
	calc();
	dp[0][0] = 1;
	int ans = 0;
	for(int i = 1 ; i <= stkpos ; i ++)
		for(int j = i ; j ; j -- ){
			int ch = stk[i];
			dp[j][ch] = 0;
			for(int k = 0 ; k <= 26 ; k ++)
				if(k!=ch)
					dp[j][ch] =(dp[j][ch]+dp[j - 1][k])%mod;
		}
	for(int i = 1 ; i <= stkpos ; i ++ ){
		int res = 0;
		for(int j = 1 ; j <= 26 ;  j ++ )
			res = (res + dp[i][j])%mod;
		ans = (ans + (res * (ll)c[n][i])%mod)%mod;
	}
	cout << ans;
    return(0);
}
