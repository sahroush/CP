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

const ll maxn  = 1e5 + 100;
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

int cnt[maxn];

vector < int > d[maxn];

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , cnt[a[i]] ++;
	for(int i = 1 ; i < maxn ; i ++){
		for(int j = i ; j < maxn ; j += i)
			d[j].pb(i);
		d[i].pb(maxn-1);
	}
	for(int i = 1 ; i < maxn ; i ++)cnt[i] += cnt[i - 1];
	ll ans = 0;
	for(int i = 1 ; i < maxn ; i ++){
		ll res = 1;
		if(cnt[i - 1] == cnt[maxn-1])continue;
		for(int j = 0 ; j < d[i].size() - 1 ; j ++){
			ll val = pw(j + 1 , cnt[d[i][j+ 1] - 1] - cnt[d[i][j] -1]);
			if(d[i][j] == i)
				val -= pw(j , cnt[d[i][j+ 1] - 1] - cnt[d[i][j] -1]);
			val +=10LL*mod;
			val%=mod;
			res*=val;
			res%=mod;
		}
		ans += res;
		ans%=mod;
	}
	cout << ans;
    return(0);
}