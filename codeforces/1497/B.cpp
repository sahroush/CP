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
int n , m;
int cnt[maxn];

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> m;
		for(int i = 0 ; i < m ; i ++)cnt[i] = 0;
		for(int i = 0 ; i < n ;  i ++){
			int x;
			cin >> x;
			cnt[x % m] ++;
		}
		int ans = 0;
		for(int i = 0 ; i < m ; i ++)if(cnt[i]){
			if(i * 2 == m){
				ans++;
				continue;
			}
			if(i == 0){
				ans ++;
				continue;
			}
			if(cnt[i] >= cnt[m - i] and cnt[m - i]){
				ans++;
				while(cnt[m - i]){
					cnt[i] -- , cnt[m - i]--;
				}
				if(cnt[i])cnt[i] --;
				ans += cnt[i];
				continue;
			}
			else if(cnt[m - i]){
				ans++;
				while(cnt[i]){
					cnt[m - i]--;
					cnt[i] --;
				}
				cnt[m - i]--;
				ans += cnt[i];
				continue;
			}
			ans += cnt[i];
		}
		cout << ans << endl;
	}

	return(0);
}
