#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll ans , a[maxn] , n ;
vector < int > adj[maxn];
ll dp[maxn][2];

void dfs(int v , int par = 0){
    for(auto u : adj[v])
        if(u!=par)
            dfs(u , v),
            dp[v][0] += dp[u][1],
            dp[v][1] += dp[u][0]+1;
}

void solve(int v , int par = 0 , int even = 0 ,int odd = 0){
    ll sum[] =  {even , odd};
    for(auto u : adj[v])
        if(u!=par)
            sum[1]+=dp[u][0]+1,
            sum[0]+=dp[u][1];
    ll cnt = n - sum[1] + sum[0];
    for(auto u : adj[v])
        if(u!=par)
            cnt+=(dp[u][1]-1-dp[u][0])*(sum[0] + sum[1] - dp[u][0] - dp[u][1] - 1);
    cnt = (cnt + (even - odd) * (sum[0]+sum[1] -even - odd))%mod;
    ans = (ans + cnt*a[v]%mod + 100LL * mod)%mod;
    for(auto u : adj[v])
        if(u!=par)
            solve(u , v , sum[1] - dp[u][0]-1 , sum[0] - dp[u][1]+1);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1 ; i < n ; i ++ ){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    solve(1);
    cout << ans;
    return(0);
}