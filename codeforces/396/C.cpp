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

vector < int > adj[maxn];
int srt[maxn] , sub[maxn] , t = 1;
int n , q;
int fen[maxn] , dick[maxn];
int h[maxn];

void add(int x  , int pos , int (&fen)[maxn]){
    for(pos += 5; pos < maxn ; pos += pos & -pos)
        fen[pos] = (fen[pos] + x)%mod;
}

int get(int pos , int (&fen)[maxn]){
    int sum = 0;
    for(pos += 5 ; pos ; pos -= pos & -pos)
        sum = (sum + fen[pos])%mod;
    return(sum);
}

void dfs(int v = 1){
    srt[v] = sub[v] = t ++;
    for(auto u : adj[v])
        h[u] = h[v]+1 , dfs(u) , sub[v] = sub[u];
}

void add(int x , int l , int r , int (&Fen)[maxn]){
    add(x , l , Fen);
    add((-x+mod)%mod , r+1 , Fen);
}

int solve(int v){
    return((get(srt[v] , fen) - ((get(srt[v] , dick) * h[v])%mod) + mod)%mod);
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 2 ; i <= n ; i ++){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    dfs();
    cin >> q;
    while(q --){
        int t , v;
        cin >> t >> v;
        if(t == 1){
            int x , k;
            cin >> x >> k;
            add((x + h[v]*k)%mod , srt[v] , sub[v] , fen);
            add((k)%mod , srt[v] , sub[v] , dick);
        }
        else{
            cout << solve(v) << endl;
        }
    }
    return(0);
}
