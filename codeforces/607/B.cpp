#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n ;
int a[maxn];
int dp[maxn][maxn];



int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= n ; j++){
       for (int i = 1;i <= j; i++){
           dp[i][j] = dp[i][j-1]+1;
           for (int k = i ; k < j ; k++){
               if (a[k] == a[j] ){
                    dp[i][j] = min(dp[i][j] , dp[i][k-1] + max ( dp[k+1] [j-1] , 1));
                }
           }
       }
   }

   cout << dp[1][n];


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
