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

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int ps[maxn];
vector < pii > adj[maxn];
int par[maxn][20];
int dist[maxn];

void dfs(int v = 1,  int d = 0){
    dist[v] = d;
    for(auto [u , w] : adj[v])
        dfs(u , d + w);
}

void solve(int v = 1){
    for(auto [u , w] : adj[v])
        solve(u);
    for(auto [u , w] : adj[v])
        ps[v] += ps[u];
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 2 ; i <= n ; i ++){
        int p , w;
        cin >> p >> w;
        adj[p].pb({i , w});
        par[i][0] = p;
    }
    dfs();
    for(int i = 1 ; i < 20 ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            par[j][i] = par[par[j][i-1]][i-1];
    for(int i = 1 ; i <= n ; i ++){
        ps[i] ++;
        int pos = i;
        for(int j = 19 ; j >= 0 ; j --){
            if(!par[pos][j])continue;
            if(a[i] < dist[i] - dist[par[pos][j]])continue;
            pos = par[pos][j];
        }
        ps[par[pos][0]] --;
    }
    solve();
    for(int i = 1 ; i <= n ; i ++)
        cout << ps[i]-1 << ' ';
    return(0);
}