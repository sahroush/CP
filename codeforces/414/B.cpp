#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init     freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

vector < int > vec[maxn];
int dp[maxn][maxn];
int n, k;
ll sz;


int main(){
	migmig
	vec[0].push_back(0);
	for (int i =0 ; i < 2005 ; i ++){
		for (int j = i + 1 ; j < 2001 ; j +=(i+1)){
				vec[j].push_back(i+1);
		}
	}
	for (int i = 0; i < 2002 ; i ++) dp[i][1] = 1;
	cin >> n >> k;
	ll sum = 0 ;
	for (int i=1; i<k; i++){
		for (int j=1; j<=n; j++){
			sum = 0;
			int sz=vec[j].size();
			for (int h=0; h< sz; h++) {
				sum += dp[vec[j][h]][i];
				sum %= mod;
			}
			dp[j][i+1] = sum;
		}
	}
	ll ans = 0 ;
	for (int i = 1 ; i <= n ; i ++){
		ans+= dp[i][k];
		ans%=mod;
	}
	cout << ans;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
