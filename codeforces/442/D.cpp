//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , ans  , p[maxn] , dp[maxn] , mx[maxn][3];

void upd(int v){
	dp[v] = 1;
	while(v^1){
		mx[p[v]][2] = v, v = p[v];
		sort(mx[v] , mx[v] + 3 , [](int i , int j){return dp[i] > dp[j];});
		unique(mx[v] , mx[v] + 3);
		if(v == 1) dp[v] = dp[mx[v][0]];
		else if(v ^ 1 and dp[v] == max(dp[mx[v][0]] , dp[mx[v][1]] + 1))break;
		else if (v ^ 1)dp[v] = max(dp[mx[v][0]] , dp[mx[v][1]] + 1);
	}
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> p[i+1] , upd(i+1) , cout << dp[1] << ' ';
	return(0);
}
