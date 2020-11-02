/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int q;
ll a[maxn];
 
int32_t main(){
    migmig;
	cin >> q;
	while(q --){
		cin >> n;
		for(int i = 1;  i <= n ; i ++)
			cin >> a[i];
		ll sum = 0;
		for(int i = 2 ; i <= n ; i ++)
			sum += max(0LL , a[i] - a[i - 1]);
		ll x = 0 , y = a[1] , z = a[1] + sum , t = a[n] - a[1] - sum;
		// x ziad mishe , y kam mishe , z kam mishe , t ziad mishe;
		// max ziad shodan = min(y,z);
		ll mn = min(y , z);
		if(min(x , t) + mn < 0){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
    return(0);
}
