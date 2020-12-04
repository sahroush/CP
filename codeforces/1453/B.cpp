/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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

int q;
int n;
ll a[maxn];
ll x;

ll solve(int i){
	if(i == 1){
		return(x - abs(a[2] - a[1]));
	}
	if(i == n){
		return(x - abs(a[n] - a[n - 1]));
	}
	if(a[i] > a[i - 1] and a[i] > a[i + 1]){
		ll res = x - a[i] + a[i-1] - a[i] + a[i + 1] ;
		ll boz = max(a[i-1] ,a[i + 1]);
		res += boz - a[i - 1] + boz - a[i + 1];
		return(res);
	}
	if(a[i] < a[i - 1] and a[i] < a[i + 1]){
		ll res = x - a[i-1] + a[i] - a[i+1] + a[i] ;
		ll boz = min(a[i-1] ,a[i + 1]);
		res +=  a[i - 1]  - boz - boz + a[i + 1];
		return(res);
	}
	return(x);
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		x = 0;
		ll mn = 1e9;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
			mn = min(mn , a[i]);
		}
		for(int i = 1 ; i <= n ; i ++)a[i] += mn + 1;
		ll ans = 1e18;
		for(int i = 2 ; i <= n ; i ++)x += abs(a[i] - a[i - 1]);
		for(int i = 1 ; i <= n ; i ++)
			ans = min(ans , solve(i));
		cout << ans << endl;
	}
    return(0);
}
