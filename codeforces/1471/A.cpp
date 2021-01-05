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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , x;
ll q;
ll a[maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		ll sum = 0;
		ll m = 0;
		cin >> n >> x;
		for(int i = 0 ; i < n ; i ++)
			cin >> a[i] , sum += a[i] , m += (a[i] + x - 1)/x;
		cout << ll(sum + x - 1)/x << ' ' << m << endl;
		
	}




    return(0);
}
