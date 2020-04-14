#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("stupid_rmq.in", "r+", stdin); freopen("stupid_rmq.out", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m  , k;
int dp[1050][2];
int val[maxn] , w[maxn];
int par[maxn] , sz[maxn] , wsum[maxn] , valsum[maxn];
bool mark[maxn];
vector < int > vec[1050];

int getpar(int v){
    return((v == par[v])?v : par[v] = getpar(par[v]));
}

void merge(int u , int v){
    u = getpar(u);
    v = getpar(v);
    if(u == v){
        return;
    }
    if(sz[u] > sz[v]){
        swap(u , v);
    }
    sz[v]+=sz[u];
    par[u] = v;
    valsum[v]+=valsum[u];
    wsum[v]+=wsum[u];
}

void solve(int x){
    for(int i = 1 ; i <= k ; i ++){
        for(int j : vec[x]){
            if(w[j] <= i){
                dp[i][1] = max(dp[i][1] , dp[i - w[j]][0] + val[j]);
            }
        }
        if(wsum[x] <= i){
            dp[i][1] = max(dp[i][1] , dp[i - wsum[x]][0] + valsum[x]);
        }
    }
    for(int i = 1 ; i <= k ; i ++){
        dp[i][0] = dp[i][1];
        dp[i][0] = max(dp[i][0] , dp[i-1][0]);
    }
}

int main(){
    migmig
    ms(dp , 0);
    cin >> n >> m >> k;
    for(int i =1 ; i <= n ; i ++){
        cin >> w[i];
    }
    for(int i = 1 ; i<= n ; i ++){
        cin >> val[i];
        valsum[i] = val[i];
        wsum[i] = w[i];
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        merge(u , v);
    }
    for(int i = 1 ; i <= n ; i ++){
        vec[getpar(i)].pb(i);
    }
    for(int i = 1 ; i<= n ; i ++){
        if(!mark[getpar(i)]){
            mark[getpar(i)] = 1;
            solve(getpar(i));
        }
    }
    cout << dp[k][0];
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
