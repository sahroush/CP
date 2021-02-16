//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
///*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
ll x;

bool sq(ll x){ //never trust stl
	ll l = 1  , r = 100000;
	while(r - l > 1){
		ll mid = (l + r) / 2;
		if(mid * mid * mid > x)
			r = mid;
		else 
			l = mid;
	}
	return((l * l * l) == x);
}


int32_t main(){
	migmig;
	cin >> q;
	while(q -- ){
		cin >> x;
		bool ok = 0;
		for(ll i = 1 ; i * i * i <= x ; i ++){
			ll y = x - i * i * i;
			if(sq(y)){
				ok = 1;
				break;
			}
		}
		cout << ((ok) ? "YES" : "NO") << endl;
	}
	return(0);
}
