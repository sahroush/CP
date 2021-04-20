//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1010;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, m;
int a[maxn][maxn];
vector < pii > vec;
int dp[maxn][maxn];
int X2 , Y2 , X , Y , sum , cnt;

void solve(int x , int y){
	dp[x][y] = (pw(cnt , mod - 2) * 1ll * ((sum * 1ll + (x * x * 1ll * cnt)%mod + (y * y * 1ll * cnt)%mod + X2 + Y2 + (-2ll * x * X % mod) + (-2ll * y * Y % mod))%mod))%mod;
}

void add(int x , int y){
	cnt++;
	sum = (sum + dp[x][y])%mod;
	X = (X + x)%mod;
	Y = (Y + y)%mod;
	X2 = (X2 + x * x)%mod;
	Y2 = (Y2 + y * y)%mod;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> a[i][j] , vec.pb({a[i][j] , i * (m + 1) + j});
	sort(vec.begin() , vec.end());
	for(int i = 0 ; i < n * m ; ){
		int j;
		for(j = i ; j < n * m && vec[j].first == vec[i].first ; j ++ )
			solve(vec[j].second / (m + 1) , vec[j].second % (m + 1));
		for(j = i; j < n * m && vec[j].first == vec[i].first ; j ++)
			add(vec[j].second / (m + 1) , vec[j].second % (m + 1));
		i = j;
	}
	int r , c;
	cin >> r >> c;
	cout << dp[r][c];
	return(0);
}
