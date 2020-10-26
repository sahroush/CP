//*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e6+10;
const ld PI = acos((ld)-1);
const int mods[] = {998244353, 1000000007, 696969569, 1000000009, 998244853 };

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll P(ll a, ll b, ll md){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const int k = 5;

int n , m;
vector < int > adj[maxn];
vector < int > h[maxn];
int mod[k];
int pw[maxn][k];

int base[k];

vector < vector < int > > vec;

void calc(int v , int x){
    int ans = 0;
    for(int i : adj[v])
        ans = (ans + (i * pw[i][x])%mod[x])%mod[x];
    h[v].pb(ans);
}

vector < pii > e;

bool sim(int u , int v){
    for(int i = 0 ; i < k ; i ++)
        if(h[u][i]!=h[v][i])
            return(0);
    return(1);
}

bool sim(vector < int >  u , vector < int >  v){
    for(int i = 0 ; i < k ; i ++)
        if(u[i]!=v[i])
            return(0);
    return(1);
}

int32_t main(){
    migmig;
    cin >> n >> m;
    for(int i = 0 ; i < k ; i ++)
        base[i] = rng()%10000 , mod[i] = mods[rng()%5];
    for(int i = 0 ; i < k ; i ++)pw[0][i] = 1;
    for(int i = 1 ; i < maxn ; i ++){
        for(int j = 0 ; j < k ; j ++)
            pw[i][j] = (pw[i-1][j] * base[j])%mod[j];
    }
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        e.pb({u , v});
    }
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 0 ; j < k ; j ++)
            calc(i , j);
        vec.pb(h[i]);
    }
    int ans = 0;
    int cnt = 1;
    sort(vec.begin() , vec.end());
    for(int i = 1 ; i < n ; i ++){
        if(sim(vec[i] , vec[i - 1]))
            cnt++;
        else
            ans += (cnt * (cnt - 1))/2 , cnt = 1;
    }
    ans += (cnt * (cnt - 1))/2;
    for(int i = 1 ; i <= n ; i ++){
        adj[i].pb(i);
        h[i].clear();
        for(int j = 0 ; j < k ; j ++)
            calc(i , j);
    }
    for(auto [u , v] : e){
        if(sim(u , v))
            ans ++;
    }
    cout << ans;
    return(0);
}