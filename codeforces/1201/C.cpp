//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
ll a[maxn] , k;

bool chk(ll x){
	ll need = 0;
	for(int i = (n + 1)/2 ; i <= n ; i ++)
		need += max(0ll , x - a[i]);
	return need <= k;
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k; 
	for(int i =  1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	ll l = 0 , r = 1e10;
	while(r - l > 1){
		ll mid = (l + r)/2;
		if(chk(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	return(0);
}
