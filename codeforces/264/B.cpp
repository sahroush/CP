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

const ll maxn  = 3e5;
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
int dp[maxn];
int mark[maxn];

int32_t main(){
    migmig;
	cin >> n;
	dp[0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		cin >> i[a];
		vector < int > boz;
		boz.clear();
		for(int j = 2 ; j *j <= a[i] ; j ++){
			if(a[i]%j)continue;
			boz.pb(j);
			while(a[i]%j==0)a[i]/=j;
		}
		if(a[i]>1)boz.pb(a[i]);
		int mx = 0;
		for(int x : boz)
			mx = max(mx , dp[x]);
		mx ++;
		for(int x : boz)
			dp[x] = max(dp[x] , mx);
	}
	cout << *max_element(dp , dp + maxn);
    return(0);
}
