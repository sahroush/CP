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
int a[maxn];
bitset < 101 * 2000 > bs;

void solve(){
	bs[0] = 1;
	ll sum = 0;
	ll fard = 0;
	for(int i = 1 ; i <= n ; i ++)
		sum += a[i] , fard = ((a[i] % 2) ? i : fard), bs |= (bs << a[i]);
	if(sum % 2)dokme(0);
	if(bs[sum/2] == 0)dokme(0);
	if(fard){
		cout << 1 << endl;
		dokme(fard);
	}
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	int gc = a[1];
	for(int i = 1 ; i <= n ; i ++)
		gc =  __gcd(gc , a[i]);
	while(1){
		for(int i = 1 ; i <= n ; i ++)a[i] /= gc;
		solve();
	}
	return(0);
}
