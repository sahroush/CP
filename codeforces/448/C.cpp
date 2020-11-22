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

const ll maxn  = 5100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn] , dp[maxn];

int solve(int l , int r , int delta = 0){
 	int mn = 1e9;
	for(int i = l ; i <= r ; i ++)mn = min(mn , a[i] - delta);
	if(mn > (r - l + 1))return(r - l + 1);
	int L = 0;
	ll ans = mn;
	for(int i = l ; i <= r ; i ++){
		if(a[i] - delta > mn and !L)
			L = i;
		if(a[i] - delta == mn){
			if(L)
				ans += solve(L , i - 1 , mn + delta) , L = 0;
		}
		if(i == r and a[i] - delta > mn){
			ans += solve(L , i , delta + mn);
		}
	}
	if(ans > r - l + 1)ans = r - l + 1;
	return(ans);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	cout << solve(1 , n);
    return(0);
}