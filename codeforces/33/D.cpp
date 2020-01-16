#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e4;
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

struct circle{
    ld r , x , y ;
    int id;
}c[maxn];
struct point{
    ld x , y ;
    int id;
}p[maxn];

int n , m , k;
int x[maxn] , y[maxn] , cx[maxn] , cy[maxn] , r[maxn];
vector <int> adj[maxn];
int mark[1011];
int dist[1100][1010];
int cur;
int pos[maxn];

bool incircle(int a , int b){
    //tells whether circle a is in circle b or not;
    ld dis =(((c[a].x - c[b].x) * (c[a].x - c[b].x)) + ((c[a].y - c[b].y) * (c[a].y - c[b].y)));
    return(dis <= c[b].r * c[b].r and c[a].r<c[b].r);
}

void dfs(int v){
    mark[v] = 1;
    for (auto u : adj[v]){
        if(!mark[u]){
            dist[cur][u] = dist[cur][v] + 1;
            dfs(u);
        }
    }
}

int main(){
    migmig
    ms(pos , 0);
    cin >> n >> m >> k;
    for (int  i = 1 ; i <= n ; i ++){
        cin >> x[i] >> y[i];
        p[i].x = x[i] , p[i].y = y[i] , p[i].id = i;
    }
    for (int i = 1 ; i <= m ; i ++){
        cin >> r[i] >> cx[i] >> cy[i];
        c[i].id = i , c[i].r = r[i] , c[i].y = cy[i] , c[i].x = cx[i];
    }
    for (int i = 1 ; i <= m ; i ++){
        int mn = 1e6;
        for (int j = 1 ; j <= m ; j ++){
            if(i == j) continue;
            if(incircle(i , j)){
                if(mn == 1e6){
                    mn = j;
                }
                else{
                    if(c[mn].r > c[j].r ){
                        mn = j;
                    }
                }
            }
        }
        if(mn !=1e6){
            adj[mn].pb(i);
            adj[i].pb(mn);
        }
        else{
            adj[0].pb(i);
            adj[i].pb(0);
        }
    }

    for (int i = 1 ; i <= n ; i ++){
        int mn = 1e6;
        for (int j = 1 ; j <= m ; j ++){
            ld dis =((c[j].x - p[i].x) * (c[j].x - p[i].x)) + ((c[j].y - p[i].y) * (c[j].y - p[i].y));
            if(dis<=c[j].r * c[j].r){
                if(mn == 1e6){
                    mn = j;
                }
                else{
                    if(c[mn].r > c[j].r){
                        mn = j;
                    }
                }
            }
        }
        if(mn !=1e6){
            pos[i] = mn;
        }
        else{
            pos[i] = 0;
        }
    }

    for (int i = 0 ; i <= m ; i ++){
        cur = i;
        dist[i][i] = 0;
        ms(mark , 0 );
        dfs(i);
    }

    while(k -- ){
        int u , v;
        cin >> v >> u;
        cout << dist[pos[u]][pos[v]] << endl;
    }

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
