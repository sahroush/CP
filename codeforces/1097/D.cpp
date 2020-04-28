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

ll n , k;
ll dp[100][20000];
ll ans = 1;


ll p(ll x  , int cnt){
	if(cnt == 0)return(1LL);
	ll ans = 0;
	dp[cnt][0] = 1;
	for(int i = 1 ; i <= k ; i ++){
		for(int j = cnt ; j >= 0 ; j --){
			if(j < cnt)dp[j][i] = (dp[j + 1][i] + (dp[j][i - 1] * pw(j+1 , mod-2))%mod)%mod;
			else dp[j][i] = ( (dp[j][i - 1] * pw(j+1 , mod-2))%mod)%mod;
		}
	}
	for(int i = 0 ; i <= cnt ; i ++){
		ans = (ans + (dp[i][k] * pw(x , i))%mod)%mod;
	}
	return(ans);
}

int main(){
    migmig
    cin >> n >> k;
    ll boz = n;
    for(ll i = 2 ; i * i <= n ; i ++){
		int cnt = 0;
		while(boz%i == 0){
			boz/=i;
			cnt++;
		}
		ans*=p(i , cnt);
		ans%=mod;
		dp[cnt][0]=0LL;
	}
    if(boz > 1)ans*=p(boz ,1);
    cout << ans%mod;
    return(0);
}

