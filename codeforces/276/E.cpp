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

int n , q , cur = 1;
vector < int > adj[maxn];
int h[maxn];
int down[maxn];
int name[maxn];
int fen[maxn][2];

void dfs(int v = 1 , int par = 0){
    name[v] = cur ++;
    if(v>1)h[v] = h[par]+1;
    down[v] = h[v];
    for(auto u : adj[v]){
        if(u == par) continue;
        dfs(u , v);
        down[v] = max(down[v] , down[u]);
    }
}

void add(int l , int r , int x , int id = 0){
    for(;l<maxn;l += l & (-l))fen[l][id]+=x;
    r++;
    for(;r<maxn;r += r & (-r))fen[r][id]-=x;
}

int get(int pos , int id = 0){
    int sum = 0;
    for(;pos;pos-=pos&(-pos))
        sum+=fen[pos][id];
    return(sum);
}

int main(){
    migmig
    cin >> n >> q;
    for(int i =1 ; i < n ; i ++){
        int u ,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    while(q -- ){
        int t;
        cin >> t;
        if(t%2){
            int v; 
            cin >> v;
            if(v == 1)cout << fen[0][1] << endl;
            else
                cout << get(h[v] , 1) + get(name[v]) << endl;
        }
        else{
            int v , x , d;
            cin >> v >> x >> d;
            if(v == 1){
                fen[0][1]+=x;
                add(1 , d , x , 1);
                continue;
            }
            int bz = d - h[v];
            int gz = name[v] - h[v] + 1;
            if(bz >= 0)fen[0][1] += x;
            if(bz > 0){
                add(1 , bz , x ,1);
                add(gz , name[v] - h[v] + min(down[v], bz), -x);
            }
            if(bz < 0)gz = name[v] - d;
            if(h[v] + d > down[v])
                add(gz , down[v] - h[v] + name[v] , x);
            else
                add(gz , name[v] + d , x);
        }
    }
    return(0);
}