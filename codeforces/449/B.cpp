#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

const ll maxn =5e5;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

vector <pair < pii , bool> > adj[maxn];
vector < ll > vec[2][maxn];
ll n , m , k;
ll cnt = 0;
map<pii , pair < ll , bool > > mp;
ll par[maxn];
ll dist[maxn];
ll mark[maxn];
set < pii > st;
queue < ll > q;
ll indeg[maxn][2];

void djk(){
    ms(dist , 63);
    dist[1] = 0;
    par[1] = -1;
    st.insert(pii(dist[1] , 1));
    while(!st.empty()){
        auto u = *st.begin();
        st.erase(st.begin());
        if(mark[u.second]){
            continue;
        }
        mark[u.second] = 1;
        for (auto v : adj[u.second]){
            if(mark[v.first.first])continue;
            if(dist[v.first.first] > dist[u.second] + v.first.second){
                par[v.first.first] = u.second;
                dist[v.first.first] = dist[u.second] + v.first.second;
                st.insert(pii(dist[v.first.first] , v.first.first) ) ;
            }
        }
    }
}


int main(){
    migmig
    cin >> n >> m >> k;
    for (int i = 0 ; i < m ; i ++){
        ll u , v;
        ll w;
        cin >> u >> v >> w;
        if(v > u){
            swap(v , u);
        }
        adj[u].pb(make_pair(pii(v , w), 0 ) );
        adj[v].pb(make_pair(pii(u , w) , 0 ) ) ;
        if(mp.count(pii(u , v)) == 0){
            mp[pii(u , v)] = make_pair(w , 0);
        }
        else{
            mp[pii(u , v)].first = min(mp[pii(u , v)].first , w);
        }
    }
    for (int i = 0 ; i < k ; i ++){
        ll u , v = 1;
        ll w;
        cin >> u >> w;
        adj[u].pb(make_pair(pii(v , w), 1 ) );
        adj[v].pb(make_pair(pii(u , w) , 1 ) ) ;
        if(mp.count(pii(u , v)) == 0){
            mp[pii(u , v)] = make_pair(w , 1);
        }
        else{
            if(mp[pii(u , v)].first > w){
                mp[pii(u , v)].second = 1;
            }
            mp[pii(u , v)].first = min(mp[pii(u , v)].first , w);
        }
    }
    djk();
    for (int i = 1 ; i <= n ; i ++){
        for (auto u : adj[i]){
            if(dist[i] + u.first.second == dist[u.first.first]){
                vec[u.second][i].pb(u.first.first);
                indeg[u.first.first][u.second]++;
                //cout << u.first.first << ' ' ;
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++){
        if(indeg[i][0] == 0 and indeg[i][1] >= 1){
            cnt++;
        }
    }
    /*
    q.push(1);
    ms(mark , 0);
    mark[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : vec[0][v]){
            if(!mark[u]){
                q.push(u);
                mark[u] = 1;
            }
        }
        for (auto u : vec[1][v]){
            if(!mark[u]){
                q.push(u);
                cnt++;
                mark[u] = 1;
            }
        }
    }
    */
    cout << k - cnt;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
