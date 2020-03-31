#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n , a , b , k;
ll dp[6000]; //i taa harekat , too khoone j om bashim
ll prt[6000];

int main(){
    migmig
    cin >> n >> a >> b >> k;
    fill(dp , dp + 6000 , 1);
    /*
    ms(dp , 0);
    dp[0][a] = 1;
    for(int i = 1; i <= k ; i ++){
        for(int j = 1 ; j<= n ; j ++){
            for(int k = 1 ; k <= n ; k ++){
                if(abs(k - j) < abs(b- k) and j!=k){
                    dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i ++){
        ans = (ans + dp[k][i])%mod;
    }
    cout << ans;
    */
    for(int i = 1;  i <= k ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            prt[j] = (prt[j - 1] + dp[j])%mod;
        }
        for(int j = 1 ; j <= n ; j ++){
            dp[j] = (prt[min(n , j + (abs(j - b)-1))] - prt[max(1 , j - (abs(j - b) - 1))-1] - dp[j] + (ll)100*mod)%mod;
        }
    }
    cout << dp[a];
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
