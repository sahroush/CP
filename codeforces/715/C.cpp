/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < pii > adj[maxn];
map < int , int > mp;
int inv10;

ll ans = 0 , cnt = 0;

int hide[maxn] , sz[maxn];

void plant(int v , int par = -1){
	sz[v] = 1;
	for(auto [u , w] : adj[v])
		if(u!=par and !hide[u])
			plant(u , v) , sz[v] += sz[u];
}

int cen(int v , int n , int par = -1 , bool found = 0){
	while(!found){
		found = 1;
		for(auto [u , w] : adj[v])
			if(!hide[u] and u != par and sz[u] * 2 > n){
				par = v , v = u , found = 0;
				break;
			}
	}
	return(v);
}

void add(int v , int par , int w , int p ,int cur = 0){
	cur = (cur + p * 1LL * w)%m;
	mp[cur]++;
	if(cur == 0)cnt++;
	for(auto [u , w] : adj[v])
		if(u!= par and !hide[u])
			add(u , v , w , (p * 1LL * 10)%m , cur);
}

void rem(int v , int par , int w , int p ,int cur = 0){
	cur = (cur + p * 1LL * w)%m;
	mp[cur]--;
	for(auto [u , w] : adj[v])
		if(u!= par and !hide[u])
			rem(u , v , w , (p * 1LL * 10)%m , cur);
}

void calc(int v , int par , int w , int p ,int cur = 0){
	cur = (cur * 1LL * 10 + w)%m;
	int res = (m - ((cur * 1LL * p)%m))%m;
	ans += mp[res];
	for(auto [u , w] : adj[v])
		if(u!= par and !hide[u])
			calc(u , v , w , (p * 1LL * inv10)%m , cur);
}

void calc(int v){
	for(auto [u , w] : adj[v])if(!hide[u])
		add(u , v , w , 1);
	for(auto [u , w] : adj[v])if(!hide[u])
		rem(u , v , w , 1) , calc(u , v , w , inv10) , add(u , v , w , 1);
	for(auto [u , w] : adj[v])if(!hide[u])
		rem(u , v , w , 1);
}

void solve(int v){
	plant(v);
	v = cen(v , sz[v]);
	hide[v] = 1;
	calc(v);
	for(auto [u , w] : adj[v])
		if(!hide[u])
			solve(u);
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int32_t main(){
    migmig;
	cin >> n >> m;
	inv10 = ((m > 1) ? pw(10 , phi(m) - 1 , m) : 0);
	mp[0]=1;
	for(int i = 1 ; i < n ; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	solve(0);
	cout << ans + cnt/2;
    return(0);
}
