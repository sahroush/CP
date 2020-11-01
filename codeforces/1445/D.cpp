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
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
ll a[maxn];

ll fact[maxn];

#define inv(a) pw(a , mod-2)

ll c(ll r , ll n){
	return(((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r]))%mod;
}

int32_t main(){
    migmig;
	cin >>n;
	n*=2;
	fact[0] = 1;
	for(int i = 1 ; i < 3e5+100 ; i ++)
		fact[i] = (fact[i-1] * i)%mod;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	sort(a , a + n);
	ll ans = 0;
	n/=2;
	for(int i = 0 ; i < n ; i ++)
		ans -= a[i];
	for(int i = n ; i < 2*n ; i ++)
		ans += a[i];
	ans%=mod;
	cout << (ans * c(n , 2*n ))%mod;
    return(0);
}
