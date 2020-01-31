#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
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

ll n , m;
ll x[maxn] , y[maxn];
pll val[maxn];
vector < int > adj[maxn];
ll srt[maxn];
ll dp[maxn] , pd[maxn];
ll res[maxn];

int main(){
    migmig

    cin >> n >> m;

    for (int i = 1;  i<=n; i ++){
        cin >> x[i] >> y[i];
        val[i] = pii(y[i] - x[i] , i);
    }

    for (int i = 1;  i <= m ; i ++){
        int u , v;
        cin >> v >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sort(val+1 , val + n + 1);

    for (int i = 1 ; i <= n ; i ++){
        srt[val[i].second] = i;
        dp[i] = dp[i - 1] + y[val[i].second];
    }

    for (int i = n ; i > 0 ; i --){
        pd[i] = pd[i + 1] + x[val[i].second];
    }
	for (int i = 1 ; i <= n ; i ++){
        int u = val[i].second;
        ll ans=dp[i - 1] + pd[i + 1] + 1ll*(i - 1) * x[u] + 1ll*(n-i)*y[u];
        for (auto v : adj[u]){
            ans-=(min(x[u] + y[v] , x[v] + y[u]));
        }
        res[u] = ans;
    }
	for (int i = 1; i <= n ; i ++){
        cout << res[i] << ' ';
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
