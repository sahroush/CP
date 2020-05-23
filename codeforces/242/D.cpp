#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < int > adj[maxn];
int a[maxn];
queue < int > q;
int cnt[maxn];
vector < int > ans;

int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i++)
		if(cnt[i] == a[i])
			q.push(i);
	while(!q.empty()){
		auto v = q.front();
		q.pop();
		cnt[v]++;
		for(auto u : adj[v]){
			cnt[u]++;
			if(cnt[u]==a[u])
				q.push(u);
		}
		ans.pb(v);
	}
	for(int i = 1 ; i <= n ; i ++)if(cnt[i]==a[i])dokme(-1);
    cout << ans.size() << endl;
    for(int i : ans)
		cout << i << ' ';
    return(0);
}