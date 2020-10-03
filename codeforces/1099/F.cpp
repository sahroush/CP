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

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , t;
vector < int > x , c , dist;
vector < vector < pii >  > adj;
int num[maxn];
int dp[maxn];
int cnt[maxn] , val[maxn];
int cont[maxn];

void add(int x , int pos , int (&fen)[maxn]){
    for(; pos < maxn ;pos += pos & -pos)
        fen[pos] += x;
}

int get(int pos , int (&fen)[maxn]){
    int ans = 0;
    for(; pos ;pos -= pos & -pos)
        ans += fen[pos];
    return(ans);
}

void calc(int v){
    int sum = t - dist[v]*2LL;
    int pos = 0;
    int ans = 0;
    for(int i = 19 ; i >= 0 ; i --){
        pos^=(1 << i);
        if(ans + val[pos] <= sum){
            ans += val[pos];
            continue;
        }
        pos^=(1 << i);
    }
    num[v] = get(pos , cnt);
    sum -= ans;
    pos++;
    num[v] += min(cont[pos] , sum/pos);
}

int dfs3(int v = 1){
    vector < int > vec;
    vec.pb(num[v]);
    for(auto [u , w] : adj[v])
        vec.pb(dfs3(u));
    sort(vec.begin() , vec.end());
    reverse(vec.begin() , vec.end());
    if(vec.size() == 1 or v == 1)return(vec[0]);
    return(max(vec[1] , num[v]));
}

void dfs2(int v = 1){
    add(x[v] , c[v] , cnt);
    add(x[v]*c[v] , c[v] , val);
    cont[c[v]] += x[v];
    calc(v);
    for(auto [u , w] : adj[v])
        dfs2(u);
    cont[c[v]] -= x[v];
    add(-x[v] , c[v] , cnt);
    add(-x[v]*c[v] , c[v] , val);
}

void dfs1(int v = 1 , int d = 0){
    dist[v] = d;
    for(auto [u , w] : adj[v])
        dfs1(u , d + w);
}

int32_t main(){
    migmig
    cin >> n >> t;
    adj.resize(n+1);x.resize(n+1);
    c.resize(n+1);dist.resize(n+1);
    for(int i = 1 ; i <= n ; i ++)
        cin >> x[i];
    for(int i = 1 ; i <= n ; i ++)
        cin >> c[i];
    for(int i = 2 ; i <= n ; i ++){
        int v;cin >> v;adj[v].pb({i , 0});
        cin >> adj[v].back().second;
    }
    dfs1();
    dfs2();
    cout << dfs3();
    return(0);
}
