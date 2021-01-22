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

int q;
int n , k , m;
int a[maxn];
int b[maxn];

int32_t main(){
    migmig;
	cin >> q;
	while(q --){
		cin >> n >> k >> m;
		for(int i = 1 ; i <= n ; i ++)a[i] = 1;
		for(int i = 1 ; i <= m ; i ++)
			cin >> b[i] , a[b[i]] = 0;
		if(n%(k - 1) != m%(k - 1)){
			cout << "NO" << endl;
			continue;
		}
		int sz = k / 2;
		for(int i = 1 ; i <= n ; i ++)a[i] = a[i - 1] + a[i];
		bool ok = 0;
		for(int i = 1 ; i <= m ; i ++)
			if(a[b[i]] >= sz and a[n] - a[b[i]] >= sz)
				ok = 1;
		cout << ((ok) ? "YES":"NO") << endl;
	}
    return(0);
}
