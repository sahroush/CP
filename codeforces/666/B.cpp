/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < int > adj[maxn] , radj[maxn];
int dur[maxn][maxn] , rdur[maxn][maxn];
int dist[maxn][maxn];
int rdist[maxn][maxn];
queue < int > q;
int cur;
int a , b , c , d , ans; 

bool cmp(int i , int j){
	return(dist[cur][i] > dist[cur][j]);
}
bool rcmp(int i , int j){
	return(rdist[cur][i] > rdist[cur][j]);
}

void chk(int A , int B , int C , int D){
	if(A == B or A ==  C or A == D)
		return;
	if(B == C or B == D)
		return;
	if(C == D)
		return;
	if(dist[A][B] == -1e9 or dist[B][C] == -1e9 or dist[C][D] == -1e9)
		return;
	int dis = dist[A][B] + dist[B][C] + dist[C][D];
	if(dis > ans)
		ans = dis , a = A , b = B , c = C , d = D;
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		radj[v].pb(u);
	}
	for(int i = 1;  i <= n ;i ++)
		for(int j = 1 ; j <= n ; j ++)
			dist[i][j] = 1e9, rdist[i][j] = 1e9;
	for(int i = 1 ; i <= n ; i ++){
		dist[i][i] = 0;
		q.push(i);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int u : adj[v])
				if(dist[i][u] == 1e9)
					dist[i][u] = dist[i][v]+1 , q.push(u);
		}
		rdist[i][i] = 0;
		q.push(i);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int u : radj[v])
				if(rdist[i][u] == 1e9)
					rdist[i][u] = rdist[i][v]+1 , q.push(u);
		}
		for(int j = 1 ; j <= n ; j ++)
			dur[i][j] = rdur[i][j] = j;
		for(int j = 1 ; j <= n ; j ++)
			if(dist[i][j] == 1e9)dist[i][j] = -1e9;
		for(int j = 1 ; j <= n ; j ++)
			if(rdist[i][j] == 1e9)rdist[i][j] = -1e9;
		cur = i;
		sort(dur[i]+1 ,dur[i]+n+1 , cmp);
		sort(rdur[i]+1 ,rdur[i]+n+1 , rcmp);
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			for(int k = 1 ; k <= 4 ; k ++)
				for(int h = 1 ; h <= 4 ; h ++)
					chk(rdur[i][k] , i , j , dur[j][h]);
		}
	}
	//chk(1 , 2 , 3 , 4);
	cout << a << ' ' << b << ' ' << c << ' ' << d;
    return(0);
}
