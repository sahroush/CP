//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 19;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ld p[maxn][maxn];
int n;
ld dp[(1 << maxn)];

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n ; j ++)
			cin >> p[i][j];
	dp[1] = 1;
	for(int i = 0 ; i < (1 << n) ; i ++){
		if(__builtin_popcount(i) <= 1)continue;
		for(int j = 1 ; j < n ; j ++)if(i&(1 << j)){
			for(int k = 0 ; k < j ; k ++)if(i&(1 << k)){
				dp[i] = max(dp[i] , dp[i ^ (1 << k)] * p[j][k] + dp[i ^ (1 << j)] * p[k][j]);
			}
		}
	}
	cout << setprecision(10) << dp[(1 << n) - 1];
    return(0);
}
