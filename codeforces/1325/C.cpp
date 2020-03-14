#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =2e6;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

int n;
vector < int > adj[maxn];
int par[maxn];
pii e[maxn];
map < pii , int > ans;
int dist[maxn];
bool mark[maxn];
int mx = 0;
int l , r;
queue< int > q;

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i < n ; i ++){
        int u  , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        e[i] = {u , v};
    }
    q.push(1);
    par[1] = 0;
    mark[1] = 1;
    if(n == 2){
        dokme(0);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adj[v]){
            if(!mark[u]){
                dist[u] = dist[v]  +1;
                if(dist[u] > dist[mx]){
                    mx = u;
                }
                par[u] = v;
                mark[u] = 1;
                q.push(u);
            }
        }
    }
    l = mx;
    ans[{mx , par[mx]}] = ans[{par[mx] , mx}] = 1;
    ms(dist , 0);
    ms(mark , 0);
    q.push(mx);
    mark[mx] = 1;
    par[mx] = 0;
    vector < int > leaf;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        bool f = 1;
        for (auto u : adj[v]){
            if(!mark[u]){
                f = 0;
                dist[u] = dist[v]  +1;
                if(dist[u] > dist[mx]){
                    mx = u;
                }
                par[u] = v;
                mark[u] = 1;
                q.push(u);
            }
        }
        if(f){
            leaf.pb(v);
        }
    }
    r = mx;
    ans[{mx , par[mx]}] = ans[{par[mx] , mx}] = 0;
    int cur = 2;
    if(1){
        for (int i = 0 ; i < leaf.size() ; i ++){
            if(leaf[i]!=l and leaf[i]!=r){
                mx = leaf[i];
                ans[{mx , par[mx]}] = ans[{par[mx] , mx}] = 2;
                cur++;
                break;
            }
        }
    }
    for (int i = 1 ; i < n ; i ++){
        if(!ans.count(e[i])){
            ans[e[i]] = cur++;
        }
        cout << ans[e[i]] << endl;
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
