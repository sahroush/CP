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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e5 + 100;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k;
int b[1010][1010];
int c[maxn];
int d[maxn];
int e[maxn];
int f[maxn];
char a[1010][1010] , s[maxn];
ll sum[30][1010][1010] , prt[27][1010][1010] , org[1010][1010];


int32_t main(){
    migmig;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> (a[i] + 1);
	for(int i = 1 ; i <= k ; i ++){
		cin >> c[i] >> d[i] >> e[i] >> f[i];
		cin >> s[i];
		sum[s[i] - 'a' + 1][c[i]][d[i]]++;
		sum[s[i] - 'a' + 1][c[i]][f[i]+1]--;
		sum[s[i] - 'a' + 1][e[i]+1][f[i]+1]++;
		sum[s[i] - 'a' + 1][e[i]+1][d[i]]--;
        b[c[i]][d[i]]++;
        b[e[i] + 1][f[i] + 1]++;
        b[c[i]][f[i] + 1]--;
        b[e[i] + 1][d[i]]--;
	}
	for(int i = 1 ; i <= 26 ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			for(int k = 1 ; k <= m ; k ++)
				sum[i][j][k] += sum[i][j - 1][k] + sum[i][j][k-1] - sum[i][j - 1][k - 1];
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			b[i][j] += b[i-1][j] + b[i][j - 1] - b[i - 1][j - 1],
			sum[a[i][j] - 'a' + 1][i][j] += k - b[i][j];
	for(int j = 1 ; j <= n ; j ++)
		for(int k = 1 ; k <= m ; k ++){
			for(int i = 26 ; i ; i --)
				prt[i][j][k] = prt[i + 1][j][k] + sum[i][j][k];
			for(int i = 26 ; i ; i --)
				prt[i][j][k] += prt[i + 1][j][k];
			for(int i = 1 ; i <= 26 ; i ++)
				sum[i][j][k] += sum[i - 1][j][k];
			for(int i = 1 ; i <= 26 ; i ++)
				sum[i][j][k] += sum[i - 1][j][k];
			for(int i = 26 ; i ; i --)	
				sum[i][j][k] = sum[i - 1][j][k] + prt[i + 1][j][k];	
		}
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			org[i][j] = sum[a[i][j] - 'a' + 1][i][j],
			org[i][j] += org[i - 1][j] + org[i][j - 1] - org[i - 1][j - 1];
	for(int i = 1 ; i <= 26 ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			for(int k = 1 ; k <= m ; k ++)
				sum[i][j][k] += sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i][j - 1][k - 1];
	ll ans = 1e18;
	for(int i = 1 ; i <= k ; i ++){
		ll d1  = org[e[i]][f[i]] - org[e[i]][d[i] - 1] - org[c[i] - 1][f[i]] + org[c[i] - 1][d[i] - 1];
		int ch = s[i] - 'a' + 1;
		ll d2 = sum[ch][e[i]][f[i]] - sum[ch][e[i]][d[i] - 1] - sum[ch][c[i] - 1][f[i]] + sum[ch][c[i] - 1][d[i] - 1];
		ans = min(ans , org[n][m] - d1 + d2);
	}
	cout << ans << endl;
    return(0);
}
