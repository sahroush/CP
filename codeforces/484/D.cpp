#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll  n;
ll  a[maxn];
ll  dp[maxn][2];

int main(){
    migmig
    cin >> n ;
    for (ll  i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    ms(dp , 0);
    for (ll  i = 1 ; i < n ; i ++ ){
        dp[i][0] = max(dp[i -1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i-1][1] , dp[i-1][0]);
        if (a[i - 1] > a[i]){
            dp[i][1] = max(dp[i][1],dp[i- 1][1] + a[i- 1] -a[i]);
        }
        if (a[i-1] <= a[i]){
            dp[i][0] = max(dp[i][0],dp[i - 1][0]-a[i -1] + a[i]);
        }
    }
    dp[n][0] = max(dp[n - 1][0] , dp[n - 1][1]);
    dokme(dp[n][0]);
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
