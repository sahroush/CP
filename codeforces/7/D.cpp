#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e6+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
//ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s;
int dp[maxn];
ll hsh[maxn] , rhsh[maxn];
ll pw[maxn];

int main(){
    migmig
    cin >> s;
    dp[1] = 1;
    int n = s.size();
    for(int i = 0 ; i < n ; i ++){
		int cur = i + 1;
		hsh[cur] = (hsh[i] * 327 + ll(s[i]))%mod;
	}
    for(int i = n - 1 ; i >= 0 ; i --){
		int cur = i + 1;
		rhsh[cur] = (rhsh[cur+1] * 327 + ll(s[i]))%mod;
	}
	pw[0]=1;
	for(int i = 1 ; i < maxn ; i ++){
		pw[i] = pw[i - 1]*327LL%mod;
	}
	ll sum = 1;
	for(int i = 2 ; i <= n ; i ++){
		if(hsh[i] == (rhsh[1] - rhsh[i + 1] * pw[i] %mod + 100LL * mod)%mod)
			dp[i] = dp[i/2]+1;
		sum+=dp[i];
	}
	cout << sum;
    return(0);
}

