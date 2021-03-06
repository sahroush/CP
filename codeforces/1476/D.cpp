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

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;
int par[maxn];
int sz[maxn];
string s;

int getpar(int v){
	return((par[v] == v)? v : par[v] = getpar(par[v]));
}

void merge(int v , int u){
	if((u = getpar(u)) == (v = getpar(v)))
		return;
	sz[v] += sz[u] , par[u] = v;
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> s;
		for(int i = 0 ; i < 2 * n + 100 ; i ++)par[i] = i , sz[i] = 1;
		int x = n + 10;
		for(int i = 0 ; i < n ; i ++){
			if(s[i] == 'L')
				merge(i + x , i + 1);
			else
				merge(i , (i + 1) + x);
		}
		for(int i = 0 ; i <= n ; i ++)
			if(getpar(i) == getpar(i + x))
				sz[getpar(i)]--;
		for(int i = 0 ; i <= n ; i ++)
			cout << sz[getpar(i)] << ' ';
		cout << endl;
	}
	return(0);
}
