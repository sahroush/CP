#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 4e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int r, g;
ll dp[maxn];

int main(){

	cin >> r >> g;

	ll h=(sqrt(1+2*(r+g))-0.5);
	fill(dp,dp+maxn , 0);
	dp[0]=1;
	for(int i = 1 ; i <= h ; i ++){
		for (int j = min(r,g)-i ; j >=0 ; j--){
			dp[i+j]+=dp[j];
			dp[i+j]%=mod;
		}
	}
	ll ans = 0;
	for (int i = (h*(h+1))/2-max(r,g) ; i <= min (r,g) ; i++){
		ans+=dp[i];
		ans%=mod;
	}
	if (r== 1 or g==1){
		if (g==0 or r==0){
			dokme(1);
		}
		if (g==1 and r==1){
			dokme(2);
		}
		if (ans > 0){
			dokme(2);
		}
		dokme(0);
	}
	if (r==0 or g==0){
		if (ans > 0){
			dokme(1);
		}
		dokme(0);
	}
	cout << ans;

	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
