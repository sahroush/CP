//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3010;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , a[maxn];
ll ans;
priority_queue < int > pq;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n, pq.push(-1);
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , a[i] -= i , a[i] += n;
	for(int i = 1 ; i <= n ; pq.push(a[i]), i ++) if(a[i] < pq.top())
			ans += pq.top() , pq.pop() , pq.push(a[i]) , ans -= a[i];
	cout << ans;
	return(0);
}
