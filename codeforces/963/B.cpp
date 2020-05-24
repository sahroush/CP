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

int n;
vector < int > adj[maxn];
int par[maxn];
bool sik[maxn];

void solve(int v){
	cout << v << endl;
	sik[v]=1;
	for(auto u : adj[v])if(!sik[u] and u!=par[v])solve(u);
}

int dfs(int v){
	int s = 0;
	for(auto u : adj[v])
		if(u!=par[v])par[u] = v ,s+=dfs(u);
	if(s%2)
		solve(v);
	return(++s);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
		cin >> par[i];
		if(!par[i])continue;
		adj[i].pb(par[i]);
		adj[par[i]].pb(i);
	}
	ms(par,0);
    if(n%2==0)dokme("NO");
    cout << "YES" << endl;
    dfs(1);
    solve(1);
    return(0);
}