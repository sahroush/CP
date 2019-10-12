#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e6+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n;
string s;
ll dp[maxn][4][2];

int main(){
    migmig
    cin >> s;
    n = s.size();
    memset( dp, 0, sizeof(dp));
    if( s[0] == '0' or s[0]=='?' ){
        dp[0][0][0]=1;
    }
    if( s[0] == '1' or s[0]=='?' ){
        dp[0][1][0]=1;
    }
    if( s[0] == '2' or s[0]=='?' ){
        dp[0][2][0]=1;
    }
    if( s[0] == '*' or s[0]=='?' ){
        dp[0][3][0]=1;
    }
    for( int i = 1; i < n ;i++ ){
        if( s[i] == '0' or s[i]=='?'){
            dp[i][0][0] += dp[i-1][0][0]+dp[i-1][1][1];
        }
        if( s[i] == '1' or s[i]=='?'){
            dp[i][1][0] += dp[i-1][0][0] + dp[i-1][1][1];
            dp[i][1][1] += dp[i-1][3][0] + dp[i-1][3][1];
        }
        if( s[i] == '2' or s[i]=='?'){
            dp[i][2][1] += dp[i-1][3][0] + dp[i-1][3][1];
        }
        if( s[i] == '*' or s[i]=='?' ){
            dp[i][3][0] += dp[i-1][1][0] + dp[i-1][2][1];
            dp[i][3][1] += dp[i-1][3][0] + dp[i-1][3][1];
        }
        for( int j = 0 ; j < 4; j++){
            for( int k = 0 ; k < 2 ; k++ ){
                dp[i][j][k] %= mod;
            }
        }
  }
  ll ans = dp[n-1][0][0] + dp[n-1][1][1] + dp[n-1][3][0] + dp[n-1][3][1];
  ans %= mod;
  cout << ans;




    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
