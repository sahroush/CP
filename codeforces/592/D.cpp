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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < int > adj[maxn];
vector < int > tar;
bool bad[maxn];
int dp[maxn] , cnt[maxn];
bool boz = 0;
int ans = 1e9 , tme = 0;

void dfs(int v , int par = 0 , int dist = 0){
	cnt[v] = bad[v];
	for(auto u : adj[v]){
		if(u!=par){
			dfs(u , v , dist + 1);
			cnt[v]+=cnt[u];
			if(!boz) dp[v]+= ((cnt[u])? 2 : 0) + dp[u];
		}
	}
	if(bad[v]){
		if(tme < dist){
			tme = dist;
			ans = v;
		}
		if(tme == dist){
			ans = min(ans , v);
		}
	}
	
	
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i < n ; i ++){
		int u , v;
		cin >> v >> u;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0 ; i < m ; i ++){
		int x;
		cin >> x;
		tar.pb(x);
		bad[x] = 1;
	}
    dfs(tar[0]);
    boz = 1;
    int ans1 = ans;
    dfs(ans);
    cout << min(ans , ans1) << endl << dp[tar[0]]-tme;
    return(0);
}

