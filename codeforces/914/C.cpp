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

string n;
int k;
ll ans = 0;
ll dp[maxn];
ll fact[maxn];
ll inv[maxn];

ll c(ll n , ll r){
	if(r > n)return(0);
	return(((fact[n] * inv[r])%mod*inv[n - r])%mod);
}

int main(){
    migmig
    cin >> n >> k;
    fact[1] = inv[1] = fact[0] = inv[0] = 1;
    for(int i = 2 ; i < 500000; i ++ ){
		fact[i] = (i * fact[i - 1])%mod;
		inv[i] = pw(fact[i] , mod - 2);
		dp[i] = dp[__builtin_popcount(i)]+1;
	}
	if(k == 0)dokme(1);
	int cur = 0;
	for(int i = 0 ; i < (int)n.size(); i ++)
		if(n[i] == '1'){
			for(int j = max(1 , cur) ;  j < int(n.size()) ; j ++ )
				if(dp[j] == k-1)
					ans = (ans + c( (int)n.size() - i - 1  ,j - cur ))%mod;
			cur++;}
	if(k == 1)ans = (ans - 1 + mod)%mod;
	if(dp[cur] == k-1)
		ans++;
	cout << ans%mod;
    return(0);
}