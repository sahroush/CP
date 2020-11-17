/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
int q;

deque < ll >  a;

int32_t main(){
    migmig;
	cin >> q;
	while (q -- ){
		cin >> n >> k;
		while(a.size())a.pop_front();
		for(int i = 0 ; i < n*k ; i ++){
			ll x;
			cin >> x;
			a.pb(x);
		}
		int sz = n*k;
		sort(a.begin() , a.end());
		ll ans = 0;
		if(n%2){
			for(int j = 0 ; j < k; j ++ ){
				for(int i = 0 ; i < n/2 ; i ++)
					a.pop_front();
				for(int i = 0; i < n/2   ;i ++)
					a.pop_back();
				ans += a.back();
				a.pop_back();
			}
		}
		else{
			for(int j = 0 ; j < k; j ++ ){
				for(int i = 0 ; i < n/2-1 ; i ++)
					a.pop_front();
				for(int i = 0; i < n/2  ;i ++)
					a.pop_back();
				ans += a.back();
				a.pop_back();
			}
		}
		cout << ans << endl;
	}
    return(0);
}
