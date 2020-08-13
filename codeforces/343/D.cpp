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

int timee = 0;
int st[maxn];
int fn[maxn];
int n , q;
vector < int > adj[maxn];
int seg[maxn] , sag[maxn];

void dfs(int v = 1 , int par = 0){
    st[v] = timee++;
    for(auto u : adj[v])
        if(u!=par)
            dfs(u , v);
    fn[v] = timee;
}

void up(int u , int val ,  int v = 1, int l = 0 ,int r = n){
    if(r <= st[u] or l >= fn[u])return;
    if(l>=st[u] and r<=fn[u]){
        seg[v] = val;
        return;
    }
    up(u, val , 2*v , l , (l+r)/2);
    up(u, val , 2*v+1 , (l+r)/2 , r);
}

void date(int u , int val , int v = 1, int l = 0 , int r = n ){
    sag[v] = val;
    if(r - l == 1)return;
    if(st[u] < (r+l)/2)date(u, val , 2*v , l , (l+r)/2);
    else date(u, val , 2*v+1 , (l+r)/2 , r);
}

int que(int u , int v = 1 ,int l = 0 , int r = n){
    if(r - l == 1)return(seg[v]);
    if(st[u] < (r+l)/2)
        return(max(seg[v] , que(u , 2*v , l , (r+l)/2)));
    else
        return(max(seg[v] , que(u , 2*v+1 , (r+l)/2 , r)));
}

int ry(int u , int v = 1 ,int l = 0 , int r = n){
    if(r <= st[u] or l >= fn[u])return(-1);
    if(l>=st[u] and r<=fn[u]) return(sag[v]);
    return(max(ry(u , 2*v , l , (r+l)/2) , ry(u , 2*v+1 ,(r+l)/2 , r)));
}

int main(){
    migmig
    cin >> n ;
    for(int i = 1; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    cin >> q;
    int cnt = 0;
    while(q --){
        cnt++;
        int t , v;
        cin >> t >> v;
        if(t == 1)
            up(v , cnt);
        else if(t == 2)
            date(v , cnt);
        else
            cout << bool(que(v) > ry(v)) << endl;
    }
    return(0);
}