//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e5+10;
const ll mod = 998244353;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , c[maxn] , prt[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)cin >> c[i];
	sort(c + 1 , c + n + 1);reverse(c + 1 , c + n + 1);
	for(int i = 1 ; i <= n ; i ++)prt[i] = (prt[i - 1] + c[i])%mod;
	ll nr = pw(n , mod - 2);
    for(int i = 1 ; i <= n ; i ++){
		ll ans = 0;
		for(int j = 1 , k = 0 ; j <= n ; j += i , k++)
			ans = (ans + ((prt[min(n, i+j-1ll)] - prt[j-1] + mod)%mod) * k)%mod;
		cout << (ans * nr)%mod << endl;
	}
	return(0);
}
