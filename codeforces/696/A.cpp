//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int t[maxn];
ll u[maxn] , v[maxn] , w[maxn];

ll lca(ll u , ll v){
	set < ll > st;
	while(u!=1)
		st.insert(u) , u/=2;
	st.insert(1);
	while(v!=1){
		if(st.count(v))
			return(v);
		v/=2;
	}
	return(1);
}

void solve(int x){
	map < ll  , ll > mp;
	for(int i = 1 ; i <= x ; i ++){
		if(t[i] == 1){
			ll u = ::u[i] , v = ::v[i];
			ll lc = (lca(u , v));
			ll w = ::w[i];
			while(u!=lc)
				mp[u]+=w , u/=2;
			while(v!=lc)
				mp[v]+=w , v/=2;
		}
		else{
			ll u = ::u[i] , v = ::v[i];
			ll lc = (lca(u , v));
			ll ans = 0;
			while(u!=lc){
				if(mp.count(u))ans+=mp[u];
				u/=2;
			}
			while(v!=lc){
				if(mp.count(v))ans+=mp[v];
				v/=2;
			}
			cout << ans << endl;
		}
	}
}

int32_t main(){
    migmig;
    cin >> q;
	for(int i = 1 ; i <= q ; i ++){
		cin >> t[i] >> u[i] >> v[i];
		if(t[i] == 1)
			cin >> w[i];
	}
	solve(q);
    return(0);
}
