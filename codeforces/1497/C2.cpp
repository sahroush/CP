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

ll n , q , k;


int32_t main(){
	migmig;
	cin >> q;
	while(q --){
		cin >> n >> k;
		if(n - (k - 1) <= n/2){
			for(int i = 1 ; i < k ; i ++)
				cout << 1 << ' ';
			cout << n - (k - 1) << endl;
			continue;
		}
		if(n%k == 0){
			for(int i = 1 ; i <= k ; i ++)
				cout << n / k << ' ';
			cout << endl;
			continue;
		}
		for(int i = 1 ; i <= k - 3 ; i ++){
			n--;
			cout << 1 << ' ';
		}
		if(n % 3 == 0){
			cout << n/3 << ' ' << n/3 << ' ' << n/3 << endl;
			continue;
		}
		if(n % 2){
			cout << 1 << ' ' << (n - 1)/2 << ' ' << (n - 1)/2 << endl;
			continue;
		}
		if((n - 2)%4 == 0){
			cout << 2 << ' ' << (n - 2) / 2 << ' ' << (n - 2) / 2 << endl;
			continue;
		}		
		cout << n / 2 << ' ' << n/4 <<  ' ' << n/4 << endl;
	}
	return(0);
}

