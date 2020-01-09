#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

const ll maxn =1e3+2;
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

int n , m ;
vector <int> adj[maxn] , ans1 , ans2;
int dist[510][510][2];
pair <pii , bool >  par[510][510][2];
bool mark[510][510][2];
queue < pair < pii , bool > > q;

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
    	int u , v ;
    	cin >> v >> u;
    	adj[v].pb(u);
    	adj[u].pb(v);
	}
	ms(dist , 63);
	dist[1][n][0] = 0 ;
	q.push({pii(1 , n ) , 0});
	while(!q.empty()){
		pair < pii , bool > X;
		X = q.front();q.pop();
		int v = X.first.first , u = X.first.second;
		bool state = X.second;
		if(state){
			for (auto x : adj[u]){
                if(dist[v][x][0] != dist[0][0][0] or v == x)continue;
				par[v][x][0] = {{v , u}, 1};
				dist[v][x][0] = dist[v][u][1] + 1;
				q.push({{v, x}, 0});
			}
		}
		else{
			for (auto x : adj[v]){
                if(dist[x][u][1] != dist[0][0][0]) continue;
				par[x][u][1] = {{v , u}, 0};
				dist[x][u][1] = dist[v][u][0];
				q.push({{x, u}, 1});
			}
		}
	}
	if(dist[n][1][0] >= 1e7){
		dokme(-1);
	}
	cout << dist[n][1][0] << endl;
    int s = 1 , e = n;
    while(s!=n or e != 1){
        auto v = par[e][s][0];
        v = par[v.first.first][v.first.second][1];
        e = v.first.first;
		s = v.first.second;
		ans1.pb(e);
		ans2.pb(s);
    }
    reverse(all(ans1));
    prnt(ans1);
    cout << n <<  endl;
    reverse(all(ans2));
    prnt(ans2);
    cout << 1;

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
