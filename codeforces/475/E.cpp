#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =2002;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

int n , res , m;
vector < int > adj[maxn] , vec[maxn];
int mn , mx , cnt = 0;
int low[maxn] , srt[maxn] , ch[maxn];
int par[maxn] , sz[maxn],ans;
bool f[maxn][maxn] , mark[maxn];
bool ct[maxn][maxn];
vector < pii > cct;
pii e[(int)3e5+1];

int getpar(int v){
    return(((v == par[v])?v:par[v]=getpar(par[v])));
}

void merge(int u , int v){
    u = getpar(u) , v = getpar(v);
    if(u == v){
        return;
    }
    par[u] = v;
    sz[v] += sz[u];
}

void dfs(int v , int pr){
    mark[v] = 2;
    ch[v] = sz[v];
    for (auto u : vec[v]){
        if(u == pr){
            continue;
        }
        dfs(u , v);
        ch[v]+=ch[u];
        res+=ch[u]*sz[v];
    }
}

void init(int v , int pr){
    low[v] = srt[v] = ++cnt;
    for (int u : adj[v]){
        if(u == pr){
            continue;
        }
        if(srt[u]){
            low[v] = min(low[v] , srt[u]);
        }
        else{
            init(u , v);
            low[v] = min(low[v] , low[u]);
            if(low[u] == srt[u]){
                cct.pb(make_pair(u , v));
                ct[u][v] = ct[v][u] = 1;
            }
        }
    }
}

int main(){
    //migmig
    cin >> n >> m;
    for (int i = 1; i <= m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        e[i] = {u , v};
    }
    init(1 , 1);
    for (int i = 1 ; i <= n ; i ++){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <=m ; i++){
        if(!ct[e[i].first][e[i].second]){
            merge(e[i].first , e[i].second);
        }
    }
    for (auto i : cct){
        int u = getpar(i.first) , v = getpar(i.second);
        vec[u].pb(v) ;vec[v].pb(u);
    }

    for (int i = 1 ; i <= n ; i ++){
        if(par[i]!=i){
            continue;
        }
        res = 0;
        dfs(i , i);
        ms(mark , 0);
        for (int j = 1 ; j <= vec[j].size() ; j ++){
            for (int k = 0 ; k < maxn ; k ++){
                f[j][k]=0;
            }
        }
        f[0][0]=1;
        for(int j = 1 ; j<= vec[i].size() ; j ++){
            for (int k = 0 ; k < maxn ; k ++){
                f[j][k] = f[j - 1][k];
                if(k >= ch[vec[i][j - 1]]){
                    f[j][k]|=f[j-1][k - ch[vec[i][j - 1]]];
                }
            }
        }
        for (int j = 0 ; j < maxn ; j ++){
            if(f[vec[i].size()][j]){
                ans = max(ans , res + j * (ch[i] - j - sz[i]));
            }
        }
    }
    for (int i = 1 ;  i <= n ; i ++){
        if(getpar(i) == i){
            ans+=sz[i]*sz[i]-sz[i];
        }
    }
    mx = ans;
    cout << mx+n;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
