#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =501;
const ll INF = 1e15;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct edge{
    int u , v ;
    ll w;
}e[maxn * maxn];

int  n , m ;
ll dist[maxn][maxn];
ll dp[maxn][maxn] ;

int main(){
    migmig
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j <= n ; j ++){
            dist[i][j] = INF;
        }
    }
    for (int i = 1 ; i <= n ; i ++){
        dist[i][i] = 0;
    }
    for (int i = 1 ; i <= m ; i ++){
        int u , v;
        ll l;
        cin >> u >> v >> l;
        e[i].u = u , e[i].v = v , e[i].w = l;
        dist[v][u] = dist[u][v] = min(dist[v][u] , l);
    }
    for (int k = 1 ; k <= n ; k ++){
        for (int i = 1; i <= n ; i ++){
            for (int j = 1 ; j <= n ; j ++){
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[j][k]);
            }
        }
    }
    ms(dp , 0);
    //ans[i][j] = sigma(ans[n(i)][j] + |n(i)|);
    for (int i = 1 ; i <= n ; i ++){
        for (int j = 1 ; j <= m ; j ++){
            if(dist[i][e[j].v] == dist[i][e[j].u] + e[j].w){
                dp[i][e[j].v]++;
            }
            if(dist[i][e[j].u] == dist[i][e[j].v] + e[j].w){
                dp[i][e[j].u]++;
            }
        }
    }
    //cout << dp[1][2];
    for (int i = 1 ; i <= n ; i ++){
        for (int j = i + 1 ; j<= n ; j ++){
            ll ans = 0;
            for (int k = 1 ; k <= n ; k ++){
                if(dist[i][j] == dist[i][k] + dist[k][j]){
                    ans+=dp[i][k] + dp[j][k];
                }
            }
            cout << ans/2  << ' ';
        }
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
