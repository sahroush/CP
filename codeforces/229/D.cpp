#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int n , a[maxn] , sum[maxn] , dp[maxn] , sml[maxn];


int main(){
	cin >> n;
	for (int i = 0 ; i< n ; i ++){
		
		cin >> a[i];
	}
	sum[0] = 0;
	for (int i = 1 ; i <= n; i ++){
		sum[i] = sum[i-1] + a[i-1];
	}
	dp[0] = 0 ; 
	sml[0] = 0;
	for (int i = 1 ; i <= n; i ++){
		dp[i] = 1;
		sml[i] = sum[i];
		for (int j = 0 ; j  < i ; j ++){
			if (sum[i] - sum[j] >= sml[j] and dp[i] <= dp[j] + 1){
				dp[i] = dp[j] + 1;
				sml[i] = sum[i] - sum[j];
				
			}
			
		}
	}
	
	cout << n - dp[n];

	return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.