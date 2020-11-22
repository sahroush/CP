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

int n , m , k;
ll a[maxn];

ll c[maxn][maxn];

ll dp[(1 << maxn)][maxn];

int32_t main(){
    migmig;
	cin >> n >> k >> m;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i] , dp[(1 << i)][i] = a[i];
	for(int i = 0 ; i < m ; i ++){
		int x , y;
		cin >> x >> y;
		x -- , -- y;
		cin >> c[x][y];
	}
	ll ans = 0;
	for(int i = 0 ; i < (1 << n) ; i ++)for(int I = 0 ; I < n ; I ++)if(i&(1 << I)){
		auto &cur = dp[i][I];
		for(int j = 0 ; j < n ; j ++){
			if(i&(1 << j))continue;
			auto &nxt = dp[i|(1 << j)][j];
			nxt = max(nxt , cur + a[j] + c[I][j]);
		}
		if(__builtin_popcount(i) == k)
			ans = max(ans , cur);
	}
	cout << ans;
    return(0);
}