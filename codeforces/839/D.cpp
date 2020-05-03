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

ll n;
ll a[maxn];
ll cnt[maxn];
ll dp[maxn];
ll p2[maxn];
ll ans = 0;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	p2[0] = 1;
	for(int i = 1 ; i < 2e6 ; i ++){
		p2[i]= (p2[i-1] * 2)%mod;
	}
	for(int i = 1e6 ; i >= 2 ; i --){
		ll sum = 0;
		for(int j = i ; j <= 2e6 ; j += i){
			sum+=cnt[j];
		}
		if(!sum)continue;
		dp[i] = p2[sum - 1] * sum % mod;
		for(int j = i*2 ; j <= 2e6 ; j +=i){
			dp[i] = (dp[i] - dp[j] + mod*100LL)%mod;
		}
		ans = (ans + dp[i] * i %mod )%mod;
	}
	cout << ans;
    return(0);
}

