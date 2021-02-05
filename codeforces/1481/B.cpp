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
typedef pair<int , int> pii;

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

int n , q , k , h[maxn];

bool chk(){
	for(int i = 1 ; i < n ; i ++)
		if(h[i] > h[i - 1])return(1);
	return(0);
}
int add(){
	for(int i = 1 ; i < n ; i ++)
		if(h[i] > h[i - 1])
			return(i);
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> k;
		for(int i = 0 ; i < n ; i ++)
			cin >> h[i];
		int ans = -1;
		while(chk() and k){
			ans = add();
			h[ans-1]++;
			k--;
		}
		if(k and !chk())ans = -1;
		cout << ans << endl;
	}
	return(0);
}
