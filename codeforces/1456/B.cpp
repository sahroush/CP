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

int n;
int a[maxn];

int chk(int l ,int r){
	int xr = 0;
	for(int i = l ; i <= r ; i ++)xr^=a[i];
	return(xr);
}

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	if(n == 2)dokme(-1);
	for(int i = 2 ; i < n ; i ++)
		if((a[i]^a[i-1]) > a[i + 1])dokme(1);
	for(int i = 2 ; i < n ; i ++)
		if((a[i] ^ a[i + 1]) < a[i - 1])dokme(1);
	int ans = 1e9;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = i ; j <= n ; j ++)
			for(int k = j + 1 ; k <= n ; k ++)
				for(int l = k ; l <= n ; l ++)
					if(chk(i , j) > chk(k , l))ans = min(ans , j - i + l - k);
	}
	if(ans == 1e9)dokme(-1);
	cout << ans;
    return(0);
}
