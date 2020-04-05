#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6+100;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define lowbit(x) ((x)&(-(x)))
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int dp[600][600];
int n , ans[600];

int main(){
    migmig
    ms(dp , -1);
    cin >> n;
    for(int i = 1; i <= n ; i ++){
        cin >> dp[i][i];
    }
    for(int i=1 ; i <= n ; i ++){
        for(int j = i-1 ; j > 0 ; j --){
            for(int k = j ; k <= i ; k ++){
                if(dp[j][k] == dp[k+1][i] and dp[j][k]!=-1){
                    dp[j][i] = dp[j][k]+1;
                }
            }
        }
    }
    ans[1] = 1;
    for(int i = 2 ; i <= n ; i ++){
        ans[i] = ans[i - 1] + 1;
        for(int j = 1 ; j < i ; j ++){
            if(dp[j][i]!=-1){
                ans[i] = min(ans[i] , ans[j-1] + 1);
            }
        }
    }
    cout << ans[n];


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
