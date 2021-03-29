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

int q;
int n , w;
int a[maxn];
int cnt[maxn];

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> w;
		for(int i = 1 ; i <= n ; i ++)cin >> a[i] , cnt[int(log2(a[i]))]++;
		int ans = 1;
		int cur = 0;
		while(n--){
			bool ok = 0;
			for(int i = 20 ; i >= 0 ; i --)if(cnt[i]){
				if((1 << i) + cur <= w){
					cnt[i] --;
					ok = 1;
					cur += (1 << i);
					break;
				}
			}
			if(!ok){
				ans ++;
				cur = 0;
				for(int i = 20 ; i >= 0 ; i --)if(cnt[i]){
				if((1 << i) + cur <= w){
					cnt[i] --;
					ok = 1;
					cur += (1 << i);
					break;
				}
			}
			}
			
		}
		cout << ans << endl;
		for(int i = 1 ; i <= n ; i ++)cnt[int(log2(a[i]))]--;
	}

	return(0);
}
