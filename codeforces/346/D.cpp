#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int out[maxn];
vector < int > in[maxn];
int n , m;
int dist[maxn];
bool mark[maxn];
int s, t;



set <pii> st;

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
    	int u , v;
    	cin >> u >> v;
    	in[v].pb(u);
    	out[u]++;
	}
	cin >> s >> t;
	ms(dist , 63);
	dist[t] = 0;
	st.insert(pii(dist[t] , t));
	while(!st.empty()){
		pii v = *st.begin();
		st.erase(v);
		if(mark[v.second]) continue;
		mark[v.second] = 1;
		for (auto u : in[v.second]){
			dist[u] = min(dist[u] , dist[v.second] + 1);
			out[u]--;
			if(out[u] <= 0){
				dist[u]=min(dist[u] , dist[v.second]);
			}
			st.insert(pii(dist[u] , u));
		}
	}
	if(dist[s] == dist[0]){
		cout << -1;
	}
	else{
		cout << dist[s];
	}

    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.

