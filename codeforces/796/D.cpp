#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
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

struct edge{
    int u , v;
    bool f = 0;
}e[maxn];

int n , k , d;
int a[maxn];
bool p[maxn];
vector < int > adj[maxn];
vector < int > ans;
int cnt = 0  , an = 0;;
map < pii , int > mp;
bool mark[maxn];
int dist[maxn];
queue < int > q;

int main(){
    migmig
    cin >> n >> k >> d;
    for (int i = 0 ; i < k ; i ++){
        cin >> a[i];
        p[a[i]] = 1;
    }
    for (int i = 1 ; i <= n - 1 ; i ++){
        int v , u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
        mp[{u , v}] = mp[{v , u}] = i;
        e[i].u = u , e[i].v = v;
    }
    ms(dist , 63);
    for (int i  = 1 ; i <= n ; i ++){

        if(!p[i]) continue;


        an++;
        mark[i] = 1;
        dist[i] = 0;
        q.push(i);
    }
    while(!q.empty()){
        if(an >= n){
            break;
        }
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if(!mark[v]){
                if(dist[u] + 1 <= d and dist[v] > dist[u] + 1){
                    e[mp[{u , v}]].f = 1;
                    mark[v] = 1;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    an++;
                }
            }
        }
    }

    for (int i = 1 ; i <= n - 1 ; i ++){
        if(!e[i].f){
            cnt++;
            ans.pb(i);
        }
    }
    cout << cnt << endl;
    prnt(ans);

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
