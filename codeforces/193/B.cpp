#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll a[maxn] , b[maxn] , c[maxn] , p[maxn];
ll n , u , r;
vector < ll > vec;
ll ans = -1e18;

void solve(vector < ll > cur ,int  done = 0){
	if(done > u)
		return;
	if(done%2 == u%2){
		ll res = 0;
		for(int i = 0 ; i < n ; i ++)
			res+=cur[i]*c[i];
		ans = max(ans , res);
		if(done == u)
			return;
	}
	vector < ll > xr;
	xr.clear();
	for(int i = 0 ; i < n ; i ++)
		xr.pb(cur[i]^b[i]);
	vector < ll > rot;
	rot.clear();
	for(int i = 0 ; i < n ; i ++)
		rot.pb(cur[p[i]] + r);
	vector < ll > xorot;
	xorot.clear();
	for(int i = 0 ; i < n ; i ++)
		xorot.pb(xr[p[i]] + r);
	if(done == u-1){
		solve(rot , u);
		solve(xr , u);
		return;
	}
	solve(rot , done+1);
	solve(xorot , done + 2);
	if(done%2!=u%2)
		solve(xr , u);
}

int main(){
    migmig
    cin >> n >> u >> r;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	for(int i = 0 ; i < n ; i ++)
		cin >> b[i];
	for(int i = 0 ; i < n ; i ++)
		cin >> c[i];
    for(int i = 0 ; i < n ; i ++)
		cin >> p[i];
	for(int i = 0 ; i < n ; i ++)
		p[i]--;
	for(int i = 0 ; i < n ; i ++)
		vec.pb(a[i]);
	solve(vec);
	cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
