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

int t;
ll x , y , p , q;

bool chk(ll mid){
	if(p * mid < x)return(0);
	if(mid * (q - p) < y)return(0);
	return(1);
}

int32_t main(){
    migmig;
	cin >> t;
	while(t -- ){
		cin >> x >> y >> p >> q;
		if(p == q and x!=y){
			cout << -1 << endl;
			continue;
		}
		if (x == y and p == q){
			cout << 0 << endl;
			continue;
		}
		if(p == 0){
			if(x == 0){
				cout << 0 << endl;
			}
			else{
				cout << -1 << endl;
			}
			continue;
		}
		ll l = -1 , r = 2e9;
		y-=x; // wa
		while(r - l > 1){
			ll mid = (l + r) / 2;
			if(chk(mid))
				r = mid;
			else
				l = mid;
		}
		cout << r * q - x - y << endl;
	}
    return(0);
}
