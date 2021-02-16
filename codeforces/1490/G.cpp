/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 100;
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
int a[maxn] , b;
ll mx[maxn];

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> m;
		ll sum = 0;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i] , sum += a[i] , mx[i] = sum;
		for(int i = 2 ; i <= n ; i ++)
			mx[i] = max(mx[i] , mx[i - 1]);
		while(m--){
			cin >> b;
			if(sum <= 0){
				int l = 0 , r = n;
				while(r - l > 1){
					int mid = (l + r) / 2;
					if(mx[mid] >= b)
						r = mid;
					else
						l = mid;
				}
				cout << ((mx[r] >= b) ? r - 1 : -1) << ' ';
				continue;
			}
			if(mx[n] >= b){
				int l = 0 , r = n;
				while(r - l > 1){
					int mid = (l + r) / 2;
					if(mx[mid] >= b)
						r = mid;
					else
						l = mid;
				}
				cout << ((mx[r] >= b) ? r - 1 : -1) << ' ';
				continue;
			}
			int res = ((b + sum - 1 - mx[n]) / sum);
			ll ans = res * n; 
			b -= res * sum;
			int l = 0 , r = n;
				while(r - l > 1){
					int mid = (l + r) / 2;
					if(mx[mid] >= b)
						r = mid;
					else
						l = mid;
				}
				cout << ans + r - 1 << ' ';
				continue;
		}
		cout << endl;
	}
	return(0);
}
