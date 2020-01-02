#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
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

int n , m;
string s[maxn];
ll dp[3100][3100][2];

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < n; i ++){
        cin >> s[i];
    }
    if(s[0][1] == '#' or s[1][0] == '#' or s[n-1][m-2] == '#' or s[n-2][m-1] == '#'){
        dokme(0);
    }
    ms(dp , -1);
    dp[0][0][1] = dp[0][0][0] = 1;
    dp[0][1][0] = dp[1][0][1] = 1;
    for (int i = 1 ; i < m ; i ++){
        dp[0][i][1] = 0;
        dp[0][i][0] = dp[0][i - 1][0];
        if(s[0][i] == '#'){
            dp[0][i][0]=0;
        }
    }
    for (int i = 1 ; i < n ; i ++){
        dp[i][0][1] = dp[i - 1][0][1];
        dp[i][0][0] = 0;
        if(s[i][0] == '#'){
            dp[i][0][1]=0;
        }
    }
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < m ; j ++){
            for (int k = 0 ; k < 2 ; k ++){
                if(dp[i][j][k]==-1){
                    dp[i][j][k] = 0;
                    if(j){
                        if(s[i][j - 1]!='#'){
                            dp[i][j][k] += dp[i][j-1][k];
                        }
                    }
                    if(i){
                        if(s[i - 1][j]!='#'){
                            dp[i][j][k] += dp[i - 1][j][k];
                        }
                    }
                }
                dp[i][j][k] = max((ll) 0 , dp[i][j][k]);
                dp[i][j][k]%=mod;
            }
        }
    }
    cout << ((dp[n-2][m-1][0] * dp[n-1][m-2][1]) % mod - (dp[n-1][m-2][0] * dp[n-2][m-1][1] % mod) + mod*mod) % mod;



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
