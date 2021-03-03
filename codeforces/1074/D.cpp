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

map < int , pii > mp;

int q;

pii get(int v){
	if(mp.count(v) == 0) return mp[v] = {v , 0};
	if(mp[v].first == v)
		return mp[v];
	pii res = get(mp[v].first);
	res.second ^= mp[v].second;
	return mp[v] = res;
}

int32_t main(){
	migmig;
	cin >> q;
	int lst = 0;
	while(q -- ){
		int t , l , r;
		cin >> t >> l >> r;
		l ^= lst , r ^= lst;
		if(l > r)swap(l , r);
		r++;
		pii a = get(l) , b = get(r);
		if(t == 1){
			int x;
			cin >> x;
			x ^= lst;
			if(a.first == b.first)continue;
			a.second ^= b.second ^ x;
			mp[b.first] = a;
		}
		else{
			if(a.first == b.first)
				cout << (lst = a.second ^ b.second) << endl;
			else
				lst = 1 , cout << -1 << endl;
		}
	}
	return(0);
}
