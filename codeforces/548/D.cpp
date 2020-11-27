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
int a[maxn];
int par[maxn];
int sz[maxn];
int mx = 0;
int val = 1e9;
map < int , vector < int > > mp;

int getpar(int v){
	return((v == par[v]) ? v : par[v] = getpar(par[v]));
}

void merge(int u , int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)return;
	if(sz[u] > sz[v])swap(u , v);
	sz[v] += sz[u] , par[u] = v , mx = max(mx , sz[v]);
}

void add(int pos , int x){
	if(pos > 1 and a[pos - 1] >= x)
		merge(pos , pos - 1);
	if(pos < n and a[pos + 1] >= x)
		merge(pos , pos + 1);
	mx = max(mx , 1);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , par[i] = i , sz[i] = 1 , mp[-a[i]].pb(i); 
	for(int i = 1 ; i <= n ; i ++){
		while(mx < i){
			auto [f , s] = *mp.begin();
			mp.erase(f);
			val = -f;
			for(int x : s)
				add(x , -f);
		}
		cout << val << ' ';
	}
    return(0);
}
