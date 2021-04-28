//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 203;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k , val[maxn] , dp[maxn][130], x[8] , y[8] , id[maxn] , mark[maxn][130];
set < pair < int , pii > > s;
pii p[maxn][130];
char ans[maxn];

void check(int v , int u , int msk){
	for(int i = 0 ; i < (1 << k) ; i ++){
		if(!((msk^i) & msk) and !mark[u][i]){
			int res = msk^i;
			s.erase({dp[u][i] , pii(u , i)});
			if(dp[u][i] > dp[v][msk] + dp[u][res]){
				dp[u][i] = dp[v][msk] + dp[u][res];
				p[u][i] = {v , msk};
			}
			s.insert({dp[u][i] , pii(u , i)});
		}
	}
}

void dfs(int v , int msk){
	ans[v] = 'X';
	while(msk){
		pii n = p[v][msk];
		if(!n.second)return;
		dfs(n.first , n.second);
		msk^=n.second;
	}
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n* m ; i ++)
		cin >> val[i];
	for(int i = 1 ; i <= n * m ; i ++)
		for(int j = 0 ; j < (1 << k) ; j ++)
			dp[i][j] = 1e9;
	for(int i = 0 ; i < k ; i ++){
		cin >> x[i] >> y[i];
		int h = (x[i] - 1) * m + y[i];
		id[h] = i;
		dp[h][(1 << i)] = val[h];
		s.insert({dp[h][1<<i] , {h , (1 << i)}});
		p[h][1 << i] = {i , 0};
	}
	for(int i = 1 ; i <= n * m ; i ++)
		dp[i][0] = val[i] , mark[i][0] = 1;
	while(s.size()){
		auto tmp = *s.begin();
		s.erase(tmp);
		int v = tmp.second.first;
		int msk = tmp.second.second;
		mark[v][msk] = 1;
		if(v%m != 0)check(v , v + 1 , msk);
		if(v%m != 1 and m!=1)check(v , v - 1 , msk);
		if(v > m)check(v , v-m , msk);
		if(v + m <= n * m)check(v , v + m , msk);
	}
	int mn = 1e9 , mi = 0;
	for(int i = 1 ; i <= n * m ; i ++){
		mn = min(mn , dp[i][(1 << k) - 1]);
		if(mn == dp[i][(1 << k) - 1]) mi = i;
	}
	for(int i = 1 ; i <= n * m ; i ++)ans[i] = '.';
	dfs(mi , (1 << k) - 1);
	cout << mn << endl;
	for(int i = 1 ; i <= n * m ; i ++){
		cout << ans[i];
		if(i%m == 0)cout << endl;
	}
	return(0);
}
