//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2010;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , a , b , par[maxn][maxn];
ld dp[maxn][maxn] , p[maxn] , u[maxn];

int solve(ld x){
	for(int i = 1 ; i <= n ; i ++)for(int j = 0 ; j <= a ; j ++){
		dp[i][j] = dp[i-1][j], par[i][j] = 0;
		if(j and dp[i][j] < dp[i - 1][j - 1] + p[i]){
			dp[i][j] = dp[i - 1][j - 1] + p[i];
			par[i][j] = 1;
		}
		if(dp[i][j] < dp[i - 1][j] + u[i] - x){
			dp[i][j] = dp[i - 1][j] + u[i] - x;
			par[i][j] = 2;
		}
		if(j and dp[i][j] < dp[i - 1][j - 1] + (p[i] + u[i] - p[i] * u[i]) - x){
			dp[i][j] = dp[i - 1][j - 1] + (p[i] + u[i] - p[i] * u[i]) - x;
			par[i][j] = 3;
		}
	}
	int cnt = 0 , cur = a;
	for(int i = n ; i >= 1 ; i --){
		if(par[i][cur] == 1){
			cur --;
		}
		else if(par[i][cur] == 2){
			cnt++;
		}
		else if(par[i][cur] == 3){
			cur--, cnt++;
		}
	}
	return cnt;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> a >> b;
	for(int i = 1 ; i <= n ; i ++)
		cin >> p[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> u[i];
	ld l = 0 , r = 1;
	for(int i = 0 ; i < 100 ; i ++){
		ld mid = (l + r)/2.0;
		if(solve(mid) <= b)
			r = mid;
		else
			l = mid;
	}
	solve(r);
	cout << dp[n][a] + r * b;
	return(0);
}
