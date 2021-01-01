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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 130;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
vector < pii > adj[maxn];

int win[maxn][maxn][30];

int solve(int f , int s , int ch = 0){
	if(win[f][s][ch])return(win[f][s][ch]);
	for(auto [u , c] : adj[f])if(c >= ch){
		if(solve(s , u , c) == 2)return((win[f][s][ch] = 1));
	}
	return((win[f][s][ch] = 2));
}

int32_t main(){
    migmig;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++){
		int u , v;
		char c;
		cin >> u >> v >> c;
		adj[u].pb({v , c - 'a' + 1});
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++)
			cout << ((solve(i , j) == 1) ? 'A' : 'B');
		cout << endl;
	}
    return(0);
}
