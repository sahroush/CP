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

string s;
int n;
ll sum[maxn];

int32_t main(){
    migmig;
	cin >> s;
	n = s.size();
	sum[0] = 1;
	for(int i = 1 ; i < maxn ; i ++)
		sum[i] = (sum[i - 1]*10)%mod;
	for(int i = 1 ; i < maxn ; i ++)
		sum[i] = (sum[i - 1] + sum[i])%mod;
	ll cur = 0;
	ll ans = 0; 
	s = "^" + s;
	for(int i = 1 ; i < n ; i ++){
		cur = ((cur*10)%mod + s[i] - '0')%mod;
		ans = (ans + (cur * sum[n - i - 1])%mod)%mod;
	}
	cur = 0;
	for(int i = n ; i > 1 ; i --){
		cur = (cur + ((s[i] - '0') * pw(10 , n-i))%mod)%mod;
		ans = (ans + (cur * (i - 1))%mod)%mod;
	}
	cout << ans;
    return(0);
}
