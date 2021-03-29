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

const int maxn = 1100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n , k;
int dp[maxn][maxn][2];
//0 -->

int f(int pos , int d , int dir){
	if(dp[pos][d][dir] ^ -1)
		return dp[pos][d][dir];
	if(d == 1)
		return dp[pos][d][dir] = 1;
	if(!dir){
		if(pos == n)
			dp[pos][d][dir] = 1;
		else
			dp[pos][d][dir] = f(pos + 1 , d , dir);
		if(pos == 1)
			dp[pos][d][dir] += 1;
		else
			dp[pos][d][dir] += f(pos - 1 , d-1 , 1-dir);
	}
	if(dir){
		if(pos == 1)
			dp[pos][d][dir] = 1;
		else
			dp[pos][d][dir] = f(pos - 1 , d , dir);
		if(pos == n)
			dp[pos][d][dir] += 1;
		else
			dp[pos][d][dir] += f(pos + 1 , d-1 , 1-dir);
	}
	dp[pos][d][dir] %= mod;
	return dp[pos][d][dir];
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= k ; j ++)
				dp[i][j][0] = dp[i][j][1] = -1;
		cout <<  f(1 , k , 0) << endl;
	}
	return(0);
}
