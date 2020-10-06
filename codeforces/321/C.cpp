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

const ll maxn  = 1e5+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
set < int > adj[maxn];
int ans[maxn];
vector < int > cur;
bool mark[maxn];
int sz[maxn];
int mx[maxn];

void dfs(int v){
    mark[v] = 1;
    sz[v] = 1;
    cur.pb(v);
    for(auto u : adj[v])
        if(!mark[u])
            dfs(u) , mx[v] = max(mx[v] , sz[u]) , sz[v] += sz[u];
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[v].insert(u) , adj[u].insert(v);
    }
    fill(ans , ans + maxn , -1);
    int cnt = 0;
    int color = 0;
    while(cnt != n){
        ms(mark , 0);
        ms(mx , 0);
        ms(sz , 0);
        for(int i = 1 ; i <= n ; i ++){
            if(ans[i] > -1)continue;
            if(mark[i]) continue;
            cur.clear();
            dfs(i);
            int comp = cur.size();
            int mn = cur[0];
            for(int i : cur){
                mx[i] = max(mx[i] , comp - sz[i]);
                if(mx[i] < mx[mn]) mn = i;
            }
            ans[mn] = color;
            for(auto u : adj[mn])
                adj[u].erase(mn);
            adj[mn].clear();
            cnt++;
        }
        color ++;
    }
    for(int i = 1; i <= n ; i ++)
        cout << char('A' + ans[i]) << ' ';
    return(0);
}