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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int k;
ll a[maxn];
bool odd = 1;

int32_t main(){
    migmig;
	cin >> k;
	for(int i = 0 ; i < k ; i ++)
		cin >> a[i] , odd&=(a[i]%2);
	ll p , q;
	if(odd){
		p = pw(2 , a[0]);
		for(int i = 1 ; i < k ; i ++)
			p = pw(p , a[i]);
		p = (p * pw(2 , mod - 2))%mod;
		p = (p - 1 + mod)%mod;
		p = (p * pw(3 , mod-2))%mod;
	}
	else{
		p = pw(2 , a[0]);
		for(int i = 1 ; i < k ; i ++)
			p = pw(p , a[i]);
		p = (p * pw(2 , mod - 2))%mod;
		p = (p + 1 + mod)%mod;
		p = (p * pw(3 , mod-2))%mod;
	}
	q = pw(2 , a[0]);
	for(int i = 1 ; i < k ; i ++)
		q = pw(q , a[i]);
	q = (q * pw(2 , mod - 2))%mod;
	cout << p << '/' << q;
    return(0);
}
