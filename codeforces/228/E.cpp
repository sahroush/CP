/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 300;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , cur = 1;
vector < int > adj[maxn], radj[maxn] , order;
int mark[maxn] , c[maxn];

void sfd(int v){
    c[v] = cur;
    for (auto u : adj[v])
        if(!c[u])
            sfd(u);
}

void dfs(int v){
    mark[v] = 1;
    for (auto u : adj[v])
        if(!mark[u])
            dfs(u);
    order.pb(v);
}

vector < int > ans;
int indeg[maxn];
queue < int > q;

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        // -i = i , i = i + n
        int u , v , c;
        cin >> u >> v >> c;
        if(c){
            adj[u].pb(v);
            adj[v].pb(u);
            adj[v + n].pb(u+n);
            adj[u+n].pb(v + n);
        }
        else{
            adj[v].pb(u + n);
            adj[u].pb(v + n);
            adj[v+n].pb(u);
            adj[u+n].pb(v);
        }
    }
    ms(mark , 0);
    for (int i = 1 ; i <= n+n ; i ++)
        if(!mark[i])
            dfs(i);
    reverse(order.begin() , order.end());
    for (int i = 0 ; i < n+n ; i ++)
        if(c[order[i]] == 0)
            sfd(order[i]),
            cur++;
    cur--;
    for(int i = 1 ; i <= n+n ; i ++)
        if(c[i] == c[i + n])
            dokme("Impossible")
    order = vector < int > (maxn, 0);
    
    for(int i = 1 ; i <= cur ; i ++ )radj[i].clear();
    for(int i = 1 ; i <= n+n ; i ++ )
        for(auto u : adj[i])
            if(c[i]!=c[u])
                radj[c[u]].pb(c[i]);
    for(int i = 1 ; i <= cur ; i ++)
        sort(radj[i].begin() , radj[i].end()),
        radj[i].resize(unique(radj[i].begin() , radj[i].end())-radj[i].end()),
        indeg[i] = (int)radj[i].size();
    for(int i = 1 ; i <= cur ; i ++) adj[i].clear();
    for(int i = 1 ; i <= cur ; i ++) for(auto u : radj[i]) adj[u].pb(i);
    for(int i = 1 ; i <= cur ; i ++) if(indeg[i] == 0) q.push(i);
    cur = 1;
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        order[v] = cur ++;
        for(auto u : adj[v]){
            indeg[u]--;
            if(indeg[u] == 0)
                q.push(u);
        }
    }
    for(int i = 1 ; i <= n ; i ++)
        if(order[c[i]] < order[c[i+n]])
            ans.pb(i);
    cout << ans.size() << endl;
    for(auto u : ans)
        cout << u << ' ';
    return(0);
}