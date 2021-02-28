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

const int maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
ll s[maxn];
ll ans = 0;
ll cnt[maxn];

void apply(int pos){
	if(pos == n){
		s[pos] -= cnt[pos];
		s[pos] = max(s[pos] , 1LL);
		return;
	}
	if(s[pos] - cnt[pos] > n - pos){
		s[pos] -= cnt[pos];
		return;
	}
	if(s[pos] > n - pos){
		ll diff = s[pos] - (n - pos + 1);
		diff = min(diff , cnt[pos]);
		cnt[pos] -= diff;
		s[pos] -= diff;
	}
	for( ; cnt[pos] and s[pos] > 1 ; s[pos]-- , cnt[pos] --)
		cnt[pos + s[pos]]++;
	for( ; cnt[pos] ; cnt[pos] --)
		cnt[pos + 1]++;
}

void jmp(int pos){
	apply(pos);
	if(pos == n){
		ans += s[pos] - 1;
		return;
	}
	ll bz = n - pos;
	if(s[pos] > bz){
		ans += s[pos] - bz;
		s[pos] = bz;
	}
	for( ; s[pos] > 1 ; s[pos]--)
		cnt[pos + s[pos]]++ , ans++;
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> s[i] , cnt[i] = 0;
		ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			jmp(i);
		}
		cout << ans << endl;
	}
	return(0);
}
