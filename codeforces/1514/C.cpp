//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 100;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > ans;
bool bad[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 2 ; i < maxn ; i ++)if(!bad[i])
		for(int j = i*2 ; j < maxn ; j += i)bad[j] = 1;
	
	if(n == 2){
		cout << 1 << endl;
		dokme(1);
	}
	if(!bad[n]){
		cout << n-2 << endl;
		for(int i = 1 ; i < n-1 ; i ++)cout << i << ' ';
		exit(0);
	}/*
	for(int i = 0 ; i < (1 << n) ; i ++){
		vector < int > cur;
		ll x = 1;
		cur.clear();
		for(int j = 0 ; j < n-1 ; j ++){
			if(i & (1 << j))cur.pb(j+1) , x = (x * (j + 1ll))%n;
		}
		if(x == 1 and cur.size() >= ans.size())ans = cur;
	}
	*/
	ans.pb(1);
	ll x = 1;
	for(int i = 2 ; i < n-1 ; i ++)if(__gcd(n , i) == 1)ans.pb(i), x = (x * i)%n;
	if(x != 1)ans.pb(n-1) , x = (x * (n - 1))%n;
	assert(x == 1);
	cout << ans.size() << endl;
	for(int  x : ans)cout << x << ' ';
	return(0);
}
