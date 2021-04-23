//曇り空 のぞいた予感
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1550;
const ll mod = 1e9+7;
const ll mod2 = 402653189;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k , ps[maxn] , h[maxn] , h2[maxn];
string s , t;
set < pii > ans;

pii get(int i , int j){
	int v1 = (h[j] + mod - (h[i-1] * pw(31 , j - i + 1))%mod)%mod;
	int v2 = (h2[j] + mod2 - (h2[i-1] * pw(87 , j - i + 1 , mod2))%mod2)%mod2;
	return pii(v1 , v2);
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> s >> t >> k;
	n = s.size();
	for(int i = 1 ; i <= n ; i ++)
		ps[i] = ps[i-1] + 1 - t[s[i-1]-'a'] + '0';
	for(int i = 1 ; i <= n ; i ++)
		h[i] = (h[i-1] * 31ll + s[i-1] - 'a' + 1)%mod,
		h2[i] = (h2[i-1] * 87ll + s[i-1] - 'a' + 1)%mod2;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i ; j <= n ; j ++)
			if(ps[j] - ps[i - 1] <= k)
				ans.insert(get(i , j));
	cout << ans.size();
	return(0);
}
