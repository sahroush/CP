#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5;
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

struct adj{
    int u , v;
    bool working;
}e[maxn];

int n , m;
vector < int > adj[maxn];
int par[maxn] , dist1[maxn] , distn[maxn] , val[maxn];
bool mark[maxn];
queue < int > q;
map < pii , bool > mp;
int cnt = 0;

int main(){
    //migmig
    cin >> n >> m;
    for (int i = 0 ;i  < m ; i++){
        int u , v;
        bool f;
        cin >> u >> v >> f;
        e[i].u = u , e[i].v = v , e[i].working = f;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[pii(u , v)] = mp[pii(v , u)] = f;
    }
    dist1[1] = 0;
    mark[1] = 1;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if(!mark[v]){
                mark[v] = 1;
                q.push(v);
                dist1[v] = dist1[u] + 1;
            }
        }
    }
    ms(mark , 0);
    distn[n] = 0;
    mark[n] = 1;
    q.push(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if(!mark[v]){
                mark[v] = 1;
                q.push(v);
                distn[v] = distn[u] + 1;
            }
        }
    }
    ms(mark , 0);
    val[1] = 0;
    mark[1] = 1;
    par[1] = -1;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : adj[v]){
            if(dist1[u] + distn[u] !=dist1[1] + distn[1]) continue;
            if(dist1[u] ==dist1[v] + 1){
                if(val[u] < val[v] + mp[pii(u , v)]){
                    par[u] = v;
                }
                val[u] = max(val[u] , val[v] + mp[pii(u , v)]);
                if(!mark[u]){
                    if(val[u] == val[v] + mp[pii(u , v)]){
                        par[u] = v;
                    }
                    mark[u]=1;
                    q.push(u);
                }
            }
        }
    }
    mp.clear();
    int pos = n;
    while(par[pos]!=-1){
        mp[pii(pos , par[pos])] = mp[pii(par[pos] , pos)] = 1;
        pos = par[pos];
    }
    for (int i = 0 ; i < m ; i ++){
        if(!e[i].working and mp[pii(e[i].u , e[i].v)]){
            cnt++;
        }
        if(e[i].working and !mp[pii(e[i].u , e[i].v)]){
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0 ; i < m ; i ++){
        if(!e[i].working and mp[pii(e[i].u , e[i].v)]){
            cout << e[i].v << ' ' << e[i].u << ' ' << 1 << endl;
        }
        if(e[i].working and !mp[pii(e[i].u , e[i].v)]){
            cout << e[i].v << ' ' << e[i].u << ' ' << 0 << endl;
        }
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
