//曇り空 のぞいた予感
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , q;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> q;
	while(q --){
		int x;
		cin >> n;
		bool ok = 0;
		while(n -- ){
			cin >> x;
			for(int i = 2 ; i * i <= x ; i ++){
				int cnt = 0;
				while(x % i == 0)x /= i , cnt ++;
				ok |= (cnt%2);
			}
			if(x > 1)ok = 1;
		}
		cout << ((ok) ? "YES" : "NO") << endl;
	}

	return(0);
}
