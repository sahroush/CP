//*
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n , k;
int a[maxn];

int b[maxn];

bool chk(int x){//ans >= x
	for(int i = 1 ; i <= n ; i ++)
		b[i] = ((a[i] >= x) ? 1 : -1) , b[i] += b[i - 1];
	int mn = 0;
	for(int i = k ; i <= n ; i ++)
		if(b[i] > mn)
			return(1);
		else
			mn = min(mn , b[i - k + 1]);
	return(0);
}

int32_t main(){
	migmig;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	int l = 1 , r = n + 1;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(chk(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	return(0);
}
