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

const ll maxn  = 4100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int prt[maxn];

int dp[2][100][200][2100];
bool mark[2][100][200][2100];

int Dp(int cur = 0 , int k = 1 , int diff = 100 , int l = 0){
	if(mark[cur][k][diff][l])return(dp[cur][k][diff][l]);
	mark[cur][k][diff][l]=1;
	int r = n - l - diff + 101;
	if(!cur){
		if(l+k < r){
			dp[cur][k][diff][l] =  Dp(1-cur , k , diff-k , l+k);
			if(l + k + 1 < r)
				dp[cur][k][diff][l] = max(dp[cur][k][diff][l],
				Dp(1 - cur , k + 1 , diff - k - 1 , l + k + 1));
		}
		else
			dp[cur][k][diff][l] = prt[l] - prt[n] + prt[r - 1];
	}
	else{
		if(r - k > l){
			dp[cur][k][diff][l] = Dp(1 - cur , k , diff+k , l);
			if(r - k - 1 > l)
				dp[cur][k][diff][l] = min(dp[cur][k][diff][l],
				Dp(1 - cur , k + 1 , diff + k + 1 , l));
		}
		else
			dp[cur][k][diff][l] = prt[l] - prt[n] + prt[r - 1];
	}
	return(dp[cur][k][diff][l]);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , prt[i] = prt[i-1] + a[i];
	cout << Dp();
    return(0);
}
