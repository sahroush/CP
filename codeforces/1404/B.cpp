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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
int a , b , da , db;
vector < int > adj[maxn];

int dist(int v ,int u , int par = 0){
    if(u == v)
        return(0);
    int mx = -1e9;
    for(auto n : adj[v])
        if(n!=par)
            mx = max(mx , dist(n , u , v) + 1);
    return(mx);
}

pii dfs(int v , int par = 0){
    pii mx = {-1  , v};
    for(auto u : adj[v])
        if(u != par)
            mx = max(mx , dfs(u , v));
    mx.first ++;
    return(mx);
}

int32_t main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n >> a >> b >> da >> db;
        for(int i = 1 ; i <= n ; i ++)
            adj[i].clear();
        for(int i = 1 ; i < n ; i ++){
            int u , v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if(dist(a , b) <= da){
            cout << "Alice" << endl;
            continue;
        }
        int u = dfs(1).second;
        int v = dfs(u).second;
        int r = (dist(u , v) + 1)/2;
        if(r <= da){
            cout << "Alice" << endl;
            continue;
        }
        if(db > 2*da){
            cout << "Bob" << endl;
            continue;
        }
        cout << "Alice" << endl;
    }
    return(0);
}