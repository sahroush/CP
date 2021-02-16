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
typedef pair<ll , ll> pii;

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
int n;
pii a[maxn];

bool chk(int x){
	ll sum = 0;
	for(int i = x ; i ; i --)
		sum += a[i].first;
	int i = x + 1;
	while(i <= n){
		if(sum >= a[i].first)sum += a[i].first;
		else
			return(0);
		i++;
	}
	return(1);
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i].first , a[i].second = i;
		}
		sort(a + 1 , a + n + 1);
		int l = 0 , r = n;//oops
		while(r - l > 1){
			int mid = (l + r) / 2;
			if(chk(mid))
				r = mid;
			else
				l = mid;
		}
		cout << n - r + 1 << endl;
		sort(a + r , a + n + 1 , [](pii a , pii b){return(a.second < b.second);});
		for(int i = r ; i <= n ; i ++)
			cout << a[i].second << ' ';
		cout << endl;
	}
	return(0);
}
