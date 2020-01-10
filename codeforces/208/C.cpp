#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =200;
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
vector < int > vec[maxn];
ll cnt[maxn][maxn];
ll val[maxn];
bool mark[maxn];
ll dist_s[maxn] , dist_e[maxn];
queue< int > q;

int main(){
    migmig
    cin >> n >> m ;
    for (int i = 0 ; i < m ; i ++){
    	int u , v;
    	cin >> u >> v;
    	vec[v].pb(u);
    	vec[u].pb(v);
	}
	dist_s[1] = 0;
	q.push(1);
	mark[1] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for (int u : vec[v]){
			if(!mark[u]){
				dist_s[u] = dist_s[v] + 1;
				mark[u] = 1;
				q.push(u);
			}
		}
	}
	ms(mark , 0 );
	dist_e[n] = 0;
	q.push(n);
	mark[n] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for (int u : vec[v]){
			if(!mark[u]){
				dist_e[u] = dist_e[v] + 1;
				mark[u] = 1;
				q.push(u);
			}
		}
	}
	for (int  i= 1 ; i <= n ; i ++){
		ms(mark , 0);
		cnt[i][i] = 1;
		mark[i] = 1 ;
		q.push(i);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for (auto u : vec[v]){
				if(!mark[u]){
					if(dist_s[u] + dist_e[u] == dist_s[n]){
						q.push(u);
					}
					mark[u] = 1;
				}
				if(dist_s[u] == dist_s[v] - 1)	cnt[i][v]+=cnt[i][u];
			}
		}
	}
    ld ans = 1.0;
    for (int i = 2 ; i < n ; i ++){
		ans = max(ans, (ld)2.0 * cnt[1][i] * cnt[i][n] / (cnt[1][n] + 0.0));
	}
    cout << fixed << setprecision(10) ;
	cout << ans;


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
