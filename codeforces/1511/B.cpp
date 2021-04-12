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

int q;
ll a , b , c;

int cnt(ll x){
	int ans = 0;
	while(x)x/=10 , ans++;
	return ans;
}

void check(ll x , ll y){
	assert(cnt(x) == a and cnt(y) == b and cnt(__gcd(x , y)) == c);
}

int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> a >> b >> c;
		ll A = pw(10 , a-1);
		ll B = pw(10 , b-1);
		ll x = b;
		while(x > c){
			B/=10;
			x--;
		}
		while(cnt(B) != b)B *= 3;
		//check(A , B);
		cout << A << ' ' << B << endl;
	}
	return(0);
}
