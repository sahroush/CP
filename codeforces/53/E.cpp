#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , k;
bool adj[20][20];
ll dp[(1 << 10)][(1 << 10)];

int main(){
    migmig
    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		u -- ; v -- ;
		adj[u][v] = adj[v][u] = 1;
		dp[(1 << u) + (1 << v)][(1 << u) + (1 << v)] = 2;
    }
    for(int i = 1 ; i < (1 << n) ; i ++){
		for(int j = i ; j > 0 ; j = (j-1)&i){
			dp[i][j]/=__builtin_popcount(j);
			for(int v = 0 ; v < n ; v++){
				if(i & (1 << v)){
					int p = j & (((1 << n)-1)^(1 << v));
					for(int u = 0 ; u < n ; u ++){
						if(i & (1 << u)){
							continue;
						}
						if(!adj[v][u]){
							continue;
						}
						dp[i | (1 << u)][p|1 << u]+=dp[i][j];
					}
				}
			}
		}
	}
	ll ans = 0 ;
	for(int i = 0 ; i <(1 << n) ; i ++){
		if(__builtin_popcount(i) == k){
			ans+=dp[(1 << n)-1][i];
		}
	}
	cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
