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

const ll maxn  = 1e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int r[maxn][26];

int n , q;
string s;
char a[4][maxn];

int dp[300][300][300];
int sz[4];

int32_t main(){
    migmig;
	cin >> n >> q;
	cin >> s;
	for(int i = 0 ; i < 26 ; i ++)r[n+1][i]=r[n][i]=n;
	for(int i = n - 1 ; i >= 0 ; i --)
		for(int j = 0 ; j < 26 ; j ++)
			r[i][j] = (s[i] == 'a' + j) ? i : r[i + 1][j];
	dp[0][0][0]=-1;
	while(q -- ){
		string t;
		int ind;
		cin >> t >> ind;
		if(t == "-"){
			sz[ind]--;
		}
		else{
			char c;
			cin >> c;
			a[ind][sz[ind]] = c;
			sz[ind]++;
			if(ind == 1)
				for(int i = 0 ; i <= sz[2] ; i ++)
					for(int j = 0 ; j <= sz[3] ; j ++){
						dp[sz[1]][i][j] = r[dp[sz[1] - 1][i][j]+1][a[1][sz[1]-1] - 'a'];
						if(i)dp[sz[1]][i][j] =min(dp[sz[1]][i][j], r[dp[sz[1]][i-1][j]+1][a[2][i-1] - 'a']);
						if(j)dp[sz[1]][i][j] =min(dp[sz[1]][i][j], r[dp[sz[1]][i][j-1]+1][a[3][j-1] - 'a']);
					}
			if(ind == 2)
				for(int i = 0 ; i <= sz[1] ; i ++)
					for(int j = 0 ; j <= sz[3] ; j ++){
						dp[i][sz[2]][j] = r[dp[i][sz[2] - 1][j]+1][a[2][sz[2]-1] - 'a'];
						if(i)dp[i][sz[2]][j] =min(dp[i][sz[2]][j], r[dp[i-1][sz[2]][j]+1][a[1][i-1] - 'a']);
						if(j)dp[i][sz[2]][j] =min(dp[i][sz[2]][j], r[dp[i][sz[2]][j-1]+1][a[3][j-1] - 'a']);
					}
			if(ind == 3)
				for(int j = 0 ; j <= sz[1] ; j ++)
					for(int i = 0 ; i <= sz[2] ; i ++){
						dp[j][i][sz[3]] = r[dp[j][i][sz[3]-1]+1][a[3][sz[3]-1] - 'a'];
						if(i)dp[j][i][sz[3]] =min(dp[j][i][sz[3]], r[dp[j][i-1][sz[3]]+1][a[2][i-1] - 'a']);
						if(j)dp[j][i][sz[3]] =min(dp[j][i][sz[3]], r[dp[j-1][i][sz[3]]+1][a[1][j-1] - 'a']);
					}
		}
		cout << ((dp[sz[1]][sz[2]][sz[3]]==n)?"NO":"YES") << endl;
	}
    return(0);
}
