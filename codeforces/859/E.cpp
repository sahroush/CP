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

int n;
ll ans = 1;
ll sz[maxn];
ll par[maxn];
bool mark[maxn];
ll comp[maxn];

int getpar(int v){
	if(v == par[v])
		return(v);
	par[v] = getpar(par[v]);
	return(par[v]);
}

void merge(int v , int u ){
	if(u == v){
		comp[getpar(v)]=2;
		return;
	}
	u = getpar(u) , v = getpar(v);
	if(u == v){
		comp[v]=1;
		return;
	}
	if(sz[u] > sz[v]){swap(u , v);}
	comp[v] = max(comp[v] , comp[u]);
	par[u] = v;
	sz[v] += sz[u];
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= 2*n ; i ++)
		par[i] = i , sz[i] = 1;
    for(int i = 0 ; i < n ; i ++){
		int u , v;
		cin >> u >> v;
		merge(u , v);
	}
	for(int i = 1 ; i <= 2*n ; i ++){
		if(!mark[getpar(i)]){
			int p = getpar(i);
			mark[p] = 1;
			if(sz[p]==1) continue;
			if(comp[p] == 2)continue;
			if(comp[p] == 0)
				ans = (ans * ll(sz[p]))%mod;
			else 
				ans = (ans + ans)%mod;
		}
	}
	cout << ans;
    return(0);
}