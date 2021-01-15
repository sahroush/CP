
#include <bits/stdc++.h>

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

const ll lg = 61;

ll n , q;
ll a[maxn];

ll cnt[lg + 5];
ll c[lg + 5][lg + 5];

bitset < maxn > h5[lg + 5];

bitset < 50000 + 100 > h4[lg + 5];

bitset < 5000 + 100 > h3[lg + 5];

bitset < 500 + 100 > h2[lg + 5];

bitset < 50 + 100 > h1[lg + 5];

void solve5(){
	for(int i = 0; i < lg ; i ++)h5[i] = 0;
		ll ans = 0;
		ms(c , 0);
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++){
			cin >> a[i];
			for(ll j = 0 ; j < lg ; j ++){
				if(a[i]&(1LL << j))
					h5[j][i] = 1;
			}
		}
		for(int i = 0 ; i < lg ; i ++)
			cnt[i] = h5[i].count();
		for(int i = 0 ; i < lg ; i ++)
			for(int j = 0 ; j < lg ; j ++)
				c[i][j] = (h5[i]&h5[j]).count();
		for(ll a = 0 ; a < lg ; a ++ ){
			if(!cnt[a])continue;
			for(ll b = 0 ; b < lg ; b ++){
				ll res = cnt[a];
				ll sm = (c[a][b] * (n))%mod;
				ll A = cnt[a] - c[a][b];
				ll B = cnt[b] - c[a][b];
				sm = (sm + ((A * B)%mod + (A * c[a][b])%mod)%mod)%mod;
				res = (res * sm)%mod;
				ll p = (((1LL << a)%mod) * ((1LL << b)%mod))%mod;
				ans = (ans + (p * res)%mod)%mod;
			}
		}
		cout << ans << endl;
}

void solve4(){
	for(int i = 0; i < lg ; i ++)h4[i] = 0;
		ll ans = 0;
		ms(c , 0);
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++){
			cin >> a[i];
			for(ll j = 0 ; j < lg ; j ++){
				if(a[i]&(1LL << j))
					h4[j][i] = 1;
			}
		}
		for(int i = 0 ; i < lg ; i ++)
			cnt[i] = h4[i].count();
		for(int i = 0 ; i < lg ; i ++)
			for(int j = 0 ; j < lg ; j ++)
				c[i][j] = (h4[i]&h4[j]).count();
		for(ll a = 0 ; a < lg ; a ++ ){
			if(!cnt[a])continue;
			for(ll b = 0 ; b < lg ; b ++){
				ll res = cnt[a];
				ll sm = (c[a][b] * (n))%mod;
				ll A = cnt[a] - c[a][b];
				ll B = cnt[b] - c[a][b];
				sm = (sm + ((A * B)%mod + (A * c[a][b])%mod)%mod)%mod;
				res = (res * sm)%mod;
				ll p = (((1LL << a)%mod) * ((1LL << b)%mod))%mod;
				ans = (ans + (p * res)%mod)%mod;
			}
		}
		cout << ans << endl;
}

void solve3(){
	for(int i = 0; i < lg ; i ++)h3[i] = 0;
		ll ans = 0;
		ms(c , 0);
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++){
			cin >> a[i];
			for(ll j = 0 ; j < lg ; j ++){
				if(a[i]&(1LL << j))
					h3[j][i] = 1;
			}
		}
		for(int i = 0 ; i < lg ; i ++)
			cnt[i] = h3[i].count();
		for(int i = 0 ; i < lg ; i ++)
			for(int j = 0 ; j < lg ; j ++)
				c[i][j] = (h3[i]&h3[j]).count();
		for(ll a = 0 ; a < lg ; a ++ ){
			if(!cnt[a])continue;
			for(ll b = 0 ; b < lg ; b ++){
				ll res = cnt[a];
				ll sm = (c[a][b] * (n))%mod;
				ll A = cnt[a] - c[a][b];
				ll B = cnt[b] - c[a][b];
				sm = (sm + ((A * B)%mod + (A * c[a][b])%mod)%mod)%mod;
				res = (res * sm)%mod;
				ll p = (((1LL << a)%mod) * ((1LL << b)%mod))%mod;
				ans = (ans + (p * res)%mod)%mod;
			}
		}
		cout << ans << endl;
}

void solve2(){
	for(int i = 0; i < lg ; i ++)h2[i] = 0;
		ll ans = 0;
		ms(c , 0);
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++){
			cin >> a[i];
			for(ll j = 0 ; j < lg ; j ++){
				if(a[i]&(1LL << j))
					h2[j][i] = 1;
			}
		}
		for(int i = 0 ; i < lg ; i ++)
			cnt[i] = h2[i].count();
		for(int i = 0 ; i < lg ; i ++)
			for(int j = 0 ; j < lg ; j ++)
				c[i][j] = (h2[i]&h2[j]).count();
		for(ll a = 0 ; a < lg ; a ++ ){
			if(!cnt[a])continue;
			for(ll b = 0 ; b < lg ; b ++){
				ll res = cnt[a];
				ll sm = (c[a][b] * (n))%mod;
				ll A = cnt[a] - c[a][b];
				ll B = cnt[b] - c[a][b];
				sm = (sm + ((A * B)%mod + (A * c[a][b])%mod)%mod)%mod;
				res = (res * sm)%mod;
				ll p = (((1LL << a)%mod) * ((1LL << b)%mod))%mod;
				ans = (ans + (p * res)%mod)%mod;
			}
		}
		cout << ans << endl;
}

void solve1(){
	for(int i = 0; i < lg ; i ++)h1[i] = 0;
		ll ans = 0;
		ms(c , 0);
		ms(cnt , 0);
		for(int i = 0 ; i < n ; i ++){
			cin >> a[i];
			for(ll j = 0 ; j < lg ; j ++){
				if(a[i]&(1LL << j))
					h1[j][i] = 1;
			}
		}
		for(int i = 0 ; i < lg ; i ++)
			cnt[i] = h1[i].count();
		for(int i = 0 ; i < lg ; i ++)
			for(int j = 0 ; j < lg ; j ++)
				c[i][j] = (h1[i]&h1[j]).count();
		for(ll a = 0 ; a < lg ; a ++ ){
			if(!cnt[a])continue;
			for(ll b = 0 ; b < lg ; b ++){
				ll res = cnt[a];
				ll sm = (c[a][b] * (n))%mod;
				ll A = cnt[a] - c[a][b];
				ll B = cnt[b] - c[a][b];
				sm = (sm + ((A * B)%mod + (A * c[a][b])%mod)%mod)%mod;
				res = (res * sm)%mod;
				ll p = (((1LL << a)%mod) * ((1LL << b)%mod))%mod;
				ans = (ans + (p * res)%mod)%mod;
			}
		}
		cout << ans << endl;
}



int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		if(n > 50000){
			solve5();
		}
		else if(n > 5000){
			solve4();
		}
		else if(n > 500){
			solve3();
		}
		else if(n > 50){
			solve2();
		}
		else{
			solve1();
		}
	}
    return(0);
}