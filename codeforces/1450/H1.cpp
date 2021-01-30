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

const int maxn = 2e5 + 100;
const ll mod = 998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct mint{
	ll x;
	mint(ll a):
		x(a % mod){}
	mint():
		x(0){}
	friend mint operator + (mint a , mint b){
		return(mint(a.x + b.x));
	}
	friend mint operator - (mint a , mint b){
		return(mint(a.x - b.x + mod * 10LL));
	}
	friend mint operator * (mint a , mint b){
		return(mint(a.x * b.x));
	}
	friend mint operator ^ (mint a , mint b){
		mint res(1);
		while(b.x){if(b.x&1)res=a*res;a=a*a;b.x>>=1;}return(res);
	}
	friend mint operator / (mint a , mint b){
		return(a * (b^mint(mod - 2)));
	}
};

mint fact[maxn];
mint n, m;
string s;

mint C(mint r , mint n){
	return((fact[n.x] / (fact[r.x] * fact[n.x - r.x])));
}

mint w , b , q;

int32_t main(){
	migmig;
	cin >> n.x >> m.x;
	cin >> s;
	fact[0] = mint(1);
	for(int i = 1 ; i < maxn ; i ++)
		fact[i] = mint(i) * fact[i - 1];
	for(int i = 0 ; i < n.x ; i ++)
		((s[i] == '?') ? q.x++ : (s[i] == 'w' and i%2) ? b.x++ : (s[i] == 'b' and i%2 == 0) ? b.x++ : w.x ++);
	mint ans , sum;
	for(int i = 0 ; i <= q.x ; i ++){
		int diff = abs(w.x + i - (b.x + q.x - i));
		if(diff % 4)continue;
		ans = ans + C(mint(i) , q) * mint(diff / 4);
		sum = sum + C(mint(i) , q);
	}
	ans=ans / sum;
	cout << ans.x;
	return(0);
}
