#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct edge{
    int from , to;
    ll w;
}e[maxn];

int n , m , s , t ,ans[maxn];
vector < pll > adj[maxn] , radj[maxn];
set <pll> st;
vector < pii > dag[maxn];
ll dist[maxn] , rdist[maxn];
bool mark[maxn] , indag[maxn];
int dp[maxn];
int h[maxn];
bool cut[maxn];
queue < int > q;


void djk(int start){
    ms(dist , 63);
    dist[start] = 0;
    st.insert(pll(dist[start] , start));
    while(!st.empty()){
        auto v = *st.begin();
        st.erase(v);
        if(mark[v.second]) continue;
        mark[v.second] = 1;
        for (auto u : adj[v.second]){
            if(dist[u.first] > dist[v.second] + u.second){
                dist[u.first] = dist[v.second] + u.second;
                st.insert(pll(dist[u.first] , u.first));
            }
        }
    }
}
void rdjk(int start){
    ms(rdist , 63);
    ms(mark,  0);
    rdist[start] = 0;
    st.insert(pll(rdist[start] , start));
    while(!st.empty()){
        auto v = *st.begin();
        st.erase(v);
        if(mark[v.second]) continue;
        mark[v.second] = 1;
        for (auto u : radj[v.second]){
            if(rdist[u.first] > rdist[v.second] + u.second){
                rdist[u.first] = rdist[v.second] + u.second;
                st.insert(pll(rdist[u.first] , u.first));
            }
        }
    }
}

void build(){
    for(int i = 0 ; i < m ; i ++){
        if(dist[e[i].from] + e[i].w + rdist[e[i].to] == dist[t]){
            dag[e[i].from].pb(pii(e[i].to , i ));
            dag[e[i].to].pb(pii(e[i].from , i ));
            indag[i] = 1;
        }
        if(dist[e[i].from] + 1 + rdist[e[i].to] > dist[t]){
            ans[i] = -1;
        }
    }
}

void dfs(int v , int par = -1){
    dp[v] = h[v];
    mark[v] = 1;
    for (auto u : dag[v]){
        int boz = u.first, indx = u.second;
        if(!mark[boz]){
            h[boz] = h[v] + 1;
            dfs(boz , indx);
            if(dp[boz] > h[v]){
                cut[indx] = 1;
            }
            else{
                dp[v] = min(dp[v] , dp[boz]);
            }
        }
        else if(indx!=par){
            dp[v] = min(dp[v] , h[boz]);
        }
    }
}

int main(){
    migmig
    cin >> n >> m >> s >> t;
    for (int i = 0;  i < m ; i ++){
        int v , u;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb(pll(v , w));
        radj[v].pb(pll(u , w));
        e[i].from = u , e[i].to = v , e[i].w = w;
    }
    djk(s);
    rdjk(t);
    build();
    ms(mark , 0);
    h[s] = 0;
    dfs(s);
    for(int i = 0 ; i < m ; i ++){
        if(ans[i] == -1){
            cout << "NO" << endl;
            continue;
        }
        if(cut[i]){
            cout << "YES" << endl;
            continue;
        }
        if(e[i].w == e[i].w - ((dist[t]-1) - (dist[e[i].from] + rdist[e[i].to]))){
            cout << "NO" << endl;
            continue;
        }
        cout << "CAN " <<  e[i].w - ((dist[t]-1) - (dist[e[i].from] + rdist[e[i].to])) << endl;
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
