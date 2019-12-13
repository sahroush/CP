#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =9e5+1000;
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
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m;
vector < int > adj[maxn] , vec[maxn];
bool parity[maxn] , mark[maxn];
bool prt[maxn];
vector <int> ans;
int par[maxn];

void dfs2(int v){
	mark[v] = 1;
	ans.pb(v);
	prt[v] = !prt[v];
	for (int i =0  ; i < adj[v].size() ; i ++){
		int u = adj[v][i];
		if(!mark[u]){
			par[u] = v; 
			dfs2(u);
			prt[v] = !prt[v];
			ans.pb(v);
		}
	}
	int u = par[v];
	if(u==-1 and prt[v] != parity[v]){
		ans.pop_back();
		prt[v] = !prt[v];
	}
	else{
		if(parity[v] != prt[v]){
			ans.pb(u);
			ans.pb(v);
			prt[u] = !prt[u];
			prt[v] = !prt[v];
		}
	}
	
}



int main(){
    migmig
    cin  >> n >> m;
    for (int i =0 ; i < m ; i ++){
    	int x , y;
    	cin >> x >> y;
    	adj[x].pb(y);
    	adj[y].pb(x);
	}
	int st = -1;
	for (int i =0 ; i < n ; i ++){
		cin >> parity[i + 1];
		if(parity[i + 1] and st == -1){
			st = i + 1;
		}
	}
	if(st == -1){
		dokme(0);
	}
	par[st] = -1;
	dfs2(st);
	for(int i = 1 ; i <= n ; i ++){
		if(parity[i] and !mark[i]){
			dokme(-1);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0 ; i < ans.size() ; i ++){
		cout << ans[i] << ' ';
	}
	
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.

