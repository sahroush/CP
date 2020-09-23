//*
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
    void reset(){
        adj.clear();
        radj.clear();
        indeg = outdeg = color = mark = 0;
    }
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
        scc_cnt = 1;
        ans.clear();
        while(q.size())q.pop();
        edge.clear();
        for(int i = 1 ; i <= n ; i ++)
            V[i].reset();
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
    void scc(int n ){
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
            V[i].radj.resize(unique(V[i].radj.begin() , V[i].radj.end())-V[i].radj.begin()),
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

int n , p , mx , m;
digraph d;

int32_t main(){
    migmig
    cin >> n >> p >> mx >> m;
    d.n = mx + p;
    for(int i = 0 ; i < n ; i ++){
        int x , y;
        cin >> x >> y;
        d.add_edge(x , y + d.n);
        d.add_edge(y , x + d.n);
    }
    for(int i = 1 ; i <= p ; i ++){
        int l , r;
        cin >> l >> r;
        d.add_edge(p + l , i);
        d.add_edge(i+d.n , p+l+d.n);
        if(r < mx){d.add_edge(p + r + 1 + d.n , i);
        d.add_edge(i+d.n , p + r + 1 );}
    }
    for(int i = 0 ; i < m ; i ++){
        int x , y;
        cin >> y >> x;
        d.add_edge(x + d.n , y);
        d.add_edge(y + d.n , x);
    }
    for(int i = 1 ; i < mx ; i ++){
        d.add_edge(i + p , i + p + 1);
        d.add_edge(i + p + 1 + d.n , i + p + d.n);
    }
    if(!d.sat())
        dokme(-1);
    vector < int > ans;
    int f = 0;
    for(int i : d.ans)
        if(i <= p)
            ans.pb(i);
        else
            f = max(f , i - p);
    cout << ans.size() << ' ' << f << endl;
    for(int i : ans)
        cout << i << ' ';
    return(0);
}