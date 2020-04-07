#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 9e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

bool adj[30][30];
ll n , m;
ll dp[maxn][30];
ll ans = 0;

int main(){
    migmig
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i ++){
        ll u , v;
        cin >> u >> v;
        u-- , v--;
        adj[v][u] = adj[u][v] = 1;
        dp[1LL<<v|1LL<<u][max(u, v)] = 1;
    }
    ans = -m;
    for(ll i = 1 ; i < 1LL<<n ; i ++){
        ll boz =i - (i & ( i - 1));
        ll pos = -1;
        while(boz){
            pos++;
            boz>>=1LL;
        }
        for(ll j = pos ; j < n ; j ++){
            for(ll k = pos ; k < n ; k ++){
                dp[i|1LL<<k][k]+=(adj[j][k]&&!(i&(1LL<<k)))?dp[i][j] : 0;
            }
            ans+=adj[j][pos]?dp[i][j] : 0;
        }
    }
    cout << ans/2;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
