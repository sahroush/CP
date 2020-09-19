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

const ll maxn  = 3e5;
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
vector < int > adj[maxn][2];
int cnt = 0;
int mark[maxn];

void dfs(int v , int col = 0){
    mark[v] = 1+col;
    for(auto u : adj[v][0])
        if(!mark[u])
            dfs(u , 1 - col);
        else if(mark[u] == mark[v])
            dokme(0)
    for(auto u : adj[v][1])
        if(!mark[u])
            dfs(u ,col);
        else if(mark[u] != mark[v])
            dokme(0)        
}

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < m; i ++){
        int u , v , c;
        cin >> u >> v >> c;
        adj[u][c].pb(v);
        adj[v][c].pb(u);
    }
    for(int i = 1 ; i <= n ;i ++)
        if(!mark[i])
            cnt++,
            dfs(i);
    cout << pw(2 , cnt - 1);
    return(0);
}