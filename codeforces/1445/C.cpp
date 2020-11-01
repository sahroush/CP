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
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = 5e18){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int t;
ll p , q;
map < ll , ll > mp;

int32_t main(){
    migmig;
	cin >> t;
	while(t -- ){
		cin >> p >> q;
		// p mod x = 0
		// x mod q != 0
		if(p%q){
			cout << p << endl;
			continue;
		}
		mp.clear();
		ll x = q;
		for(ll i = 2 ; i * i <= q ; i ++){
			while(x%i == 0)
				x/=i, mp[i]++;
		}if(x > 1)mp[x] = 1;
		ll ans = p;
		ll mn = 0;
		for(auto [f , s] : mp){
			ll cnt = 0;
			while(p%f == 0)
				p/=f , cnt++;
			mn = max(mn ,ans / pw(f , cnt) *  pw(f , s-1));
		}
		cout << mn << endl;
	}




    return(0);
}
