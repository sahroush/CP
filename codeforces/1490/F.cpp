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

int q , n;
int a[maxn];
int cnt[maxn];
int sz;

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		sz = 0;
		for(int i = 1 ; i <= n ; i ++)
			cnt[i] = 0;
		sort(a + 1 , a + n + 1);
		int cur = a[1];
		int sz = 1;
		for(int i = 1 ; i <= n ; i ++){
			if(a[i] == cur)cnt[sz]++;
			else cur = a[i] , sz ++ , cnt[sz] ++;
		}
		sort(cnt + 1 , cnt + sz + 1);
		int ans = n;
		int sml = n , gr = 0 , num = 0;
		for(int i = n ; i >= 0 ; i --){
			gr += num;
			while(sz and cnt[sz] == i)sml -= i , sz -- , num ++;
			ans = min(ans , gr + sml);
		}
		cout << ans << endl;
	}
	return(0);
}
