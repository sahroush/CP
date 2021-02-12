/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
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

ll n , q , k;
ll a[maxn];

ll sum[maxn];

ll cnt(ll l , ll r){
	return(r - l + 1);
}

int32_t main(){
	migmig;
	cin >> n >> q >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 2 ; i < n ; i ++){
		sum[i] = cnt(a[i - 1] + 1, a[i + 1] - 1) - 1;
		sum[i] = sum[i - 1] + sum[i];
	}
	while(q -- ){
		int l , r;
		cin >> l >> r;
		if(l == r){
			cout << k - 1<< endl;
			continue;
		}
		ll ans = 0;
		ans += cnt(1 ,  a[l + 1] - 1) + cnt(a[r - 1]+1 , k) - 2;
		ans += sum[r - 1] - sum[l];
		cout << ans << endl;
	}
	return(0);
}
