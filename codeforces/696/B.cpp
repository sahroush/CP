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

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];
int sub[maxn];

ld E[maxn];

void dfs(int v){
	sub[v] = 1;
	for(auto u : adj[v])
		dfs(u) , sub[v] += sub[u];
}

void calc(int v){
	for(auto u : adj[v])
		E[u] = 1 + E[v] + (sub[v] - sub[u] - 1)/2.0 , calc(u);
}

int32_t main(){
    migmig;
    cin >> n;
    for(int i = 2 ; i <= n ; i ++){
		int x;
		cin >> x;
		adj[x].pb(i);
	}
	dfs(1);
	E[1] = 1;
	calc(1);
	cout << fixed << setprecision(10);
	for(int i = 1 ; i <= n ; i ++)
		cout << E[i] << ' ';
    return(0);
}
