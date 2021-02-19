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

int srt[maxn];

ll fen[maxn];
ll cnt[maxn];

void add(int pos , int x , ll *fen){
	for( ; pos < maxn ; pos += pos & -pos)
		fen[pos] += x;
}

ll get(int pos , ll *fen){
	ll res = 0;
	for( ; pos ; pos -= pos & -pos)
		res += fen[pos];
	return(res);
}

int ord[maxn];

void solve(){
	for(int i = 1 ; i <= n ; i ++)
		srt[i] = i;
	sort(srt + 1 , srt + 1 + n , [](int a , int b){return(t[a] < t[b]);});
	for(int i = 1 ; i <= n ; i ++)ord[srt[i]] = i;
	for(int i = 1 ; i <= n ; i ++){
		ll m = ::m - t[i];
		int pos = 0;
		ll sum = 0;
		for(int i = 20 ; i >= 0 ; i --){
			if((pos ^ (1 << i)) > n)continue;
			if(sum + fen[pos ^ (1 << i)] <= m)pos ^= (1 << i) , sum += fen[pos];
		}
		ans[i] = i - 1 - get(pos , cnt);
		add(ord[i] , t[i] , fen);
		add(ord[i] , 1 , cnt);
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
