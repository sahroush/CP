//曇り空 のぞいた予感
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1<<18;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn] , p[maxn] , cnt[maxn];
ll sum , ans;

int getpar(int v){
	return ((p[v]) ? p[v] = getpar(p[v]) : v);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n , cnt[0]++;
	for(int i = 1 ; i <= n ; i ++)cin >> a[i] , sum += a[i] , cnt[a[i]]++;
	for(int i = (1 << 18)-1 ; i >= 0 ; i --){
		for(int j = i ; j ; j = (j - 1)&i){
			if(!cnt[getpar(i^j)] or !cnt[getpar(j)])continue;
			if(getpar(j) == getpar(i^j))continue;
			ans += 1ll * i * (cnt[getpar(j)] + cnt[getpar(j^i)] - 1);
			cnt[getpar(i^j)] = 0;
			cnt[getpar(j)] = 1;
			p[getpar(i^j)] = getpar(j);
		}
	}
	cout << ans - sum;
	return(0);
}
