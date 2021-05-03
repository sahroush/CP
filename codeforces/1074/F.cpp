#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int a[maxn];
vector < int > adj[maxn] , ans;

int par[maxn][30];
int h[maxn];

struct segment{
    pii seg[maxn * 4];
    int lazy[maxn * 4];
    void build(int v = 1 , int l = 1 , int r = n+1){
        if(r - l == 1){
            seg[v] = {0 , 1};
            return;
        }
        int mid = ( l + r ) / 2;
        build(2*v , l , mid);
        build(2 * v + 1, mid , r);
        seg[v].second = seg[2*v].second + seg[2*v + 1].second;
    }
    void shift(int v , int l , int r ){
        seg[v].first += lazy[v];
        if(r - l > 1)
            lazy[2*v] += lazy[v],
            lazy[2*v + 1] += lazy[v];
        lazy[v] = 0;
    }
    void update(int val , int L , int R , int v = 1 , int l = 1 , int r = n+1){
        shift(v, l , r);
        if(L >= r or l >= R)
            return;
        if(L <= l and r <= R){
            lazy[v] += val;
            shift(v , l , r);
            return;
        }
        int mid = (l + r) / 2;
        update(val , L , R , 2*v , l , mid);
        update(val , L , R , 2*v + 1 , mid , r);
        seg[v] = min(seg[2*v] , seg[2 * v + 1]);
        if(seg[2*v].first == seg[2*v + 1].first) seg[v].second = seg[2*v].second + seg[2*v + 1].second;
    }
    int get(){
        shift(1 , 1 , n + 1);
        if(seg[1].first == 0)
            return(seg[1].second);
        return(0);
    }
}seg;

int l[maxn] , r[maxn] , t = 1;

void dfs(int v){
    l[v] = r[v] = t++;
    for (auto u : adj[v]){
        if(u!=par[v][0]){
            par[u][0] = v;
            h[u] = h[v]+1;
            dfs(u);
            r[v] = r[u];
        }
    }
}

int lca(int u , int v){
    if(h[u] > h[v]){
        swap(u , v);
    }
    for (int i = 25 ; i >= 0 ; i --){
        if(par[v][i] and h[par[v][i]]>=h[u]){
            v = par[v][i];
        }
    }
    if(v == u){
        return(v);
    }
    for (int i = 25 ; i >= 0 ; i --){
        if(par[v][i] != par[u][i]){
            v = par[v][i] , u = par[u][i];
        }
    }
    return(par[v][0]);
}

void init(){
    dfs(1);
    for (int j = 1; j < 28 ; j ++){
        for (int i = 1 ; i <= n ; i ++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int gpar(int v , int dist){
    for(int i = 25 ; i >= 0 ; i --)
        if(dist & (1 << i))
            v = par[v][i];
    return(v);
}

set < pii > e;

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init();
    seg.build();
    while(m -- ){
        int u , v;
        cin >> u >> v;
        if(h[u] < h[v]) swap(u , v);
        if(h[u] == h[v] and u > v) swap(u , v);
        int x = 1;
        if(e.count(pii(u , v))) x = -1 , e.erase(pii(u , v));
        else e.insert(pii(u , v));
        if(lca(u , v) == v)
            seg.update(x , l[gpar(u , h[u] - h[v] - 1)] , r[gpar(u , h[u] - h[v] - 1)] + 1),
            seg.update(-x , l[u] , r[u] + 1);
        else
            seg.update(x , l[1] , r[1] + 1),
            seg.update(-x , l[v] , r[v] + 1),
            seg.update(-x , l[u] , r[u] + 1);
        cout << seg.get() << endl;
    }
    return(0);
}