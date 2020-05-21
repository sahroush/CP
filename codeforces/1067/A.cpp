#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5+2;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , a[maxn] , dp[maxn][210][3];

int main(){
    migmig
    cin >> n ;
    for(ll i = 1 ; i <= n ; i ++) cin >> a[i];
    for(ll i = 1 ; i <= 200 ; i ++)
		if(a[1] == -1 or a[1] == i)
			dp[1][i][0] = 1;
	for(ll i = 2 ; i <= n ; i ++){
		ll prt = 0;
		for(ll j = 1 ; j <= 200 ; j ++){
			if(a[i] == -1 or a[i] == j){
				dp[i][j][0] = prt;
				dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2])%mod;
			}
			prt = (prt + (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2])%mod)%mod;
		}
		prt = 0;
		for(ll j = 200 ; j ; j --){
			if(a[i] == -1 or a[i] == j)
				dp[i][j][2] = prt;
			prt = (prt + dp[i-1][j][1] + dp[i-1][j][2])%mod;
		}
	}
    ll ans = 0 , i = n;
    for(ll j = 1 ; j <= 200 ; j ++)
			if(a[i] == -1 or a[i] == j)
				ans = (ans + dp[i][j][1] + dp[i][j][2])%mod;
	cout << ans;
    return(0);
}