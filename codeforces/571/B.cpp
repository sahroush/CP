#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , k;
ll t,l,a[maxn],dp[5005][5005];

int main(){
	cin >> n >> k;
	t =  n / k ; l = n % k ;
	for(int i = 0 ; i < n  ; i ++ )	cin >> a[i];
	sort(a , a + n );
	for(int i = 0 ; i <= k ; i ++)
		for(int j = 0 ; j <= l ; j ++)
			dp[i][j]=9e18;
	dp[0][0]=0;
	for(int i=1; i<=k ; i++ ){
		for(int j = 0 ; j <= l ;j++ ){
			dp[i][j]= dp [ i - 1 ] [ j ]  +abs( a[ t * i + j -1 ] - a [ t * i +j - t ] ) ;
			if(j)
				dp[i][j]=min(dp  [i ] [ j ] , dp [ i - 1 ] [ j - 1 ] + abs ( a [ t * i +j - 1 ] - a [ t *i + j - t - 1  ] ) ) ;
		}
	}
	cout << dp[k] [n%k];
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
