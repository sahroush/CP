#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e5;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , k , s;
int dist[maxn][100];
vector <int> vec[maxn];
queue <int> q;
bool mark[maxn];

int main(){
    migmig
    cin >> n >> m >> k >> s;
    for (int i =0 ; i < n ; i ++){
        int inp;
        cin >> inp;
        vec[inp].pb(i + 101);
    }
    for (int i = 0 ; i < m ; i ++){
        int x , y;
        cin >> x >> y;
        x+=100;
        y+=100;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    for (int i = 1 ; i<=k ; i ++){
        dist[i][i] = -1;
        q.push(i);
        ms(mark , 0);
        mark[i] = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for (int j = 0 ; j < vec[v].size() ; j ++){
                int u = vec[v][j];
                if(!mark[u]){
                    mark[u] = 1;
                    q.push(u);
                    dist[u][i] = dist[v][i] + 1;
                }
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++ ){
        vector <int> vc;
        vc.clear();
        for (int j = 1; j<=k ; j ++){
            vc.pb(dist[i + 100][j]);
        }
        sort(vc.begin() , vc.end());
        int sum = 0;
        for (int j = 0; j < s ; j ++){
            sum+=vc[j];
        }
        cout << sum << ' ';
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
