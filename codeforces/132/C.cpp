#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 111;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

string s;
int n;
int dp[maxn][55][2];

int main(){
    migmig
    cin >> s;
    cin >> n;
    memset(dp,200,sizeof(dp));
    dp[0][0][0]= 0 , dp[0][0][1]=0;
    /*
    int pos = 0 ;
    int st = 1;
    for (int i = 0 ; i < s.size() ; i ++){
        if (s[i] == 'F'){
            pos+=st;
            dp[i][0][0] = pos;
            dp[i][0][1] = 0;
        }
        else{
            st*=-1;
            dp[i][0][0] = 0;
            dp[i][0][1] = pos;
        }
    }
    */
    for (int i = 0 ; i < s.size() ; i ++){
        for (int j = 0 ; j <= n; j++){
            for (int k = 0 ; k < 2 ; k ++){
                dp[i+1][j+(s [ i ] != 'F') ][ k ] = max(dp[ i + 1 ] [ j + ( s [ i ] != 'F' ) ] [ k ] , dp [ i ] [ j ] [ k ] + ( k ? 1 : - 1 ) );
                if (k){
                    dp[i+1][j+(s [ i ] != 'F') ][ k ] = max(dp[ i + 1 ] [ j + ( s [ i ] != 'F' ) ] [ k ] , dp [ i ] [ j ] [ k ] + 1 );
                }
                else{
                    dp[i+1][j+(s [ i ] != 'F') ][ k ] = max(dp[ i + 1 ] [ j + ( s [ i ] != 'F' ) ] [ k ] , dp [ i ] [ j ] [ k ] -1 );
                } //holy shit!!!
		        dp [i + 1 ] [ j + ( s [ i ] != 'T' ) ] [ !k ]=max ( dp [ i + 1 ][ j + ( s [ i ] !='T' ) ] [ !k ] ,dp [ i ] [ j ] [ k ] );
            }
        }
    }
    int ans = 0;
    for (int  i = n ; i >= 0 ; i -= 2 )  ans = max(ans, max( dp[ s.size() ] [ i ] [ 0 ] ,   dp[ s.size() ] [ i ] [1]) ) ;
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
