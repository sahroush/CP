#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =3e3+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , s1 , t1 , l1 , s2 , t2 , l2 ;
vector < int > vec[maxn];
int dist[maxn][maxn];
queue <int> q;
bool mark[maxn];

void bfs(int r){
    mark[r] = 1;
    q.push(r);
    dist[r][r] = 0;
    while(!q.empty()){
        int v= q.front();
        q.pop();
        for (int i = 0; i < vec[v].size() ; i ++){
            int u = vec[v][i];
            if (!mark[u]){
                mark[u] = 1;
                q.push(u);
                dist[r][u] = dist[r][v] + 1;
            }
        }
    }
    return;
}

int main(){
    migmig
    memset(dist  , -1 , sizeof dist);
    cin >> n >> m;
    for (int  i =0 ; i < m ; i ++){
        int x , y;
        cin >> x >> y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    for (int i = 1 ; i <= n ; i ++){
        memset(mark , 0 , sizeof mark);
        bfs(i);
    }

    int ans = 1e8;
    if (dist[s1][t1] <= l1 and dist[s2][t2] <= l2) {
        ans = min(ans, dist[s1][t1] + dist[s2][t2]);
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int v[2] = {dist[s1][i] + dist[i][j] + dist[j][t1], dist[s2][i] + dist[i][j] + dist[j][t2]};
            if (v[0] <= l1 and v[1] <= l2) {
                ans = min(ans, v[0] + v[1] - dist[i][j]);
            }
        }
    }
    swap(s1  , t1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int v[2] = {dist[s1][i] + dist[i][j] + dist[j][t1], dist[s2][i] + dist[i][j] + dist[j][t2]};
            if (v[0] <= l1 and v[1] <= l2) {
                ans = min(ans, v[0] + v[1] - dist[i][j]);
            }
        }
    }
    if (ans > m) {
        dokme(-1);
    }
    m-=ans;
    dokme(m);
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
