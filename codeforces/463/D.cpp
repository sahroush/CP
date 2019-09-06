#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e8;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int dp[maxn];
int p[maxn][5];
int n , k;

bool chk(int x , int c){

	for (int i = 0 ; i < k ; i ++){
		bool f = 0;
		for (int j = 0 ; j < n ; j ++ ){
			if (p[j][i] == x){
				f=1;
			}
			if (p[j][i] == c and f==0){
				return(0);
			}
		}
	}
	return(1);
}

int main(){
	migmig
	cin >> n >> k;
	fill(dp , dp + n , 1);
	for (int i = 0 ; i < k ; i ++){
		for (int j = 0 ; j < n ; j ++){
		cin >> p[j][i];
		}
	}
	dp[0] = 1 ;
	for (int i = 0 ; i < n ; i ++){
		int mx=0;
		for (int j = 0 ; j < i ; j ++){
			if (mx < dp[j] and chk(p[j][0] , p[i][0])){
				mx = max (mx,dp[j]);
			}
		}
		dp[i] = max(dp[i] , mx +1);
	}
	int mx =0 ;
	for (int i = 0 ; i < n ; i ++ ){
		mx = max(mx,dp[i]);
	}


	cout << mx;

	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
