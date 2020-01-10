#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;
 
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
	int u , v ;
	ll w;
	bool used = 0;
}e[maxn];

int n , m , start;
ll dist[maxn];
vector < pii > adj[maxn];
bool mark[maxn];
map < pii , int > mp;
ll par[maxn];
set < pair < pii , ll > >  st;

void djk(){
	ms(dist , 63);
	dist[start] = 0;
	st.insert(make_pair(pii(dist[start] , (ll)0) , (ll) start));
	while(!st.empty()){
		auto u = *st.begin();
		st.erase(st.begin());
		if(mark[u.second]) continue;
		mark[u.second] = 1;
		if(u.second!=start){
			e[mp[{u.second , par[u.second]}]].used  = 1;
		}
		for (auto v : adj[u.second]){
			if(!mark[v.first]){
				if(dist[v.first] >= dist[u.second] + v.second){
					par[v.first] = u.second;
					dist[v.first] = dist[u.second] + v.second;
					st.insert(make_pair(pii(dist[v.first] , v.second) , v.first));
				}
			}
		}
	}
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i ++){
    	int u , v ;
    	ll w;
    	cin >> u >> v >> w;
    	mp[{v , u }] = mp[{u , v}] = i;  
		e[i].v = min(u , v);
		e[i].u = max(u , v);
		e[i].w = w;
		adj[v].pb(pii(u , w));
		adj[u].pb(pii(v , w));
	}
	cin >> start;
	djk();
	ll ans = 0 ;
	for (int i = 1 ; i <= m ; i ++){
		if(e[i].used){
			ans+=e[i].w;
		}
	}
	cout << ans << endl;
	for (int i = 1 ; i <= m ; i ++){
		if(e[i].used){
			cout << i << ' ';
		}
	}
    return(0);
}
