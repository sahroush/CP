/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 12;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
pii dist[maxn][maxn][3][maxn][maxn][3];
int x[maxn*maxn] , y[maxn*maxn];
int mark[maxn][maxn][3];

struct tr{
	int x , y , p;
	tr(int A , int B , int C):
		x(A) , y(B) , p(C){}
};

queue < tr > q;

int X , Y , P;

void add(int x , int y , int p , int d , int D){
	if(x < 1 or x > n)return;
	if(y < 1 or y > n)return;
	pii dis = {d , D};
	if(dis >= dist[X][Y][P][x][y][p])return;
	dist[X][Y][P][x][y][p] = dis;
	if(mark[x][y][p])return;
	mark[x][y][p] = 1;
	q.push({x , y , p});
}

int hx[] = {1 , 1 , -1 , -1 , 2 , -2 , 2 , -2},
	hy[] = {2 , -2 , 2 , -2 , 1 , 1 , -1 , -1};

pii ans[maxn * maxn][3];

void spfa(int a , int p){
	X = x[a] , Y = y[a] , P = p;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			for(int k = 0 ; k < 3 ; k ++)
				dist[X][Y][P][i][j][k] = {1e9 , 1e9};
	add(x[a] , y[a] , p , 0 , 0);
	while(!q.empty()){
		auto [x , y , p] = q.front();
		mark[x][y][p] = 0;
		int d = dist[X][Y][P][x][y][p].first;
		int D = dist[X][Y][P][x][y][p].second;
		q.pop();
		for(int i = 0 ; i < 3 ; i ++)add(x , y , i , d + 1 , D + 1);
		if(p == 0){ // asb
			for(int i = 0 ; i < 8 ; i ++)
				add(x + hx[i] , y + hy[i] , 0 , d + 1 , D);
		}
		if(p == 1){ //rokh
			for(int i = 1 ; i <= n ; i ++)
				add(i , y , 1 , d + 1 , D),
				add(x , i , 1 , d + 1 , D);
		}
		if(p == 2){
			for(int i = 1 ; i <= n ; i ++)
				add(x - i , y - i , 2 , d+1 , D),
				add(x + i , y + i , 2 , d+1 , D),
				add(x - i , y + i , 2 , d+1 , D),
				add(x + i , y - i , 2 , d+1 , D);
		}
	}
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++){
			int t;
			cin >> t;
			x[t] = i , y[t] = j;
		}
	for(int i = 1 ; i <= n * n ; i ++)for(int j = 0 ; j < 3 ; j ++)spfa(i , j);
	for(int i = 0 ; i < 3 ; i ++)ans[1][i] = {0 , 0};
	for(int i = 2 ; i <= n * n ; i ++){
		for(int j = 0 ; j < 3 ; j ++)
			ans[i][j] = {1e9 , 1e9};
		for(int j = 0 ; j < 3 ; j ++)
			for(int k = 0 ; k < 3 ; k ++){
				auto p = ans[i - 1][k];
				p.first += dist[x[i-1]][y[i-1]][k][x[i]][y[i]][j].first;
				p.second+=dist[x[i-1]][y[i-1]][k][x[i]][y[i]][j].second;
				ans[i][j] = min(ans[i][j] , p);
			}
	}
	pii res = min({ans[n*n][0] , ans[n*n][1] , ans[n*n][2]});
	cout << res.first << ' ' << res.second;
    return(0);
}
