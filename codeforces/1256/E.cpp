/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int srt[maxn];
ll dp[maxn];
int par[maxn];
int ans[maxn];


bool cmp(int i , int j){
	return(a[i] < a[j]);
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n; i ++)
        cin >> a[i] , srt[i] = i;
    sort(srt + 1, srt + n  + 1, cmp);
    ms(dp , 63);
    dp[0] = 0;
    for(int i = 1 ; i <= n-2 ; i ++)
		for(int j = 2 ; j <= 4 ; j ++)
			if(dp[i+j] > a[srt[i+j]] - a[srt[i]] + dp[i-1])
				par[i + j] = i , dp[i + j] = a[srt[i+j]] - a[srt[i]] + dp[i-1];
	cout << dp[n] << ' ';
	int cnt = 1;
	for(int i = n ; i ; i --){
		if(ans[srt[i]])continue;
		for (int j = par[i] ; j <= i ; j ++)
			ans[srt[j]] = cnt;
		cnt++;
	}
	cout << cnt - 1 << endl;
	for(int i = 1; i <= n ; i ++)
		cout << ans[i] << ' ';
    return(0);
}