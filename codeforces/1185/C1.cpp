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

int n , m;
int t[maxn];
int ans[maxn];

ll prt[maxn];

void solve(){
	for(int i = 1 ; i <= n ; i ++)
		prt[i] = prt[i - 1] + t[i];
	for(int i = 1 ; i <= n ; i ++){
		vector < int > st;
		st.clear();
		for(int j = 1 ; j < i ; j ++)
			st.pb(t[j]);
		sort(st.begin() , st.end());
		while(prt[i] > m)
			ans[i] ++ , prt[i] -= st.back() , st.pop_back();
	}
}

int32_t main(){
	migmig;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> t[i];

	solve();

	for(int i = 1 ; i <= n; i ++)
		cout << ans[i] << ' ';
	return(0);
}
