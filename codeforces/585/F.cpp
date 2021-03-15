/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 5e5 + 100;
const int sigma = 10;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s , x , y;
int n , d;
bool bad[maxn];
int nxt[sigma][maxn] , sz = 0 , f[maxn];

void add(string s){
	int cur = 0;
	for(char c : s){
		if(!nxt[c - '0'][cur])nxt[c - '0'][cur] = ++sz;
		cur = nxt[c - '0'][cur];
	}
	bad[cur] = 1;
}

int q[maxn] , l , r;

void build(){
	for(int i = 0 ; i < sigma ; i ++)if(nxt[i][0])q[r++] = nxt[i][0];
	while(r - l){
		int v = q[l++];
		for(int i = 0 ; i < sigma ; i ++)
			if(nxt[i][v])f[nxt[i][v]] = nxt[i][f[v]] , q[r++] = nxt[i][v];
			else nxt[i][v] = nxt[i][f[v]];
	}
}

int dp[52][maxn];

int solve(string s){
	int ans = 0 , cur = 0;
	for(int i = 0 ; i < d ; i ++){
		for(int j = 0 ; j < s[i] - '0' + (i == d - 1) ; j ++)
			ans = (ans + dp[d - i - 1][nxt[j][cur]])%mod;
		cur = nxt[s[i] - '0'][cur];
	}
	return(ans);
}

int32_t main(){
	migmig;
	cin >> s >> x >> y;
	n = s.size() , d = x.size();
	for(int i = 0 ; i <= n - d/2; i ++)
		add(s.substr(i , d/2));
	build();
	for(int i = 0 ; i <= sz ; i ++)if(bad[i]){
		dp[0][i] = 1;
		for(int j = 0 ; j < sigma ;  j ++)
			nxt[j][i] = i;
	}
	for(int i = 1 ; i <= d ; i ++)
		for(int j = 0 ; j <= sz ; j ++)
			for(int k = 0 ; k < sigma ; k ++)
				dp[i][j] = (dp[i][j] + dp[i - 1][nxt[k][j]])%mod; 
	for(int i = d - 1;  i >= 0 ; i --)
		if(x[i] == '0')x[i] = '9';
		else{x[i] -- ; break;}
	cout << (solve(y) - solve(x) + mod)%mod;
	return(0);
}
