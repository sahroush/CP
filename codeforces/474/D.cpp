#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll Mod = 1e9+7;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,k;
ll dp[maxn] , sum[maxn];


int main(){
	cin >> n >> k;
	fill(dp,dp+k,1);
	for (int i = k ; i < maxn; i++){
		dp[i]=dp[i-1]+dp[i-k];	
		dp[i]%=Mod;
	}
	sum[0]=1;
	for (int i = 1 ; i <maxn ; i ++) sum[i]=sum[i-1]+dp[i];
	for (int i = 0 ; i < n ; i ++){
		int a,b;
		cin >> a >> b;
		cout << (sum[b]-sum[a-1]+Mod)%Mod << endl;
	}


	return(0);
}
//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
