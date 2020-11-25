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

const ll maxn  = 2e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string a;
string b;

vector < int > kmp(string s){
	int n = s.size();
    vector < int > f(n);
    for(int i = 1; i < n ; i ++){
		int j = f[i-1];
		while(j and s[i]!=s[j])
			j = f[j-1];
		j+=(s[i]==s[j]) , f[i] = j;
	}
    return(f);
}

vector < int > f;

int32_t main(){
    migmig;
	cin >> a;
	cin >> b;
	int n = a.size() , m = b.size();
	f = kmp(b);
	int dp[n+5][m+5];
	ms(dp ,-1);
	dp[0][0] = 0;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++ ){
		dp[i][0] = dp[i-1][0];
		for(int j = 1; j <= m ; j++ ){
		    if(dp[i-1][j - 1] != -1)
		        if(a[i - 1] == '?' or a[i - 1] == b[j - 1])
				    dp[i][j] = dp[i-1][j-1];
			if(j == m and dp[i][j] != -1)
				dp[i][j]++;
		}
		for(int j = m ; j ; j-- )
			if(dp[i][j] != -1 and dp[i][f[j - 1]] != -1)
				dp[i][f[j-1]] = max(dp[i][j], dp[i][f[j - 1]]);
	}
	for(int i = 0 ; i <= m ; i ++)ans = max(ans , dp[n][i]);
	cout << ans;
    return(0);
}
