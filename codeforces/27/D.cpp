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

struct dinode{
    vector < int > adj , radj;
    int indeg = 0 , outdeg = 0;
    int color = 0 , mark = 0;
    int name;
};

struct digraph{
    int n , m;
    dinode V[maxn];
    vector < pii > edge;
    vector < int > order;
    queue < int > q;
    vector < int > ans;
    int scc_cnt = 1;
    void init(){
        for(int i = 1 ; i <= n ; i ++)
            V[i].name = i, V[i].adj.clear(), V[i].radj.clear();
    }
    void add_edge(int v , int u){
        V[v].adj.pb(u);
        V[u].radj.pb(v);
        V[u].indeg++;
        V[v].outdeg++;
        edge.pb({u , v});
    }
    void dfs(int v){
        V[v].mark = 1;
        for (auto u : V[v].adj)
            if(!V[u].mark)
                dfs(u);
        order.pb(v);
    }
    void sfd(int v){
        V[v].color = scc_cnt;
        for (auto u : V[v].radj)
            if(!V[u].color)
                sfd(u);
    }
    void scc(int n){
        for (int i = 1 ; i <= n ; i ++)
            if(!V[i].mark)
                dfs(i);
        reverse(order.begin() , order.end());
        for (int i = 0 ; i < n ; i ++)
            if(V[order[i]].color == 0)
                sfd(order[i]),
                scc_cnt++;
        scc_cnt--;
    }
    
    void topo(int n){
        order = vector < int > (n+10, 0);
        for(int i = 1 ; i <= n ; i ++) if(V[i].indeg == 0) q.push(i);
        int cur = 1;
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            order[v] = cur ++;
            for(auto u : V[v].adj){
                V[u].indeg--;
                if(V[u].indeg == 0)
                    q.push(u);
            }
        }
    }
    
    void make_scc_dag(int n){
        for(int i = 1 ; i <= scc_cnt ; i ++ )V[i].radj.clear();
        for(int i = 1 ; i <= n ; i ++ )
            for(auto u : V[i].adj)
                if(V[i].color!=V[u].color)
                    V[V[u].color].radj.pb(V[i].color);
        for(int i = 1 ; i <= scc_cnt ; i ++)
            sort(V[i].radj.begin() , V[i].radj.end()),
            V[i].radj.resize(unique(V[i].radj.begin() , V[i].radj.end())-V[i].radj.end()),
            V[i].indeg = (int)V[i].radj.size();
        for(int i = 1 ; i <= scc_cnt ; i ++) V[i].adj.clear(), V[i].outdeg = 0;
        for(int i = 1 ; i <= scc_cnt ; i ++) for(auto u : V[i].radj) V[u].adj.pb(i);
        for(int i = 1 ; i <= scc_cnt ; i ++) V[i].outdeg = (int)V[i].adj.size();
    }
    
    bool sat(){
        // -v = v , v = v + n
        scc(n + n);
        for(int i = 1 ; i <= n ; i ++)
            if(V[i].color == V[i + n].color)
                return(0);
        ans.clear();
        make_scc_dag(n + n);
        topo(scc_cnt);
        for(int i = 1 ; i <= n ; i ++)
            if(order[V[i].color] < order[V[i+n].color])
                ans.pb(i);
        return(1);
    }
};

digraph d;
int n , m;
int a[maxn] , b[maxn];

int32_t main(){
    migmig
    cin >> n >> m;
    d.n = m;
    for(int i = 1 ; i <= m ; i ++)
        cin >> a[i] >> b[i];
    for(int i = 1 ; i <= m ; i ++)
        if(a[i] > b[i])swap(a[i], b[i]);
    for(int i = 1 ; i <= m ; i ++)
        for(int j = 1 ; j <= m ; j ++){
            if(a[i] >= a[j] and b[i]<= b[j])continue;
            if(a[j] >= a[i] and b[j]<= b[i])continue;
            if(a[j] >= b[i]) continue;
            if(a[i] >= b[j]) continue;
            d.add_edge(i+m , j);
            d.add_edge(i, j+m);
        }
    if(!d.sat())
        dokme("Impossible");
    string s = "";
    for(int i = 1 ; i <= m ; i ++)
        s += "o";
    for(int i : d.ans)
        s[i-1] = 'i';
    cout << s;
    return(0);
}