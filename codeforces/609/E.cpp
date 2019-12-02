#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =10e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}
struct edge{
    int t  , next;
    ll w;
}e[maxn];
int n, l , m , g[maxn];
vector<int> adj[maxn];
int timer;
vector<int> tin, tout;
vector<vector<int> > up;
bool inmst[maxn];
int par[maxn];
ll ans[maxn];
int depth[maxn] , son[maxn][20] , dad[maxn][20];
int cnt ;
struct yall{
        int x , y, mark , k , w;
}yal[maxn];

bool cmp(yall i , yall j){
    return(i.w < j.w);
}

void dfs2(int v){
    for(int i=1;i<20;i++){
        dad[v][i]=dad[dad[v][i-1]][i-1];
        son[v][i]=max(son[dad[v][i-1]][i-1],son[v][i-1]);
    }
    for(int i=g[v];i;i=e[i].next){
        if(!depth[e[i].t]){
            depth[e[i].t]=depth[v]+1;
            dad[e[i].t][0]=v;
            son[e[i].t][0]=e[i].w;
            dfs2(e[i].t);
        }
    }
}

void add(int x,int y,int z){
    e[++cnt].t=y;
    e[cnt].w=z;
    e[cnt].next=g[x];
    g[x]=cnt;
}

int getpar(int v){
    if(par[v] == v){
        return(v);
    }
    par[v] = getpar(par[v]);
    return(par[v]);
}


void dfs(int v, int p){
    tin[v] = ++timer;
    //cout << v;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
        //cout << l << '\t';
    }
    for (int i = 0 ; i < adj[v].size() ; i ++) {
        int u = adj[v][i];
        if(v == 3){
            //cout << u;
        }
        if (u!=p){
            dfs(u, v);
        }
    }
    //cout << v;
    tout[v] = ++timer;
    //cout << v;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

bool cmp2(yall i , yall j){
    return(i.k < j . k );
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);

    //cout << 2;s
}

int pht(int x,int y){
    int h=depth[x]-depth[y],mx=0;
    for(int i = 0 ; h ; i ++){
        if(h & 1){
            mx=max(mx,son[x][i]);
            x=dad[x][i];
        }
        h>>=1;
    }
    return mx;
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 1 ;i <= m; i ++){
        int x , y , w;
        cin >> x >> y >> w;
        yal[i].x = x , yal[i].y = y , yal[i].k = i , yal[i].w = w;
    }
    sort(yal + 1 , yal + m + 1, cmp);
    for (int i =1 ; i <= n ; i ++){
        par[i ] = i ;
    }
    for (int i = 1 ; i <= m ; i ++){
        if(getpar(yal[i].x) != getpar(yal[i].y)){
            yal[i].mark = 1;
            int x = yal[i].x , y = yal[i].y;
            adj[x].pb(y);
            //cout << 2;
            adj[y].pb(x);
            //cout << 2;
            par[par[yal[i].x]] = par[yal[i].y];
            add(yal[i].x , yal[i].y , yal[i].w);
            add(yal[i].y , yal[i].x , yal[i].w);
        }
    }
    //cout << 2;
    for (int i = 1 ; i <= m ; i ++){
        if(yal[i].mark){
            ans[getpar(yal[i].x)]+=yal[i].w;
        }
    }

    for (int i = 1 ; i <= n ; i ++){
        if(depth[i] == 0){
            son[i][0]  = 1e6;
            dad[i][0] = i;
            depth[i] = 1;
            dfs2(i);
        }
    }
    //cout << 2;
    sort(yal +1,yal + m + 1 , cmp2 );
    //cout << 2;
    preprocess(1);
    //cout << 2;
    for (int i = 1 ; i <= m ; i ++){
        int x = yal[i].x , y = yal[i] . y;
        int lc = lca(x , y);
        if(yal[i].mark){
            cout << ans[getpar(x)] << endl;
        }
        else{
            ll mx = max(pht(x , lc) , pht(y , lc));
            //cout << lc << endl;
            cout << (ll)ans[getpar(x)] - mx + yal[i].w << endl;
        }
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
