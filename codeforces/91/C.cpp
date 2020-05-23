#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+9;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int par[maxn];
int sz[maxn];
ll ans = 1;

int getpar(int v){
	return((v == par[v])?v : par[v] = getpar(par[v]));
}

void merge(int u , int v){
	u = getpar(u) , v = getpar(v);
	if(u == v){
		ans = (ans + ans)%mod;
		return;
	}
	if(sz[u] > sz[v])
		swap(u , v);
	par[u] = v;
	sz[v] += sz[u];
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
		par[i] = i , sz[i] = 1;
	while(m--){
		int u , v;
		cin >> u >> v;
		merge(u , v);
		cout << (ans+mod-1)%mod << endl;
	}
    return(0);
}