#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int k , a , b;
ll pa , pb , dp[2000][2000];
ll ans , boz;

int main(){
    migmig
    cin >> k >> a >> b;
    pa = a * pw(a+b , mod - 2) % mod;
    pb = b * pw(a+b , mod - 2) % mod;
    dp[1][0] = 1;
    boz = pa * pw(pb , mod - 2) %mod;
    for(int i = 1 ; i <= k ; i ++)
		for(int j = 0 ; j <= k ; j ++)
			if(i + j >= k)
				ans = (ans + dp[i][j] * ((i + j + boz)%mod)%mod)%mod;
			else
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * pa)%mod , dp[i][j + i] = (dp[i][j + i] + dp[i][j] * pb)%mod;
	cout << ans;
    return(0);
}

