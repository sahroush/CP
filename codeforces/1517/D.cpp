//曇り空 のぞいた予感
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 510;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, m , k;
int adj[maxn][maxn][4]; //LRUD

#define L 0
#define R 1
#define U 2
#define D 3

/*
struct tr{
	int x , y , d , len;
	friend bool operator < (tr a , tr b){
		return a.d > b.d;
	}
};
int mn[maxn][maxn][12];
int dist[maxn][maxn][12];
bool mark[maxn][maxn][12];
priority_queue < tr > pq;

int sz;
tr q[1000000];

int solve(int i , int j){
	sz = 0;
	pq.push({i , j , 0 , 0});
	mn[i][j][0] = 1000000+1;
	int ans = 1000000 * 20;
	while(pq.size()){
		tr v = pq.top();
		pq.pop();
		if(mark[v.x][v.y][v.len])continue;
		mark[v.x][v.y][v.len] = 1;
		q[sz++] = v;
		int res = dist[v.x][v.y][v.len] * 2 + ((k - 2*v.len) * mn[v.x][v.y][v.len]);
		ans = min(ans , res);
		if(v.len == k/2)continue;
		
		if(v.x > 1){
			if(dist[v.x-1][v.y][v.len+1] == 0 or dist[v.x-1][v.y][v.len+1] > dist[v.x][v.y][v.len] + adj[v.x][v.y][U] or 
				(dist[v.x-1][v.y][v.len+1] == dist[v.x][v.y][v.len] + adj[v.x][v.y][U] and min(adj[v.x][v.y][U] , mn[v.x][v.y][v.len]) < mn[v.x-1][v.y][v.len + 1]))
					dist[v.x-1][v.y][v.len+1] = dist[v.x][v.y][v.len] + adj[v.x][v.y][U] , mn[v.x - 1][v.y][v.len + 1] = min(adj[v.x][v.y][U] , mn[v.x][v.y][v.len]) ,
					pq.push({v.x - 1 , v.y , dist[v.x-1][v.y][v.len+1] , v.len + 1});
		}
		if(v.y > 1){
			if(dist[v.x][v.y-1][v.len+1] == 0 or dist[v.x][v.y-1][v.len+1] > dist[v.x][v.y][v.len] + adj[v.x][v.y][L] or 
				(dist[v.x][v.y-1][v.len+1] == dist[v.x][v.y][v.len] + adj[v.x][v.y][L] and min(adj[v.x][v.y][L] , mn[v.x][v.y][v.len]) < mn[v.x][v.y-1][v.len + 1]))
					dist[v.x][v.y-1][v.len+1] = dist[v.x][v.y][v.len] + adj[v.x][v.y][L] , mn[v.x][v.y-1][v.len + 1] = min(adj[v.x][v.y][L] , mn[v.x][v.y][v.len]) ,
					pq.push({v.x , v.y - 1 , dist[v.x][v.y-1][v.len+1] , v.len + 1});
		}
		if(v.x < n){
			if(dist[v.x+1][v.y][v.len+1] == 0 or dist[v.x+1][v.y][v.len+1] > dist[v.x][v.y][v.len] + adj[v.x][v.y][D] or 
				(dist[v.x+1][v.y][v.len+1] == dist[v.x][v.y][v.len] + adj[v.x][v.y][D] and min(adj[v.x][v.y][D] , mn[v.x][v.y][v.len]) < mn[v.x+1][v.y][v.len + 1]))
					dist[v.x+1][v.y][v.len+1] = dist[v.x][v.y][v.len] + adj[v.x][v.y][D] , mn[v.x + 1][v.y][v.len + 1] = min(adj[v.x][v.y][D] , mn[v.x][v.y][v.len]) ,
					pq.push({v.x + 1 , v.y , dist[v.x+1][v.y][v.len+1] , v.len + 1});
		}
		if(v.y < m){
			if(dist[v.x][v.y+1][v.len+1] == 0 or dist[v.x][v.y+1][v.len+1] > dist[v.x][v.y][v.len] + adj[v.x][v.y][R] or 
				(dist[v.x][v.y+1][v.len+1] == dist[v.x][v.y][v.len] + adj[v.x][v.y][R] and min(adj[v.x][v.y][R] , mn[v.x][v.y][v.len]) < mn[v.x][v.y+1][v.len + 1]))
					dist[v.x][v.y+1][v.len+1] = dist[v.x][v.y][v.len] + adj[v.x][v.y][R] , mn[v.x][v.y+1][v.len + 1] = min(adj[v.x][v.y][R] , mn[v.x][v.y][v.len]) ,
					pq.push({v.x , v.y + 1 , dist[v.x][v.y+1][v.len+1] , v.len + 1});
		}
	}
	for(int i = 1 ; i <= sz ; i ++)
		mark[q[i].x][q[i].y][q[i].len] = 0,
		dist[q[i].x][q[i].y][q[i].len] = 0,
		mn[q[i].x][q[i].y][q[i].len] = 0;
	return ans;
}
*/

int dp[12][maxn][maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	if(k % 2){
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++)
				cout << -1 << ' ';
			cout << endl;
		}
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m - 1 ; j ++){
			int w;
			cin >> w;
			adj[i][j][R] = w;
			adj[i][j+1][L] = w;
		}
	}
	for(int i = 1 ; i <= n-1 ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			int w;
			cin >> w;
			adj[i][j][D] = w;
			adj[i+1][j][U] = w;
		}
	}
	ms(dp , 63);
	ms(dp[0] , 0);
	for(int k = 1 ; k <= 10 ; k ++)
		for(int j = 1 ; j <= m ; j ++)
			for(int i = 1 ; i <= n ; i ++)
				for(int l = 0; l < k ; l ++){
					if(i > 1)
						dp[k][i][j] = min(dp[k][i][j] , dp[l][i-1][j] + adj[i][j][U] * (k - l));
					if(j > 1)
						dp[k][i][j] = min(dp[k][i][j] , dp[l][i][j-1] + adj[i][j][L] * (k - l));
					if(i < n)
						dp[k][i][j] = min(dp[k][i][j] , dp[l][i+1][j] + adj[i][j][D] * (k - l));
					if(j < m)
						dp[k][i][j] = min(dp[k][i][j] , dp[l][i][j+1] + adj[i][j][R] * (k - l));
				}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++)
			cout << dp[k/2][i][j]*2 << ' ';
		cout << endl;
	}
			
		
			
	return(0);
}
