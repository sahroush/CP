//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 4010;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
string s;
int a[maxn][maxn] , dp[maxn][810];

int get(int i , int j){
	if(i < j)swap(i , j);
	return a[i][i] - a[i][j-1] - a[j-1][i] + a[j-1][j-1];
}

void solve(int k , int l = 1 , int r = n , int ul = 1 , int ur = n){
	if(k == 1){
		for(int i = l ; i <= r ; i ++)dp[i][k] = get(1 , i);
		return;
	}
	if(l == r){
		for(int i = ul ; i <= min(l-1 , ur) ; i ++)dp[l][k] = min(dp[l][k] , dp[i][k-1] + get(i+1 , l));
		return;
	}
	if(l > r)return;
	int mid = (l + r) >> 1;
	int umid = 0;
	for(int i = ul ; i <= min(mid-1 , ur) ; i ++){
		if(dp[mid][k] > dp[i][k-1] + get(i + 1 , mid)){
			dp[mid][k] = dp[i][k-1] + get(i + 1 , mid);
			umid = i;
		}
	}
	solve(k , l , mid-1 , ul , umid);
	solve(k , mid+1 , r , umid , ur);
}

int32_t main(){
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++)
			getchar() , a[i][j] = getchar() - '0' + a[i][j-1] + a[i-1][j] - a[i-1][j-1];
	}
	ms(dp , 63);
	for(int i = 1 ; i <= k ; i ++)solve(i);
	cout << dp[n][k]/2;
	return(0);
}
