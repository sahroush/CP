//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct fenwick{
	ll fen[maxn][2];
	void add(int pos , ll x , int p){
		for( ; pos < maxn ; pos += pos & -pos)
			fen[pos][p] += x;
	}
	void add(int l, int r,  ll x , ll y){
		add(l , x , 1);
		add(r + 1 , -x , 1);
		add(l , y , 0);
		add(r + 1 , -y , 0);
	}
	ll get(int pos , int p){
		ll res = 0;
		for( ; pos ; pos -= pos & -pos)
			res += fen[pos][p];
		return res;
	}
	ll get(int pos){
		return get(pos , 0) + get(pos , 1) * pos;
	}
}fl , fr;

int n , q , a[maxn] , l[maxn] , r[maxn];
vector < int > qr[maxn] , ql[maxn] , sl , sr;
int nl[maxn] , nr[maxn];
ll ans[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)cin >> i[a];
	for(int i = 1 ; i <= q ; i ++)cin >> i[l] , ql[l[i]].pb(i); 
	for(int i = 1 ; i <= q ; i ++)cin >> i[r] , qr[r[i]].pb(i) , ans[i] = r[i] - l[i] + 1;
	for(int i = 1 ; i <= n ; i ++){
		while(sl.size() and a[sl.back()] < a[i])sl.pop_back();
		if(sl.size())nl[i] = sl.back();
		sl.pb(i);
	}
    for(int i = n ; i >= 1 ; i --){
		while(sr.size() and a[sr.back()] < a[i])sr.pop_back();
		nr[i] = ((sr.size()) ? sr.back() : n+1);
		sr.pb(i);
	}
    for(int i = 1 ; i <= n ; i ++){
		fl.add(1 , nl[i] , 0 , i - nl[i] - 1);
		fl.add(nl[i] + 1 , i - 1 , -1 , i);
		for(auto j : qr[i])
			ans[j] += fl.get(l[j]);
	}
    for(int i = n ; i >= 1 ; i --){
		fr.add(nr[i] ,  n , 0 , nr[i] - i - 1);
		fr.add(i + 1 , nr[i] - 1 , 1 , -i);
		for(auto j : ql[i])
			ans[j] += fr.get(r[j]);
	}
	for(int i = 1 ; i <= q ; i ++)cout << ans[i] << ' ';
	return(0);
}
