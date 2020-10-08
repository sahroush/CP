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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

vector < vector < int >  > adj;
int n , q;
int t = 1;
int sub[maxn] , srt[maxn] , dist[maxn];
int a[maxn];

int odd[maxn] , even[maxn];

int dfs(int v = 1 , int d = 0){
    dist[v] = d;
    srt[v] = t ++;
    sub[v] = srt[v];
    for(auto u : adj[v])
        if(!srt[u])
            sub[v] = dfs(u , d + 1);
    return(sub[v]);
}

void add(int x , int pos , int (&fen)[maxn]){
    for( ; pos < maxn ; pos += pos & -pos)
        fen[pos] += x;
}

int get(int pos , int (&fen)[maxn]){
    int ans = 0;
    for(; pos ; pos -= pos & -pos)
        ans += fen[pos];
    return(ans);
}

int32_t main(){
    migmig
    cin >> n >> q;
    adj.resize(n+1);
    for(int i = 1 ; i <= n ; i ++)  
        cin >> a[i];
    for(int i = 1; i < n ;i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    while(q -- ){
        int t;
        cin >> t;
        if(t == 1){
            int u , x;
            cin >> u >> x;
            if(dist[u]%2 == 0)
                x*=-1;
            add(x , srt[u] , odd);
            add(-x , sub[u] + 1 , odd);
            add(-x , srt[u] , even);
            add(x , sub[u] + 1 , even);
        }
        else {
            int u;
            cin >> u;
            if(dist[u]%2)
                cout << get(srt[u] ,odd)+a[u] << endl;
            else
                cout << get(srt[u] , even)+a[u] << endl;
        }
    }
    return(0);
}