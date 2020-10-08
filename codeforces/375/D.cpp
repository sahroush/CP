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

const ll maxn  = 1e5 + 10;
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
int c[maxn], a[maxn];
vector < int > adj[maxn];
int l[maxn] , r[maxn] , t = 1;
int fen[maxn];
int cnt[maxn];

void add(int x , int pos){
    for(pos += 5 ; pos < maxn ; pos += pos & -pos)
        fen[pos] += x;
}

int get(int pos){
    int ans = 0;
    for(pos += 5; pos ; pos -= pos & -pos)
        ans += fen[pos];
    return(ans);
}

int get(int l ,int r){
    return(get(r) - get(l - 1));
}

struct qu{
    int l , r , k , ans , ind;
}q[maxn];

void dfs(int v = 1, int par = 0){
    c[t] = a[v] ,  r[v] = l[v] = t ++;
    for(auto u : adj[v]) if(u!=par)
        dfs(u , v) , r[v] = r[u];
}

int sq = 320;

bool cmp(qu i , qu j){
    if(i.l / sq == j.l / sq) return(i.r > j.r);
    return(i.l / sq < j.l / sq);
}
int ans[maxn];

int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1 ; i < n ; i ++){
        int u ,  v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    for(int i = 1 ; i <= m ; i ++)
        cin >> q[i].l >> q[i].k , q[i].ind = i , q[i].r = r[q[i].l] , q[i].l = l[q[i].l];
    sort(q + 1 , q + m + 1 , cmp);
    cnt[c[1]] = 1;
    add(1 , 1);
    int l = 1 , r = 1;
    for(int i = 1;  i <= m ; i ++){
        while(r < q[i].r){
            r ++ ;
            add(-1 , cnt[c[r]]);
            cnt[c[r]] ++;
            add(1 , cnt[c[r]]);
        }
        while(l > q[i].l){
            l -- ;
            add(-1 , cnt[c[l]]);
            cnt[c[l]] ++;
            add(1 , cnt[c[l]]);
        }
        while(r > q[i].r){
            add(-1 , cnt[c[r]]);
            cnt[c[r]] -- ;
            add(1 , cnt[c[r]]);
            r -- ;
        }
        while(l < q[i].l){
            add(-1 , cnt[c[l]]);
            cnt[c[l]] -- ;
            add(1 , cnt[c[l]]);
            l++;
        }
        ans[q[i].ind] = get(q[i].k , n);
    }
    for(int i = 1; i <= m ; i ++)
        cout << ans[i] << endl;
    return(0);
}