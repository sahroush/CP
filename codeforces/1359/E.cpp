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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , k;
ll fact[maxn] , inv[maxn];

ll c(ll r , ll n){
	if(r > n)
		return(0);
	return((fact[n] * inv[r])%mod * inv[n - r]%mod)%mod;
}


int main(){
    migmig
    cin >> n >> k;
    fact[0] = inv[0] = 1;
    for(int i = 1 ; i < 1e6 ; i ++){
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = pw(fact[i] , mod - 2);
	}
    ll ans = 0;
    ans += c(k-1 , n-1);
    for(int i = 2 ; i <= n ; i ++){
		ll cnt = 0;
		for(int j = i ; j <= n ; j += i){
			cnt++;
		}
		ans+=c(k-1 , cnt-1);
		ans%=mod;
	}
    cout << ans;
    return(0);
}