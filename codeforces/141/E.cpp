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

const ll maxn  = 1e3+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct edge{
    int from;
    int to;
    int ind;
};

int n , m;
vector < edge > adj[maxn][2] , edg[2]; 
vector < int > ans;
int mark[maxn];

int connected(int v = 1){
    int cnt = 1;
    mark[v] = 1;
    for(auto e : adj[v][0])
        if(!mark[e.to])
            cnt += connected(e.to);
    for(auto e : adj[v][1])
        if(!mark[e.to])
            cnt += connected(e.to);
    return(cnt);
}

int par[maxn] , sz[maxn];
int par2[maxn] , sz2[maxn];

int getpar(int v){
    return((v == par[v])?v:par[v]=getpar(par[v]));
}

void init(){
    for(int i = 0 ; i < maxn ; i ++)
        par[i] = i , sz[i] = 1;
}

void merge(int u ,int v){
    u = getpar(u) , v = getpar(v);
    if(u == v)return;
    if(sz[u] > sz[v])swap(u , v);
    par[u] = v;
    sz[v] += sz[u];
}

int getpar2(int v){
    return((v == par2[v])?v:par2[v]=getpar2(par2[v]));
}

void init2(){
    for(int i = 0 ; i < maxn ; i ++)
        par2[i] = i , sz2[i] = 1;
}

void merge2(int u ,int v){
    u = getpar2(u) , v = getpar2(v);
    if(u == v)return;
    if(sz2[u] > sz2[v])swap(u , v);
    par2[u] = v;
    sz2[v] += sz2[u];
}

void color(int v , int pr = -1){
    if(pr == -1 ) pr = v;
    merge(v , pr);
    mark[v] = 1;
    for(auto e : adj[v][0])
        if(!mark[e.to])
            color(e.to , v);
}

int cntb = 0 , cntw = 0;

void add(edge e){
    merge(e.to, e.from);
    merge2(e.to, e.from);
    ans.pb(e.ind);
}


int32_t main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i ++){
        edge e;
        cin >> e.from >> e.to; 
        e.ind = i;
        string type;
        cin >> type;
        if(e.from == e.to)  
            continue;
        int t = (type == "M");
        adj[e.from][t].pb(e);
        swap(e.from , e.to);
        adj[e.from][t].pb(e);
        edg[t].pb(e);
    }
    if(!(n%2))
        dokme(-1);
    if(n == 1)
        dokme(0);
    if(connected()!=n)
        dokme(-1);
    int cnt = 0;
    ms(mark , 0);
    init();
    for(int i = 1 ; i <= n ; i ++)
        if(!mark[i])
            cnt ++ , color(i);
    int k = n/2;
    // cnt = x+1 --> siah >= x --> siah = k --> x <= k --> x+1 <= k+1 --> cnt <= k+1
    if(cnt > k+1)
        dokme(-1);
    init2();
    for(auto i : edg[1])
        if(getpar(i.to)!=getpar(i.from))
            add(i) , cntb ++;
    for(auto i : edg[1])
        if(getpar2(i.to)!=getpar2(i.from) and cntb < k)
            add(i) , cntb ++;
    if(cntb!=k)
        dokme(-1);
    for(auto i : edg[0])
        if(getpar2(i.to)!=getpar2(i.from) and cntw < k)
            add(i) , cntw ++;
    if(cntw!=k)
        dokme(-1);
    cout << n-1 << endl;
    for(auto v : ans)
        cout << v << ' ';
    return(0);
}