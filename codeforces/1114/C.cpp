//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , b;
vector < pii > d;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> b;
	//tedad 0 haye n! tu base b
	// == tavane b tu n!
	for(ll i = 2 ; i * i <= b ; i ++){
		if(b % i == 0)d.pb({i, 0});
		while(b%i == 0) b/= i , d.back().second ++;
	}
	if(b > 1)d.pb({b , 1});
	ll ans = 1e18;
	for(auto [x , y] : d){
		ll p = 1;
		ll cnt = 0;
		while(p <= n/x){
			p *= x;
			cnt += n/p;
		}
		ans = min(ans , cnt/y);
	}
	cout << ans;
	return(0);
}
