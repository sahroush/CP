//*
//#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 510;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;

struct mat{
	bitset < maxn > a[maxn];
	int n, m;
	bitset < maxn >& operator [] (int i){
		return(a[i]);
	} 
	void build(int N , int M){
		n = N , m = M;
		for(int i = 1 ; i <= n ; i ++)a[i] = 0;
	}
	friend mat operator * (mat &a  , mat &b){
		mat c;
		c.build(a.n , b.m);
		for(int j = 1 ; j <= a.m ; j ++)
			for(int i = 1 ; i <= a.n ; i ++)if(a[i][j])
				c[i] |= b[j];
		return(c);
	}	
};

mat dp[70][2];

int32_t main(){
    migmig;
	cin >> n >> m;
	dp[0][0].build(n , n);
	dp[0][1].build(n , n);
	for(int i = 0 ; i < m ; i ++){
		int u , v , x;
		cin >> u >> v >> x;
		dp[0][x][u][v] = 1;
	}
	for(int i = 1 ; i < 62 ; i ++)
		dp[i][1] = dp[i-1][1] * dp[i-1][0],
		dp[i][0] = dp[i-1][0] * dp[i-1][1];
	ll ans = 0;
	mat cur , res;
	int pos = 0;
	cur.build(1 , n);
	cur[1][1] = 1;
	for(int i = 60 ; i >= 0 ; i --){
		res = cur * dp[i][pos];
		if(res[1].count()){
			ans += (1LL << ll(i));
			swap(cur , res);
			pos = 1 - pos;
		}
		if(ans > 1e18)
			dokme(-1);
	}
	cout << ans;
    return(0);
}
