#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e5;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

int n , q;
int par[maxn][50];
vector <int> adj[maxn];
int h[maxn];

void dfs(int v=1){
    for (auto u : adj[v]){
        h[u] = h[v]+1;
        dfs(u);
    }
}

int lca(int u , int v){
    if(h[u] > h[v]){
        swap(u , v);
    }
    for (int i = 35 ; i >= 0 ; i --){
        if(par[v][i] and h[par[v][i]]>=h[u]){
            v = par[v][i];
        }
    }
    if(v == u){
        return(v);
    }
    for (int i = 35 ; i >= 0 ; i --){
        if(par[v][i] != par[u][i]){
            v = par[v][i] , u = par[u][i];
        }
    }
    if(par[u][0]!=par[v][0]){
        return(-1);
    }
    return(par[v][0]);
}

int dist(int u , int v){
    int lc = lca(u , v);
    return(abs(h[u] - h[lc]) + abs(h[v] - h[lc]));
}

int solve(int a , int b , int c){
    return(abs(dist(a , c) + dist(b , c) - dist(a , b))/2+1);
}

int main(){
    migmig
    cin >> n >> q;
    for (int i=2; i <= n ; i ++){
        cin >> par[i][0];
        adj[par[i][0]].pb(i);
    }
    for (int j = 1 ; j < 40 ;j ++ ){
        for (int i = 1 ; i <= n ; i ++){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    dfs();
    while(q -- ){
        int a[3];
        int mx = 0;
        for (int i = 0 ; i < 3 ; i ++){
            cin >> a[i];
        }
        int b[] = {0 , 1 , 2};
        for (int i = 0 ; i < 6 ; i ++){
            mx = max(mx , solve(a[b[0]] , a[b[1]] , a[b[2]]));
            next_permutation(b , b + 3);
        }
        cout << mx << endl;
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
