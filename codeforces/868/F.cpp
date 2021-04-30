//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n, k;
ll a[maxn], dp[22][maxn] , cnt[maxn] , L , R;
ll cur = 0;

ll c2 (ll x){
	return x *(x-1) / 2;
}

ll cost(int l , int r){
	while(L > l){
		L --;
		cur -= c2(cnt[a[L]]);
		cnt[a[L]]++;
		cur += c2(cnt[a[L]]);
	}
	while(L < l){
		cur -= c2(cnt[a[L]]);
		cnt[a[L]]--;
		cur += c2(cnt[a[L]]);
		L++;
	}
	while(R < r){
		R ++;
		cur -= c2(cnt[a[R]]);
		cnt[a[R]]++;
		cur += c2(cnt[a[R]]);
	}
	while(R > r){
		cur -= c2(cnt[a[R]]);
		cnt[a[R]]--;
		cur += c2(cnt[a[R]]);
		R--;
	}
	return cur;
}

void solve(int k , int l = 1 , int r = n , int ul = 1 , int ur = n){
	if (k == 1){
		for(int i = 1 ; i <= n ; i ++) dp[k][i] = cost(1 , i);
		return;
	}
	if(r < l)return;
	int mid = (l + r) / 2, umid;
	dp[k][mid] = 1e18;
	for(int i = min(ur , mid) ; i >= ul ; i --){
		if(cost(i , mid) + dp[k-1][i-1] < dp[k][mid])
			umid = i , dp[k][mid] = cost(i , mid) + dp[k-1][i-1];
	}
	solve(k , l , mid-1 , ul , umid);
	solve(k , mid+1 , r , umid , ur);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	L = R = 1 , cnt[a[1]]++;
	for(int i = 1 ; i <= k ; i ++)solve(i);
	cout << dp[k][n];
	return(0);
}
