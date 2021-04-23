//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define sz(x) int(x.size())
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , t, a[maxn] , nxt[maxn][20] , q;
bool prime[maxn];
vector < int > d[maxn], pos[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> t;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , nxt[i][0] = n+1;
	for(int i = 2 ; i < maxn ; i ++)if(!prime[i])
		for(int j = i ; j < maxn ; j += i)prime[j] = 0 , d[j].pb(i);
	for(int i = 1 ; i <= n ; i ++)
		for(auto x : d[a[i]])pos[x].pb(i);
	for(int i = 2 ; i < maxn ; i ++)if(pos[i].size() > 1)
		for(int j = 0 ; j < sz(pos[i])-1 ; j ++)
			nxt[pos[i][j]][0] = min(nxt[pos[i][j]][0] , pos[i][j+1]);
	for(int i = n - 1 ; i >= 1 ; i --)
		nxt[i][0] = min(nxt[i][0] , nxt[i+1][0]);
	nxt[n+1][0] = n+1;
	for(int i = 1 ; i < 20 ; i ++)
		for(int j = 1 ; j <= n+1 ; j ++)
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
	while(t--){
		int l , r;
		cin >> l >> r;
		int ans = 1;
		for(int i = 17 ; i >= 0 ; i --){
			if(nxt[l][i] <= r)ans += (1 << i), l = nxt[l][i];
		}
		cout << ans << endl;
	}
	return(0);
}
