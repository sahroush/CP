/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 510;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , cnt;
int a[maxn][maxn] , ans[maxn<<2];
set < int > vec;
vector < pii > e;
 
#define sz (int)vec.size()

int solve(set < int > &vec){
	if(sz == 1){
		int v = *vec.begin();
		ans[v] = a[v][v];
		vec.clear();
		return(v);
	}
	int mx = 0;
	int u = *vec.begin();
	for(auto v : vec)
		mx = max(mx , a[v][u]);
	int root = n + (++cnt);
	ans[root] = mx;
	set < int > v;
	while(vec.size()){
		int V = *vec.begin();
		for(auto u : vec)
			if(a[V][u] != mx)
				v.insert(u);
		for(auto u : v)
			vec.erase(u);
		int par = solve(v);
		e.pb({par , root});
	}
	return(root);
}

int32_t main(){
	migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			cin >> a[i][j];
	for(int i = 1 ; i <= n ; i ++)vec.insert(i);
	int root = solve(vec);
	cout << n+cnt << endl;
	for(int i = 1 ; i <= n + cnt ; i ++)cout << ans[i] << ' ';
	cout << endl;
	cout << root << endl;
	for(auto [u , v] : e)
		cout << u << ' ' << v << endl;
	return(0);
}
