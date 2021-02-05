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

string s;
int n , a[maxn] , ans[maxn];

int32_t main(){
	migmig;
	cin >> s;
	n = s.size();
	for(int i = 1 ; i <= n ; i ++)
		a[i] = s[i - 1] - '0';
	int l = 1 , r = n;
	if(a[l] != a[r]){
		a[l] -- , a[l+1] += 10;
		if(a[l] == 0)l++;
	}
	for( ; l <= r ; l ++ ,  r --){
		if(a[l] != a[r]){
			if(a[l] - a[r] >= 10) a[r] += 10 , a[r - 1] --;
			if(a[l] - a[r] == 1) a[l] -- , a[l + 1] += 10;
		}
		if(a[l] != a[r])dokme(0);
		if(l != r)
			ans[l] = a[l] - a[r] / 2 , ans[r] = a[r] / 2;
		else{
			if(a[l] % 2)dokme(0);
			ans[l] = a[l] / 2;
		}
		if(ans[l] < 0 or ans[l] >= 10 or ans[r] < 0 or ans[r] >= 10)dokme(0);
	}
	for(l = r = 1 ; l <= n ; l ++){
		if(ans[l])r = 0;
		if(!r)cout << ans[l];
	}
	return(0);
}
