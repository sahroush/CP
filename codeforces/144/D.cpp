#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;
 
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
	int w;
}e[maxn];

int n , m , s , l;
vector < pii > vec[maxn];
map < pii , bool > mp[maxn]; 
int ans = 0;
int dist[maxn];
bool mark[maxn];
set < pii > st;

void djk(){
	ms(dist , 63);
	dist[s] = 0;
	st.insert(pii(dist[s] , s));
	while(!st.empty()){
		auto u = *st.begin();
		st.erase(st.begin());
		if (mark[u.second]) continue;
		mark[u.second] = 1;
		for (auto v : vec[u.second]){
			if(!mark[v.first]){
				dist[v.first] = min(dist[v.first] , dist[u.second] + v.second);
				st.insert(pii(dist[v.first] , v.first));
			}
		}
	}
}


int main(){
    migmig
    cin >> n >> m >> s;
    for (int i = 0 ; i < m ; i ++){
    	int u , v , w;
    	cin >> u >> v >> w;
    	vec[u].pb(pii(v , w));
    	vec[v].pb(pii(u , w));
    	e[i].u = u;
    	e[i].v = v;
    	e[i].w = w;
	}
    cin >> l;
    djk();
    for (int i = 1 ; i <=n ; i ++){
    	if(dist[i] == l){
    		ans++;
		}
	}
	for (int i = 0; i < m ; i ++){
		int distu = dist[e[i].u];
		int distv = dist[e[i].v];
		if(distu > distv){
			swap(distu , distv);
		}
		for (int j = 1 ; j < e[i].w ; j ++){
			int distj = min(j + distu , e[i].w - j + distv);
			if(distj == l){
				ans++;
			}
		}
		
		
	}
    cout << ans;
    return(0);
}


/*
3 2 3
2 1 577
3 2 472
150
*/
