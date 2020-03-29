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

int n;
bool a[maxn];
vector < int > adj[maxn];
int dp[maxn];
int ans[maxn];

void dfs2(int v , int par = 0){
    ans[v] = dp[v];
    for(auto u : adj[v]){
        if(u!=par){
            dp[v]-=max(0 , dp[u]);
            dp[u]+=max(0 , dp[v]);
            dfs2(u , v);
            dp[u]-=max(0 , dp[v]);
            dp[v]+=max(0 , dp[u]);
        }
    }
}

void dfs1(int v ,int par = 0){
    if(a[v] == 0){
        dp[v] = -1;
    }
    else{
        dp[v] = 1;
    }
    for (auto u : adj[v]){
        if(u!=par){
            dfs1(u , v);
            dp[v]+=max(dp[u]  , 0);
        }
    }
}

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    for (int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1 ; i <= n ; i ++){
        cout << ans[i] << ' ';
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
