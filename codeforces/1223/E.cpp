#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair< ll  , ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < pii > adj[maxn];
int n , q , k;
ll dp[maxn][2];
vector < pii > boz;

void dfs(int v , int par = 0 , ll w = 0){
    dp[v][1] = w;
    dp[v][0] = 0;
    for (auto u : adj[v]){
        if(u.first != par){
            dfs(u.first ,v , u.second);
        }
    }
    boz.clear();
    for (auto u : adj[v]){
        if(u.first != par){
            boz.pb(pii(dp[u.first][1] - dp[u.first][0] ,dp[u.first][0]));
        }
    }
    sort(boz.begin() , boz.end());
    reverse(boz.begin() , boz.end());
    int cnt = k;
    for(int i = 0 ; i < boz.size() ; i ++){
        if(boz[i].first > 0){
            if(cnt > 1){
                dp[v][1] += boz[i].first + boz[i].second;
            }
            else{
                dp[v][1] +=  boz[i].second;
            }
            if(cnt){
                dp[v][0] += boz[i].first + boz[i].second;
                cnt--;
            }
            else{
                dp[v][0] += boz[i].second;
            }
        }
        else{
            dp[v][1] +=  boz[i].second;
            dp[v][0] +=  boz[i].second;
        }
    }
}

int main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n >> k;
        for(int i = 1; i <= n ; i ++){
            adj[i].clear();
        }
        for(int i = 1;  i < n ; i ++){
            int u , v;
            ll w;
            cin >> u >> v >> w;
            adj[u].pb(pii(v , w));
            adj[v].pb(pii(u , w));
        }
        dfs(1);
        cout << dp[1][0] << endl;
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.