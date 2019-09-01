#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n , inp;
ll cnt[maxn];
ll val[maxn] , dp[maxn]; 



int main(){
	fill (cnt,cnt+maxn , 0);
	fill (val,val+maxn , 0);
	fill (dp,dp+maxn , 0);
	cin >> n ; 
	for (ll i =0 ; i < n ; i ++){
		cin >> inp;
		cnt[inp]++;
	}
	for (ll i= 0 ; i < maxn ; i++){
		val[i]=i*cnt[i];
	}
	dp[1]=val[1];
	ll ans=0;

	for (ll i = 2 ; i < maxn ; i ++){
		dp[i]=max(dp[i-2] + val[i] , dp[i-1]);
		ans=max(dp[i] , ans);
	}
	cout << ans;
	

	return(0);
}
//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
