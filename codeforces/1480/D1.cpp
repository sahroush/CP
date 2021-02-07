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
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int a[maxn];

vector < pii > vec;

#define ff first
#define ss second

int32_t main(){
    migmig;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	vec.pb({a[1] , 1});
	for(int i = 2 ; i <= n ; i ++){
		if(vec.back().ff != a[i])
			vec.pb({a[i] , 0});
		vec.back().ss ++;
	}
	int sz = vec.size();
	int a = -1 , b = -1;
	int ans = 0;
	for(int i = 0 ; i < sz ; i ++){
		if(vec[i].ss == 1){
			if(i + 1 == sz){
				ans++;
				if(vec[i].ff == a and vec[i].ff == b)ans --;
				continue;
			}
			if(a == vec[i + 1].ff and a != vec[i].ff){
				ans ++;
				a = vec[i].ff;
			}
			else if(b == vec[i + 1].ff and b != vec[i].ff){
				ans ++;
				b = vec[i].ff;
			}
			else if(a != vec[i].ff){
				ans++;
				a = vec[i].ff;
			}
			else if(b != vec[i].ff){
				ans++;
				b = vec[i].ff;
			}
			else{
				continue;
			}
		}
		else{
			ans += 2;
			if(a == vec[i].ff)ans--;
			if(b == vec[i].ff)ans--;
			a = b = vec[i].ff;
		}
	}
	cout << ans << endl;
    return(0);
}
