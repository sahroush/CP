/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 50100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , q;

set < int > st[maxn];

int ans[maxn];
int on[maxn];

void add(int u , int v){
	if(st[u].size() > st[v].size())
		swap(u , v);
	st[u].insert(v);
	ans[v] += on[u];
}

void rm(int u , int v){
	if(st[u].count(v)==0)
		swap(u , v);
	st[u].erase(v);
	ans[v]-=on[u];
}

int32_t main(){
    migmig;
	cin >> n >> m >> q;
	int o;
	cin >> o;
	for(int i = 0 ; i < o ; i ++){
		int x;
		cin >> x;
		on[x] = 1;
	}
	for(int i = 0 ; i < m ; i ++){
		int u , v;
		cin >> u >> v;
		add(u , v);
	}
	while(q -- ){
		string t;
		cin >> t;
		if(t == "O"){
			int u;
			cin >> u;
			on[u] = 1;
			for(auto v : st[u])
				ans[v]++;
		}
		if(t == "F"){
			int u;
			cin >> u;
			on[u] = 0;
			for(auto v : st[u])
				ans[v]--;
		}
		if(t == "A"){
			int u , v;
			cin >> u >> v;
			add(u , v);
		}
		if(t == "D"){
			int u , v;
			cin >> u >> v;
			rm(u , v);
		}
		if(t == "C"){
			int u , sum = 0;
			cin >> u;
			for(auto v : st[u])
				sum += on[v];
			cout << ans[u] + sum << endl;
		}
	}
    return(0);
}
