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
typedef pair<ll  ,ll > pii;

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

int n, q;
int c[maxn];
ll v[maxn];
ll dp[maxn];
bool mark[maxn];

int mx[2];

ll a , b;

ll solve(){
	ms(dp , 0);
	mx[0]=mx[1]=0;
	ms(mark , 0);
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(mark[c[i]])dp[c[i]] = max(dp[c[i]] , dp[c[i]] + a*v[i]);
		else mark[c[i]] = 1 , dp[c[i]] = v[i] * b;
			
		if(mx[0] != c[i])
			dp[c[i]] = max(dp[c[i]] , dp[mx[0]] + b*v[i]);
		if(mx[1] != c[i])
			dp[c[i]] = max(dp[c[i]] , dp[mx[1]] + b*v[i]);
		
		ans = max(ans , dp[c[i]]);
		
		if(dp[mx[0]] < dp[c[i]])
			if(c[i] != mx[1])
				mx[0] = c[i];
		if(dp[mx[0]] > dp[mx[1]])
			swap(mx[0] , mx[1]);
	}
	return(ans);
}

int32_t main(){
    migmig;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> c[i];
	while(q -- ){
		cin >> a >> b;
		cout << solve() << endl;
	}
    return(0);
}
