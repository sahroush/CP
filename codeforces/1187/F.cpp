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

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll l[maxn],  r[maxn];

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 0 ; i < n ; i ++)cin >> l[i];
	for(int i = 0 ; i < n ; i ++)cin >> r[i];
	ll p = 1,q = 0, sum = 0 , sm = 0;
	for(int i = 0 ; i < n ; i ++){
		if(i){
			ll a = max(0LL ,  min(r[i] , r[i-1]) - max(l[i] , l[i-1]) + 1);
			ll b = (r[i] - l[i] + 1) * (r[i - 1] - l[i - 1] + 1) % mod;
			p = ((b - a + mod)%mod * pw(b , mod - 2))%mod;
		}
		sum = (sum + p)%mod;
		sm = (sm + pw(p , 2)+ (2LL * (p-1) * (q - 1))%mod + mod)%mod;
		q = p;
	}
	ll ans = (sum * (sum + 1) - sm + mod*100LL)%mod;
	for(int i = 2 ; i < n ; i ++){
		ll a = max(0LL , min({r[i] , r[i -1 ] , r[i - 2]}) - max({l[i] , l[i - 1] , l[i - 2]}) + 1);
		ll b = max(0LL , r[i - 2] - l[i - 2] + 1);
		b = (b * max(0LL , r[i - 1] - l[i - 1] + 1))%mod;
		b = (b * max(0LL , r[i] - l[i] + 1))%mod;
		p = (a * pw(b , mod - 2))%mod;
		ans = (ans + 2 * p)%mod;
	}
    cout << ans << endl;
    return(0);
}
