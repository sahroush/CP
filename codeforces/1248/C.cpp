#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int n , m ;
ll fib[maxn];
ll dp[maxn];

int main(){
    migmig
	cin >> n >> m;
	fib[0]= 1;
	fib[1] = 1;
	ll ans;
	if (n > m){
		swap(n , m);
	}
	for (int i = 2 ; i <= max(n ,m) ; i++){
		fib[i] = fib[i-1] + fib[i-2];
		fib[i]%=mod;
	}
	dp[1] = 2;
	dp[2] = 4;
	for(int i = 0 ; i <= m ; i ++){
		fib[i]*=2;
		fib[i]%=mod;
	}
	for (int i = 3 ; i <= m+1 ; i ++){
		dp[i]= dp[i-1] + dp[i-2];
		dp[i]%=mod;
	}
	ans = dp[n] + dp[m] - 2;
	ans%=mod;
	cout << ans;
	
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.