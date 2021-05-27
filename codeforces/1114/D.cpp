//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5010;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > a;
int dp[maxn][maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	a.pb(-1);
	for(int i = 1,x; i <= n ; i ++){
		cin >> x;
		if(a.back()!=x)a.pb(x);
	}
	n = a.size() - 1;
	ms(dp , 63);
	for(int i = 1 ; i <= n ; i ++)dp[i][i] = 0;
	for(int sz = 1 ; sz <= n ; sz ++){
		for(int l = 1 ; l <= n ; l ++){
			int r = l + sz - 1;
			if(l > 1){
				dp[l-1][r] = min(dp[l-1][r] , dp[l][r] + 1);
			}
			if(r < n){
				dp[l][r+1] = min(dp[l][r+1] , dp[l][r] + 1);
			}
			if(l > 1 and r < n and a.at(l-1) == a.at(r+1)){
				dp[l-1][r+1] = min(dp[l-1][r+1] , dp[l][r] + 1);
			}
		}
	}
	cout << dp[1][n];
	return(0);
}
