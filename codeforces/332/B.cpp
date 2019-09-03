#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init     freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n,k,a[maxn];
ll dp[maxn];

int main(){
	cin >> n >> k;
	for (int i  =0 ; i < n ; i ++){
		cin >> a[i];
	}
	fill(dp,dp+maxn,0);
	
	for (int i =1 ; i <= n ; i ++){
		if(i){
			dp[i]= a[i-1]+dp[i-1];
		}
	}
	
	ll ans1=0 ,ans2=0 , b=0 , pb=0,z=0 , ca;
	ll c;
	for (int i = n-2*k+1 ; i > 0;i -- ){
		c=dp[i+2*k-1]-dp[i+k-1];
		if (c >= b){
			b=c;
			pb=i+k;
		}
		ca=dp[i+k-1]-dp[i-1];
		if (ca+b>=z){
			z=ca+b;
			ans1=i;
			ans2=pb;
		}
	}
	cout << ans1 << '\t' << ans2;
	
	
	return(0);
}
	
	



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
