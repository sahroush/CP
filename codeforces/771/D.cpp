//*
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

const ll maxn  = 80;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string s;
int a[maxn];

int dp[maxn][maxn][maxn][2];

vector < int >  pos[3];

int calc(int a , int b , int c , int d){
	int ans = 0;
	while(a < pos[0].size() and pos[0][a] < d)ans++ , a++;
	while(b < pos[1].size() and pos[1][b] < d)ans++ , b++;
	while(c < pos[2].size() and pos[2][c] < d)ans++ , c++;
	return(ans);
}	

int32_t main(){
    migmig;
	cin >> n >> s;
	for(int i = 0 ; i < n ; i ++)
		a[i] = ((s[i] == 'K')? 1 : ((s[i] == 'V')? 0 : 2)) , pos[a[i]].pb(i);
	ms(dp, 15);
	dp[0][0][0][0] = 0;
	int v = pos[0].size() , k = pos[1].size() , o = n - v - k;
	for(int i = 0 ; i <= v ; i ++)
		for(int j = 0 ; j <= k ; j ++)
			for(int h = 0 ; h <= o ; h ++)
				for(int l = 0 ; l < 2 ; l ++){
					int Dp = dp[i][j][h][l];
					if(i < v)
						dp[i+1][j][h][1] = min(dp[i+1][j][h][1], Dp + calc(i , j , h , pos[0][i]));
					if(j < k and !l)
						dp[i][j+1][h][0] = min(Dp + calc(i , j , h, pos[1][j]) , dp[i][j+1][h][0]);
					if(h < o)
						dp[i][j][h+1][0] = min(Dp + calc(i , j , h, pos[2][h]) , dp[i][j][h+1][0]);
				}
	cout << min(dp[v][k][o][0] , dp[v][k][o][1]);
    return(0);
}