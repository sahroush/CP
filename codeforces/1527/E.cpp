//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 35100;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int a[maxn];
int dp[maxn][110];
int lst[maxn] , L[maxn] , R[maxn] , curl , curr , cur;
vector < int > pos[maxn];

int cost(int l , int r){
	while(curr < r){
		curr++;
		R[a[curr]]++;
		if(R[a[curr]] > L[a[curr]]) cur += pos[a[curr]][R[a[curr]]] - pos[a[curr]][R[a[curr]] - 1];
	}
	while(curl > l){
		curl--;
		L[a[curl]]--;
		if(L[a[curl]] < R[a[curl]]) cur += pos[a[curl]][L[a[curl]] + 1] - pos[a[curl]][L[a[curl]]];
	}
	while(curr > r){
		if(R[a[curr]] > L[a[curr]]) cur -= pos[a[curr]][R[a[curr]]] - pos[a[curr]][R[a[curr]] - 1];
		R[a[curr]]--;
		curr--;
	}
	while(curl < l){
		if(L[a[curl]] < R[a[curl]]) cur -= pos[a[curl]][L[a[curl]] + 1] - pos[a[curl]][L[a[curl]]];
		L[a[curl]]++;
		curl++;
	}
	return cur;
}

void solve(int k , int l = 1 , int r = n , int ul = 1 ,int ur = n){
	if(l > r)return;
	int mid = (l + r) >> 1 , umid = ul;
	dp[mid][k] = 1e9;
	for(int i = ul ; i < min(mid , ur+1) ; i ++)
		if(dp[i][k-1] + cost(i + 1 , mid) <= dp[mid][k])
			dp[mid][k] = dp[i][k - 1] + cost(i + 1 , mid) , umid = i;
	solve(k , l , mid - 1 , ul , umid);
	solve(k , mid + 1 , r , umid , ur);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)pos[i].pb(0);
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , dp[i][1] = dp[i - 1][1] , dp[i][1] += (lst[a[i]] > 0) * (i - lst[a[i]]) , lst[a[i]] = i,
		pos[a[i]].pb(i);
	cur = dp[n][1];
	curl = 1 , curr = n;
	for(int i = 1 ; i <= n ; i ++)
		L[i] = 1 , R[i] = int(pos[i].size()) - 1;
	for(int i = 2 ; i <= k ; i ++)
		solve(i);
	cout << dp[n][k];
	return(0);
}
