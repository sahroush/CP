#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 210;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e8;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int f , h ;
int kf , kh ;
ll dp[110][110][15][15];
ll ans;

int main(){
	cin >> f >> h;
	cin >> kf >> kh ;
	memset(dp, 0, sizeof dp);
	for (int i = 0 ; i <= f ; i++){
		for (int j = 0 ; j <= h ; j ++){
			for (int k = 0 ; k <= kf ; k++){
				for (int l = 0 ; l <= kh ; l++ ){
					if(i+j == 0) ans = 1;
					else{
						ans=0;
						if(i > 0 and k > 0) ans = (ans + dp[i - 1][j][k - 1][kh]) % mod;
 						if(j > 0 and l > 0) ans = (ans + dp[i][j - 1][kf][l - 1]) % mod;
					}
					dp[i][j][k][l] = ans;
					//cout << ans << endl;
				}
			}
		}
	}



	cout << dp[f][h][kf][kh];
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
