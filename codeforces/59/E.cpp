#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =3001;
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

int n , m , k;
int par[maxn][maxn];
int dist[maxn][maxn];
vector < int > adj[maxn];
vector < int > ans;
bool mark[maxn];
queue <pii> q;
set < pair < pii , int > > st;
bool nei[maxn][maxn];

int main(){
    //migmig
    cin >> n >> m >> k;
    for (int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> v >> u ;
        adj[u].pb(v);
        adj[v].pb(u);
        nei[u][v] = nei[v][u] = 1;
    }
    for (int  i =0 ; i < k ; i ++){
        int a , b , c;
        cin >> a >> b >> c;
        st.insert(make_pair(pii(a , b) , c));
    }
    ms(dist , 63);
    /*
    for (int i = 1 ; i <= n ; i ++){
        dist[i][i] = 0;
        ms(mark, 0);
        q.push(i);
        mark[i] = 1;
        par[i][i] = -1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for (int u : adj[v]){
                if(!mark[u]){
                    if(st.count(make_pair(pii(par[i][v] , v) , u)) == 0){
                        dist[i][u] = dist[i][v] + 1;
                        mark[u] = 1;
                        q.push(u);
                        par[i][u] = v;
                    }
                }
            }
        }
    }
    */
    ms(dist , 63);
    for (int i  = 1 ; i <= n ; i ++){
        if(nei[1][i]){
            dist[1][i] = 1;
            q.push(make_pair(1 , i));
        }
    }
    while(!q.empty()){
        int v = q.front().first;
        int u = q.front().second;
        q.pop();
        for(int i = 1; i <= n; i++){
            if (nei[u][i] and dist[u][i]==dist[0][0] and !st.count(make_pair(pii(v, u), i))){
                dist[u][i]=dist[v][u]+1;
                q.push(pii(u, i));
                par[u][i]=v;
            }
        }
    }
    int mn = dist[0][0] , ind = 1;
    for (int i = 1 ; i < n ; i ++){
        if(mn > dist[i][n]){
            mn= dist[i][n];
            ind = i;
        }
    }
    if(mn == dist[0][0]){
        dokme(-1);
    }
    cout << mn << endl;
    int pos = n;
    for (int i  = ind ,j = n ; i!=1 ; ){
        ans.pb(j);
        int boz = par[i][j];
        j = i ; i = boz;
        pos = j;
    }
    ans.pb(pos);
    ans.pb(1);
    reverse(all(ans));
    prnt(ans);

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
