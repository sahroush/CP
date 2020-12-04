/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , q;
vector < int > ans;

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		//2^n - 2
		if(n%2){
			cout << -1 << endl;
			continue;
		}
		ans.clear();
		ans.pb(1);
		n-=2;
		ll z = 60;
		while(n){
			if((1LL << (z + 2)) - 2 <= n){
				for(int i = 0 ; i < z ; i ++)
					ans.pb(0);
				ans.pb(1);
				n-=(1LL << (z + 2)) - 2;
			} 
			else z--;
		}
		cout << ans.size() << endl;
		for(int i  : ans)
			cout << i << ' ';
		cout << endl;
	}




    return(0);
}
