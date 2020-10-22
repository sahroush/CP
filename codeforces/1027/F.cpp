/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e6+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];
int b[maxn];
int A[maxn] , B[maxn];
bitset < maxn > mark;
bitset < maxn > Mark;
int par[maxn] , sz[maxn];
int d[maxn];

int getpar(int v){
    return((v == par[v])?v : par[v] = getpar(par[v]));  
}

vector < pii > adj[maxn];

vector < int > vec;

int comp(int x){
    return(lower_bound(vec.begin()  , vec.end() , x ) - vec.begin());
}

void merge(int v , int u){
    v = getpar(v) , u = getpar(u);
    d[v] ++;
    if(v == u)return;
    if(sz[v] < sz[u])
        swap(u , v);
    sz[v] += sz[u];
    d[v] += d[u];
    par[u] = v;
}

bool dfs(int v , int x){
    if(mark[v])return(1);
    mark[v] = 1;
    bool ok = 1;
    if(!Mark[A[v]] and a[v] <= x){
        Mark[A[v]] = 1;
        for(auto [u ,w] : adj[A[v]]){
            ok &= dfs(w , x);
            if(!ok)
                return(0);
        }
        return(ok);
    }
    else if(!Mark[B[v]] and b[v] <= x){
        Mark[B[v]] = 1;
        for(auto [u , w] : adj[B[v]]){
            ok &= dfs(w , x);
            if(!ok)
                return(0);
        }
        return(ok);
    }
    return(0);
}

bool solve(int x){
    x = vec[x - 1];
    Mark = mark = 0;
    ms(d , 0);
    bool ok = 1;
    for(int i = 0 ; i < n ; i ++)if(!mark[i]){
        if(a[i] <= x and b[i] <= x)
            continue;
        else{
            ok&=dfs(i , x);
            if(!ok)
                return(0);
            }
    }
    for(int i = 0 ; i < vec.size() ; i ++){
        sz[i] = 1 , par[i] = i;
    }
    for(int i = 0 ; i < n ; i ++)
        if(!mark[i])
            merge(A[i] , B[i]);
    for(int i = 0 ; i < n ; i ++){
        if(!mark[i] and d[getpar(A[i])] > sz[getpar(A[i])])
            return(0);
    }
    return(ok);
}

void add(int u , int v,  int w){
    adj[u].pb({v , w});
    adj[v].pb({u , w});
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i] >> b[i] , vec.pb(a[i]) , vec.pb(i[b]);
    sort(vec.begin() , vec.end());
    vec.resize(unique(vec.begin() , vec.end()) - vec.begin());
    int l = 0 , r = vec.size();
    for(int i = 0 ; i < n ; i ++)
        A[i] = comp(a[i]) , B[i] = comp(b[i]);
    for(int i = 0 ; i < n ; i ++){
        add(A[i] , B[i] , i);
    }
    if(!solve(r))
        dokme(-1);
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(solve(mid))
            r = mid;
        else
            l = mid;
    }
    cout << vec[r - 1];
    return(0);
}