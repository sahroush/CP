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
ll n , k;
ll h[maxn];
ll l[maxn] , r[maxn];


int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++)
			cin >> h[i];
		r[1] = l[1] = h[1] + 1;
		r[n] = l[n] = h[n] + 1;
		for(int i = 2 ; i < n ; i ++)
			l[i] = h[i] + 1 , r[i] = h[i] + k;
		bool ok = 1;
		ll curl = l[1]-k+1 , curr = r[1] + k - 1;
		for(int i = 2 ; i <= n ; i ++){
			if(curl > r[i] or curr < l[i])ok = 0;
			l[i] = max(l[i] , curl);
			r[i] = min(r[i] , curr);
			curl = l[i] - k + 1 , curr = r[i] + k - 1;
		}
		cout << ((ok) ? "YES" : "NO") << endl;
	}



    return(0);
}
