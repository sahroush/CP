//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5+100;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k , x;
ld a[maxn];
ld dp[maxn][53];
ld kire[maxn] , khar[maxn];

ld cost(int l , int r){
	return dp[r][1] - dp[l-1][1] - (kire[l-1] *  (khar[r] - khar[l-1]));
}

void solve(int k , int l = 1 , int r = n , int ul = 1 ,int ur = n){
	if(k == 1){
		ld sum = 0;
		for(int i = 1 ; i <= n ; i ++)	
			sum += a[i] , dp[i][k] = dp[i-1][k] + sum/a[i];
		return ;
	}
	if(l == r){
		dp[l][k] = 1e18;
		for(int j = min(ur , l) ; j >= ul ; j --)
			dp[l][k] = min(dp[l][k] , cost(j , l) + dp[j-1][k-1]);
		return;
	}
	if(r < l)return;
	int mid = (l + r) / 2 , umid = 0;
	dp[mid][k] = 1e18;
	for(int j = min(ur , mid) ; j >= ul ; j --){
		if(cost(j , mid) + dp[j-1][k-1] - dp[mid][k] <= 0.000001)
			umid = j , dp[mid][k] = cost(j , mid) + dp[j-1][k-1];
	}
	solve(k , l , mid-1 , ul , umid);
	solve(k , mid +1 , r , umid , ur);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> x , a[i] = x, khar[i] = khar[i-1] + (1 / a[i]) , kire[i] = kire[i-1] + a[i];
	for(int i = 1 ; i <= k ; i ++)solve(i);
	cout << fixed << setprecision(10) << dp[n][k];
	return(0);
}
