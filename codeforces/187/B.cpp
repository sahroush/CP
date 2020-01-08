#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

const ll maxn =62;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , r;
ll car[maxn][maxn][maxn];
ll dp[maxn][maxn][maxn];
int s[100010] , t[100010] , k[100010];

void floyd(int v){
    for (int k = 1 ; k <= n ; k ++){
        for (int i = 1 ; i <= n ; i ++){
            for (int j = 1 ; j<= n ; j ++){
                car[v][i][j] = min(car[v][i][j] , car[v][i][k] + car[v][k][j]);
            }
        }
    }
}

int main(){
    migmig
    cin >> n >> m >> r;
    //ms(dp , 63);
    for (int i = 1 ; i <= m ; i ++) for (int j = 1 ; j <= n ; j ++) for (int k = 1 ; k <= n ; k ++) cin >> car[i][j][k];
    for (int i = 1 ; i <= m ; i ++) floyd(i);
    for (int i = 1 ; i <= r ; i++) cin >> s[i] >> t[i] >> k[i];
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j<=n ; j ++){
            dp[i][j][1] = INF;
            for (int k = 1 ; k <= m ; k ++){
                dp[i][j][1] = min(dp[i][j][1] , car[k][i][j]);
            }
        }
    }
    for (int k = 2 ; k <= n ; k ++){
        for (int i = 1 ; i <= n ; i ++){
            for (int j = 1 ; j<= n ; j ++){
                dp[i][j][k] = INF;
                for (int h = 1 ; h <= n ; h ++){
                    dp[i][j][k]=min(dp[i][j][k], dp[i][h][k-1]+ dp[h][j][1]);
                }
            }
        }
    }
    /*
    for (int cr = 1 ; cr <= m ; cr ++){
        ll dp2[maxn][maxn];
        ms(dp2 , 63);
        for (int i = 1 ; i<=n ; i ++){
            for (int j = 1 ; j <= n; j  ++){
                dp2[i][j] = car[cr][i][j];
            }
        }
        for (int k1 = 1 ; k1 <= n; k1 ++){
            for (int i = 1 ; i <= n ; i ++){
                for (int j = 1 ; j <= n ; j ++){
                    dp2[i][j]= min(dp2[i][j] , dp2[i][k1] + dp2[k1][j]);
                }
            }
        }
        for (int i = 1 ; i <= n ; i ++){
            for (int j = 1 ; j <= n ; j ++){
                dp[i][j][0]= min(dp[i][j][0] , dp2[i][j]);
            }
        }
    }
    for (int i  = 1 ; i <= n ; i ++){
        for (int j = 1 ; j<=n ; j ++){
            dp[i][j][1] = dp[i][j][0];
        }
    }
    */

    for (int i = 1 ; i<=r;i ++ ){
        k[i]++;//t
        k[i] = min(k[i] , n);//o
        cout << max(dp[s[i]][t[i]][k[i]] , (ll)0) << endl;//f
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
