#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < int > adj[maxn];
int n , m, q, ok[maxn] ,par[maxn][2] ,h[maxn] ,mark[maxn] , start[maxn] , finish[maxn] ,t , good , cnt;

void init(int n){
    h[0] = 1e9 , ok[0]=1;
    for(int i = 1 ; i <= n ; i ++){
        adj[i].clear();
        ok[i]=1;
        par[i][0] = par[i][1] = 0;
        mark[i]=0;
    }
}

void dfs(int v){
    mark[v] = 1;
    start[v] = ++t;
    for(auto u : adj[v])
        if(!mark[u]){
            h[u] = h[v]+1;
            dfs(u);
        }
    finish[v] = ++t;
}

bool chk(int u , int v){
    if(start[u] < start[v] and finish[u] > finish[v] and h[u]+1 == h[v])
        return(1);
    if(start[u] < start[v] and finish[u] > finish[v] and h[u]+1 != h[v])
        return(0);
    if(start[v] < start[u] and finish[v] > finish[u]){
        return(1);
    }
    return(0);
}

void merge(int v , int u){
    if(u==v)return;
    if(h[par[v][1]] > h[u])par[v][1]=u;
    if(h[par[v][0]] > h[par[v][1]])swap(par[v][0] , par[v][1]);
}

bool check(int v){
    fill(mark , mark + n + 1 , 0);
    h[v] = 0;
    t = 0;
    dfs(v);
    for(int i = 1 ; i <= n ; i ++){
        cnt = 0;
        for(auto u : adj[i])
            if(!chk(i, u))
                return(0);
    }
    return(1);
}

void solve(int v){
    mark[v] = 1;
    for(auto u : adj[v])
        if(mark[u])
            merge(v , u);
        else
            solve(u) , merge(v , par[u][0]) , merge(v , par[u][1]);
    if(par[v][0]!=0 and par[v][1]!=0)ok[v] = 0;
}

void solve2(int v){
    mark[v] = 1;
    ok[v]&=(ok[par[v][0]] & ok[par[v][1]]);
    for(auto u : adj[v])
        if(!mark[u])
            solve2(u);
}

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> m;
        init(n);
        for(int i = 0 ; i < m ; i ++){
            int u , v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        int v;
        for(int i = 0 ; i < 85 ; i ++)
            if(check((v = (rng()%n + 1))))
                break;
        if(!check(v)){
            cout << -1 << endl;
            continue;
        }
        fill(mark , mark + n + 1 , 0);
        solve(v);
        fill(mark , mark + n + 1 , 0);
        solve2(v);
        good = 0;
        for(int i = 1 ; i <= n ; i ++ )good+=ok[i];
        if(good*5 < n){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1 ; i <= n;  i ++)
            if(ok[i])
                cout << i << ' ';
        cout << endl;
    }
    return(0);
}